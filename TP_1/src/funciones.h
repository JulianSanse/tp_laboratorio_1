/*
 * funciones.h
 *
 *  Created on: Apr 12, 2022
 *      Author: Juli
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


/**
 * Esta funcion muestra el menu y devuelve la opcion elegida
 *  @param km kilometros ingresados
 *  @param precioAerlonieas precio de la aerolineas
 *  @param precioLatam precio de la aerolinea latam
 *
 *
 *  @return el numero ingresado.
 */
int mostrarMenu(float km, float precioAerolineas, float precioLatam);
/**
 * Esta funcion recibe un precio y calcula el 10% de descuento
 * @param precio precio de aerolineas o latam
 *
 *  @return el precio con 10% de descuento.
 */
float calcularDebito(float precio);
/**
 * Esta funcion recibe un precio y calcula el 25% de interes
 *   @param precio precio de aerolineas o latam
 *
 *  @return el precio con 25% de interes
 */
float calcularCredito(float precio);
/**
 * Esta funcion recibe un precio y calcula su valor en BTC
 * @param precio precio de aerolineas o latam
 *
 *  @return valor en BTC.
 */
float calcularBitcoin(float precio);
/**
 * Esta funcion recibe un precio y los kilometros
 *  @param precio precio de aerolineas o latam
 *	@param kilometros kilometros ingresados
 *	*  @return valor en BTC.
 */
float calcularPrecioKilometro(float precio, float kilometros);
/**
 * Esta funcion calcula la diferencia entre los dos precios
 *  @param precioLatam precio de la aerolinea latam
 *  @param precioAerlonieas precio de la aerolineas
 *	Ademas hace un if para determinar cual es el valor mas alto, para restarlo con el mas bajo, asi no da un numero negativo.
 *  @return la diferencia entre los valores.
 */
float calcularDiferencia(float precioLatam, float precioAerolineas);
/**
 * Esta funcion recibe todos los valores ya calculados para cada aerolinea y los muestra en pantalla
 *  @param precioDebitoLatam precio de la aerolinea latam en debito
 *  @param precioCreditoLatam precio de la aerolinea latam en credito
 *  @param precioBtcLatam precio de la aerolinea latam BTC
 *  @param precioPorKmLatam precio de los km unitarios de latam
 *  @param precioDebitoAerolineas precio de la aerolineas argentina en debito
 *  @param precioCreditoAerolineas precio de la aerolineas argentina en credito
 *  @param precioBtcAerolineas precio de la aerolineas argentina BTC
 *  @param precioPorKmAerolineas precio de los km unitarios de aerolineas argentina
 *
 *	@param diferencia diferencia entre valores.
 *
 *
 */
void mostrarResultados( float precioDebitoLatam,float precioCreditoLatam, float precioBtcLatam, float precioPorKmLatam, float precioDebitoAerolineas, float precioCreditoAerolineas, float precioBtcAerolineas, float precioPorKmAerolineas,float diferencia);

#endif /* FUNCIONES_H_ */
