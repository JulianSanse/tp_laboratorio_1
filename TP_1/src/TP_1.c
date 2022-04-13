/*
 ============================================================================
 Name        : TP_1.c
 Author      : Julian San Sebastian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;
	float kilometrosIngresados = 0.00;
	float precioAerolineas = 0.00;
	float precioLatam = 0.00;
	float precioDebitoLatam;
	float precioDebitoAerolineas;
	float precioCreditoLatam;
	float precioCreditoAerolineas;
	float precioBtcLatam;
	float precioBtcAerolineas;
	float precioPorKmLatam;
	float precioPorKmAerolineas;
	float diferencia;
	int opcionDosCompletada = 0;
	int opcionUnoCompletada = 0;

	float calcularDiferencia(float precioLatam, float precioAerolineas);

	opcionElegida = mostrarMenu(kilometrosIngresados, kilometrosIngresados, precioLatam);

	while(opcionElegida != 6){
		switch(opcionElegida){
			case 1:
				printf("Ingrese los kilometros: ");
				scanf("%f", &kilometrosIngresados);
				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas , precioLatam);
				opcionUnoCompletada = 1;
				break;
			case 2:
				printf("Precio vuelo Aerolineas: ");
				scanf("%f", &precioAerolineas);
				printf("Precio vuelo Latam: ");
				scanf("%f", &precioLatam);
				opcionDosCompletada = 1;
				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
				break;
			case 3:
				if(opcionDosCompletada == 0 || opcionUnoCompletada == 0){
					printf("fdsafsaasfd");
					break;
				}

				precioDebitoLatam = calcularDebito(precioLatam);
				precioDebitoAerolineas = calcularDebito(precioAerolineas);
				precioCreditoLatam = calcularCredito(precioLatam);
				precioCreditoAerolineas = calcularCredito(precioAerolineas);
				precioBtcLatam= calcularBitcoin(precioLatam);
				precioBtcAerolineas= calcularBitcoin(precioAerolineas);
				precioPorKmLatam= calcularPrecioKilometro(precioLatam, kilometrosIngresados);
				precioPorKmAerolineas= calcularPrecioKilometro(precioAerolineas, kilometrosIngresados);
				diferencia= calcularDiferencia(precioLatam, precioAerolineas);

				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
				break;
			case 4:
				printf("Latam:"
						"a) Precio con tarjeta de debito: %f \n"
						"b) Precio con tarjeta de credito: %f \n"
						"c) Precio con bitcoin: %f \n"
						"d) Diferencia de precios: %f \n", precioDebitoLatam, precioCreditoLatam, precioBtcLatam, diferencia);
			default:
				printf("\n Ingrese una opcion valida!! \n");
				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
			}
	}


	return EXIT_SUCCESS;

}
/**
 * Esta funcion calcula la diferencia entre los dos precios
 *  @param precioLatam precio de la aerolinea latam
 *  @param precioAerlonieas precio de la aerolineas
 *
 *  @return la diferencia entre los valores.
 */
float calcularDiferencia(float precioLatam, float precioAerolineas){
	float diferencia;

	if(precioLatam > precioAerolineas){
		diferencia= precioLatam - precioAerolineas;
		return diferencia;
	}else{
		diferencia= precioAerolineas - precioLatam;
		return diferencia;
	}

	return diferencia;
}








