//Detector de matrículas 2012/2013 - Antonio Diego Barquero Cuadrado - 76043791H - Lab L1

#include "imageprocess.h"

void imageprocess::copiar(uchar * imgO, uchar * imgD, int tam)
{
	asm volatile
	(
			"movl %0, %%esi \n\t"
			"movl %1, %%edi \n\t"
			"movl %2, %%ecx\n\t"
			"rep movsb \n\t"
			:
			: "m" (imgO),	"m" (imgD), "m"(tam)
			: "%ecx", "%esi", "%edi", "memory"
	);

	qDebug("COPIAR IMAGEN --> Realizado");
}

void imageprocess::borrar(uchar * imgD, int x, int y)
{
	asm volatile
	(
			"mov %0, %%edi\n\t"						//Carga la imagen
			"mov %1, %%ecx\n\t"						//Carga X
			"imull %2, %%ecx\n\t"
			"xor %%eax, %%eax\n\t"					//Guarda 0 en cada posición de
			"rep stosb\n\t"							//la imagen
			:
			: "m" (imgD), "m" (x), "m" (y)
			: "%eax", "%ecx","%edi", "memory"
	);

	qDebug("BORRAR IMAGEN --> Realizado, %d x %d",x,y);
}

void imageprocess::umbralizar(uchar * imgD, int x, int y)
{
	asm volatile
	(
			"mov %0, %%esi\n\t"						//Imagen
			"mov %1, %%ecx\n\t"						//X de la imagen

			"imull %2,%%ecx\n\t"

			"umbraliza: \n\t"
				"mov (%%esi), %%eax\n\t"			//Carga cada punto de la imagen
				"subb $128, %%al\n\t"				//y realiza la resta 255 - origen
				"cmpb $0, %%al\n\t"					//guardando el resultado en la
				"jl menor\n\t"						//imagen destino
				"movb $255, (%%esi)\n\t"			//
				"jmp sigue\n\t"						//
					"menor:\n\t"					//
						"movb $0, (%%esi)\n\t"		//

					"sigue:\n\t"
						"incl %%esi\n\t"
			"loopl umbraliza\n\t"
			:
			: "m" (imgD), "m" (x), "m" (y)
			: "%eax","%ecx","%esi", "memory"
	);

	qDebug("UMBRALIZAR IMAGEN --> Realizado, punto medio 128");
}

void imageprocess::negar(uchar * imgO, uchar * imgD, int x, int y)
{
	asm volatile
	(
			"mov %0, %%esi\n\t"						//Imagen origen
			"mov %1, %%edi\n\t"						//Imagen destino
			"mov %2, %%ecx\n\t"						//X de las imágenes

			"imull %3,%%ecx\n\t"

			"niega: \n\t"
				"movb $255, %%al\n\t"				//Recorre la imagen origen y
				"subb (%%esi), %%al\n\t"			//resta 255 a cada punto, guardando
				"movb  %%al, (%%edi)\n\t"			//el resultado en la imagen destino
				"incl %%esi\n\t"					//
				"incl %%edi\n\t"					//
			"loop niega\n\t"
			:
			: "m"(imgO), "m"(imgD), "m"(x), "m"(y)
			: "%eax", "%ecx","%esi","%edi" ,"memory"
	);

	qDebug("INVERTIR IMAGEN --> Realizado");
}

void imageprocess::detectarV(uchar *imgD, int *Fmin, int *Fmax, int U)
{
	int min = 0;
	int max = 0;

	//Esta parte calcula el límite superior de los caracteres de la imagen
	asm volatile
	(
			"mov %0, %%esi\n\t"					//Imagen
			"mov $0, %%ebx\n\t"					//Contador

			"verticeMin: \n\t"

				"cmp $50, %%ebx\n\t"
			    "je finMin\n\t"

				"mov $320, %%ecx\n\t"
				"mov $0, %%eax\n\t"
				"sumaMin:"						//Recorre la imagen por filas
					"addb (%%esi), %%al\n\t"	//y realiza la suma de cada
					"inc %%esi\n\t"				//pixel
				"loop sumaMin\n\t"

			"cmp %2, %%eax\n\t"					//Compara con el valor umbral y lo guarda en
			"jg finMin\n\t"						//caso de superarlo
			"inc %%ebx\n\t"						//
			"jmp verticeMin\n\t"

			"finMin:\n\t"
				"movl %%ebx, %1\n\t"
			:
			: "m"(imgD),"m"(min),"m"(U)
			: "%eax","%ebx","%ecx","%edx","%esi","memory"

	);

	//Esta parte calcula el límite inferior de los caracteres de la imagen
	asm volatile
	(
			"mov %0, %%esi\n\t"					//Imagen
			"mov $100, %%ebx\n\t"				//Límite inferior

			"addl $31680, %%esi\n\t"			//Se sitúa en la última fila (320*99)

			"verticeMax: \n\t"
				"cmp $50, %%ebx\n\t"			//Compara con mitad de la imagen
				"je finMax\n\t"

				"mov $320, %%ecx\n\t"
				"mov $0, %%eax\n\t"
				"sumaMax: \n\t"					//Recorre la imagen por filas
					"addb (%%esi), %%al\n\t"	//y realiza la suma de cada
					"inc %%esi\n\t"				//pixel
				"loopl sumaMax\n\t"

			"cmp %2, %%eax\n\t"
			"jg finMax\n\t"
			"dec %%ebx\n\t"						//Decrementa contador
			"sub $640, %%esi\n\t"				//Carga la fila anterior de la imagen
			"jmp verticeMax\n\t"

			"finMax: \n\t"
				"mov %%ebx, %1\n\t"
			:
			: "m"(imgD), "m"(max),"m"(U)
			: "%eax", "%ebx", "%ecx", "%edx", "%esi","memory"
	);

	*Fmin = min;
	*Fmax = max;

	qDebug("MARGEN VERTICAL --> MINIMO: %d, MAXIMO: %d \n",*Fmin,*Fmax);
}

void imageprocess::detectarH(uchar *imgD, int *Vh, uchar U)
{
	uchar V[320];

	//Esta parte recorre la imagen por columnas y compara con el umbral llenando el vector V
	//con 1 y 0 donde corresponde
	asm volatile
	(
			"mov %1, %%esi\n\t"							//Imagen
			"xor %%eax, %%eax\n\t"						//Iterador
			"xor %%edx, %%edx\n\t"						//Suma de puntos
			"xor %%ebx, %%ebx\n\t"						//Punto de la imagen

			"detectaH:\n\t"
				"cmp $320, %%eax\n\t"
				"je finDetectaH\n\t"

				"mov $100, %%ecx\n\t"
				"xor %%dl, %%dl\n\t"
					"sumaCol:\n\t"						//Recorre la imagen por columnas y
						"movb (%%esi), %%bl\n\t"		//compara cada punto cargado con el
						"cmpb $255, %%bl\n\t"			//blanco, si es igual incrementa el
						"jb noSuma\n\t"					//contador
						"addb $1, %%dl\n\t"				//
							"noSuma:\n\t"				//
								"add $320, %%esi\n\t"	//
					"loopl sumaCol\n\t"

				"cmpb %2, %%dl\n\t"						//Si supera el umbral guarda 1 en Vh
				"jg esMayorUmbral\n\t"					//si no guarda 0 en Vh
				"movb $0, (%0,%%eax)\n\t"
				"jmp itera\n\t"
					"esMayorUmbral:\n\t"
						"movb $1, (%0,%%eax)\n\t "

					"itera:\n\t"
						"inc %%eax\n\t"					//Incrementa iterador
						"mov %1, %%esi\n\t"				//Vuelve al inicio de la imagen
						"add %%eax, %%esi\n\t"			//Posición en siguiente columna
						"jmp detectaH\n\t"

			"finDetectaH:\n\t"
			:
			: "r" (V), "m" (imgD), "m" (U)
			: "%eax", "%edx", "%ecx", "%ebx", "%esi", "memory"

	);

	//Esta parte calcula el punto medio y lo guarda en la posición de Vh correspondiente
	asm volatile
	(
			"xor %%eax, %%eax\n\t" 						//Indice de V
			"xor %%ecx, %%ecx\n\t" 						//Contador de 1's
			"xor %%edx, %%edx\n\t" 						//Almacena los valores de V
			"xor %%ebx, %%ebx\n\t" 						//Indice de Vh


			"puntoMedio:\n\t"
				"cmp $320, %%eax\n\t"
				"je finPuntoMedio\n\t"

				"movb (%0,%%eax), %%dl\n\t"				//
				"cmpb $1, %%dl\n\t"						//Recorre el vector V y va
				"je incrementaCont\n\t"					//contando los 1's
				"cmp $3, %%ecx\n\t"						//
				"jg guardaVh\n\t"
				"jmp siguientePos\n\t"


				"guardaVh:\n\t"
					"pushl %%eax\n\t"					//Guarda valor del indice de V

			 	 	"sarl $1, %%ecx \n\t"				//Se sitúa en el punto
			        "subl %%ecx, %%eax \n\t"			//medio del vector y guarda el valor medio
					"movl %%eax, (%1,%%ebx,4)\n\t"		//en la posicón actual de Vh

					"inc %%ebx\n\t"

					"xor %%ecx, %%ecx\n\t"
					"popl %%eax\n\t"					//Recupera valor del indice de V
					"jmp siguientePos\n\t"

				"incrementaCont:\n\t"
					"inc %%ecx\n\t"

				"siguientePos:\n\t"
					"inc %%eax\n\t"
					"jmp puntoMedio\n\t"
			"finPuntoMedio:\n\t"
			:
			: "S" (V), "D" (Vh)
			: "%eax","%ebx","%ecx","%edx","memory"
	);

for (int i=0; i<7;i++) qDebug("%d: %d",i,Vh[i]);
}

void imageprocess::recortar(uchar *imgO, uchar *imgD,int x, int y, int W, int H)
{
	asm volatile
	(
			"mov %0, %%esi\n\t"
			"mov %1, %%edi\n\t"

			"mov $320, %%eax\n\t"					//Se situa en la posición inicial en la
			"imull %3, %%eax\n\t"					//imagen, esto se calcula de la siguiente manera
			"add %2, %%eax\n\t"						//y*320 + x. Después se sitúa en el punto de la
			"add %%eax, %%esi\n\t"					//imagen

			"mov $0, %%ebx\n\t"

			"recorta: \n\t"
				"cmp %5, %%ebx\n\t"					//El bucle se repetirá H veces
				"je finRecorta\n\t"
					"mov $0, %%eax\n\t"
					"mov %4, %%ecx\n\t"				//El bucle se repetirá W veces
					"muevePixel:\n\t"
						"movb (%%esi), %%al\n\t"	//
						"movb %%al, (%%edi)\n\t"	//Guarda los puntos de la imagen origen
						"inc %%esi\n\t"				//en la imagen destino
						"inc %%edi\n\t"				//
					"loopl muevePixel\n\t"

					"add $320, %%esi\n\t"			//Se sitúa en el siguiente punto
					"sub %4, %%esi\n\t"				//de la imagen origen (320-W)

					"inc %%ebx\n\t"
					"jmp recorta\n\t"

			"finRecorta:\n\t"
			:
			: "m" (imgO), "m" (imgD), "m" (x), "m" (y), "m" (W), "m" (H)
			: "%eax", "%ebx", "%ecx","%edx" ,"%esi", "%edi", "memory"
	);

	qDebug("RECORTAR IMAGEN: X:%d y:%d, %dX%d",x,y,W,H);
}

int imageprocess::matching(uchar *imgO, void *pattern, int ini, int tam)
{
	int val = 0;
	int match = 0;
	int suma = 0;	//contador de píxeles iguales


//	Este método realiza el algoritmo de matching propuesto con una pequeña modificación. Consiste en
//	lo siguiente:
//		Carga la imagen de origen
//		Carga la imagen que corresponde en el vector de imágenes
//		Recorre la imagen de origen y la del vector píxel a píxel y compara ambos 1 a 1
//			- Si los píxeles son iguales: suma 3 al contador.
//			- Si los píxeles no son iguales: resta 1 al contador
//
//	En general funciona bastante bien salvo excepciones, tiene algunos problemas para distinguir el
//	0 del 6, 8 o 9 en algunas imágenes con píxeles blancos dispersos sobre el fondo negro y a veces
//  confunde la F con la P.


	asm volatile
		(
				"mov %3, %%ebx\n\t"							//Inicio de los caracteres
				"mov %4, %%ecx\n\t"							//Fin de los caracteres

				"comparaLetras:\n\t"
					"mov %1, %%esi\n\t"						//Carga imagen origen
					"movl (%2,%%ebx,4), %%edx\n\t"			//Carga imagen del vector

					"pushl %%ecx\n\t"						//Guarda contador comparaLetras
					"mov $1760, %%ecx\n\t"
					"pushl %%ebx\n\t"						//Guarda índice de caracteres
					"movl $0, %6\n\t"
					"comparaPixel:\n\t"
						"xor %%eax, %%eax\n\t"
						"xor %%ebx, %%ebx\n\t"
						"movb (%%esi), %%al\n\t"			//Compara los 2 píxeles de las
						"movb (%%edx), %%bl\n\t"			//imágenes. si coinciden aumenta
						"cmpb %%al, %%bl\n\t"				//el contador, si no lo decrementa
						"je iguales\n\t"					//

						"addb %%al, %%bl\n\t"				//
						"cmp $250, %%bl\n\t"				//
						"je suma250\n\t"					//Si los dos píxeles no son iguales
						"cmp $0, %%bl\n\t"					//realiza la suma de ambos, según su resultado
						"je suma0\n\t"						//		-250: resta 1 al contador
						"subl $1, %6\n\t"					//		-0: suma 1 al contador
						"jmp siguientePixel\n\t"			//

						"iguales:\n\t"						//
							"addl $3, %6\n\t"				//suma = suma + 3
							"jmp siguientePixel\n\t"		//

						"suma250:\n\t"						//
							"subl $1, %6\n\t"				//suma = suma - 1
							"jmp siguientePixel\n\t"		//

						"suma0:"							//
							"addl $1, %6\n\t"				//suma = suma + 1
															//
						"siguientePixel:\n\t"
							"inc %%esi\n\t"
							"inc %%edx\n\t"
					"loopl comparaPixel\n\t"

						"xor %%eax, %%eax\n\t"
						"mov %6, %%eax\n\t"					//Se guarda la suma del match
						"popl %%ebx\n\t"					//Recupera el indice de caracteres

						"cmpl %5, %%eax\n\t"				//Compara con el anterior
						"jg guardaMatch\n\t"
						"jmp siguienteLetra\n\t"

							"guardaMatch:\n\t"
								"movl %%eax, %5\n\t"		//Si supera al match anterior se guarda
								"movl %%ebx, %0\n\t"		//Se guarda el nuevo carácter más parecido

						"siguienteLetra:\n\t"
						"popl %%ecx\n\t"					//Recupera contador comparaLetras
						"inc %%ebx\n\t"
				"loopl comparaLetras\n\t"
				:
				: "m"(val),"m" (imgO), "D" (pattern), "m" (ini), "m" (tam), "m" (match), "m" (suma)
				: "%eax","%ebx", "%ecx", "%edx","%esi", "memory"
		);

	qDebug("MATCHING IMAGEN: val:%d, match:%d, ini:%d, tam:%d",val,match,ini,tam);

	return val;
}
