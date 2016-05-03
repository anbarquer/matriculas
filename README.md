<p>Realizado mediante ensamblador IA32 embebido en el fichero <em>imageprocess.cpp</em> y utilizando QtCreator</p>
<p>Este programa es capaz de reconocer los caracteres que componen las matrículas que se encuentran en el directorio <em>/bin/imagesaoc</em></p>
<p>La solución se acomete realizando varios pasos:</p>
<ol>
<li>Convierte la imagen de la matrícula a su negativo</li>
<li>Umbraliza los valores de esta para obtener una imagen más definida (elimina difuminados)</li>
<li>Analiza la imagen y recorta los caracteres que lo componen</li>
<li>Mediante un algoritmo de <em>matching</em> realiza comparaciones píxel a píxel con las imágenes que se encuentran en el directorio <em>bin/letras</em> y retorna el resultado más acertado</li>
</ol>
![alt tag](https://raw.githubusercontent.com/anbarquer/matriculas/master/screen/matricula.png)

