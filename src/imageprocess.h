/***************************************************************************
 *   Copyright (C) 2012 Paco Andrés   *
 *   pacoan@unex.es   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QtCore>

namespace imageprocess{
	extern void copiar(uchar * imgO, uchar * imgD, int tam);
	extern void borrar(uchar * imgD, int x, int y);
	extern void negar(uchar * imgO, uchar * imgD, int x, int y);
	extern void umbralizar(uchar *imgD, int x, int y);
	extern void detectarV(uchar *imgD, int  *Fmin, int  *Fmax, int U);
	extern void detectarH(uchar *imgD, int *Vh, uchar U);
	extern void recortar(uchar *imgO, uchar *imgD,int x, int y, int W, int H);
	extern int matching(uchar *digit, void *pattern, int ini, int tam);
}

#endif
