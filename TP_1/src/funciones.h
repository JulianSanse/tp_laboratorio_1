/*
 * funciones.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Juli
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int mostrarMenu(float km, float precioAerolineas, float precioLatam);
float calcularDebito(float precio);
float calcularCredito(float precio);
float calcularBitcoin(float precio);
float calcularPrecioKilometro(float precio, float kilometros);
float calcularDiferencia(float precioLatam, float precioAerolineas);
void mostrarResultados( float precioDebitoLatam,float precioCreditoLatam, float precioBtcLatam, float precioPorKmLatam, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBtcAerolineas, float precioPorKmAerolineas,float diferencia);

#endif /* FUNCIONES_H_ */
