/*
 * functions.h
 *
 *  Created on: 13.11.2014 г.
 *      Author: trifon
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// функция, която намира лице на триъгълник
// по зададени три върха с 2D координати
double triarea(double, double, double, double,
				double, double);

// функция, която намира разстояние между две точки
// зададени с 2D координати
double distance(double x1, double y1, double x2, double y2);

// функция, която пресмята лицето на триъгълник
// зададен с дължините на трите си страни
double heron(double, double, double);

// функция, която намира квадрата на параметъра си
double square(double);


#endif /* FUNCTIONS_H_ */
