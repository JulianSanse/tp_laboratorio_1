/*
 * funciones.c
 *
 *  Created on: Apr 12, 2022
 *      Author: Juli
 */

#include <stdio.h>
#include <stdlib.h>

int mostrarMenu(float km, float precioAerolineas, float precioLatam){
	setbuf(stdout, NULL);
	int opcionElegida;

	printf( "\n1. Ingresar Kilometros: (km= %.2f)\n"
				"2. Ingresar Precio de Vuelos (Aerolineas= %f, Latam = %f)\n"
				"3. Calcular todos los costos\n"
				"4. Informar Resultados\n"
				"5. Carga forzada de datos\n"
				"6. Salir\n", km, precioAerolineas, precioLatam);
	printf("Ingrese una opcion: ");
	scanf("%d", &opcionElegida);

	return opcionElegida;
}

float calcularDebito(float precio){
	float precioFinalDebito;

	precioFinalDebito = precio * 0.9;

	return precioFinalDebito;
}

float calcularCredito(float precio){
	float precioFinalCredito;

	precioFinalCredito = precio * 1.25;

	return precioFinalCredito;
}

float calcularBitcoin(float precio){
	float btc= 4606954.55;
	float precioBtc;

	precioBtc = precio / btc;

	return precioBtc;

}

float calcularPrecioKilometro(float precio, float kilometros){
	float precioPorKm;
	precioPorKm= precio/ kilometros;

	return precioPorKm;
}
