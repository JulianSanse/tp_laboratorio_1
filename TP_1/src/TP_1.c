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
	int opcionTresCompletada = 0;

	opcionElegida = mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);

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
					printf("\n Debes completar los kilometros y los precios primero! \n");
					opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
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

				printf("\n Se han calculado todos los costos! \n");
				opcionTresCompletada= 1;
				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
				break;
			case 4:
				if( opcionTresCompletada ==  0){
					printf("\n Debes calcular los costos primero! \n");
					opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
					break;
				}
				mostrarResultados(precioDebitoLatam, precioCreditoLatam, precioBtcLatam, precioPorKmLatam, precioDebitoAerolineas, precioCreditoAerolineas, precioBtcAerolineas, precioPorKmAerolineas, diferencia);
				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
				break;
			case 5:
				kilometrosIngresados= 7090;
				precioAerolineas= 162965;
				precioLatam= 159339;

				precioDebitoLatam = calcularDebito(precioLatam);
				precioDebitoAerolineas = calcularDebito(precioAerolineas);
				precioCreditoLatam = calcularCredito(precioLatam);
				precioCreditoAerolineas = calcularCredito(precioAerolineas);
				precioBtcLatam= calcularBitcoin(precioLatam);
				precioBtcAerolineas= calcularBitcoin(precioAerolineas);
				precioPorKmLatam= calcularPrecioKilometro(precioLatam, kilometrosIngresados);
				precioPorKmAerolineas= calcularPrecioKilometro(precioAerolineas, kilometrosIngresados);
			    diferencia= calcularDiferencia(precioLatam, precioAerolineas);

				mostrarResultados(precioDebitoLatam, precioCreditoLatam, precioBtcLatam, precioPorKmLatam, precioDebitoAerolineas, precioCreditoAerolineas, precioBtcAerolineas, precioPorKmAerolineas, diferencia);

				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
				break;
			default:
				printf("\n Ingrese una opcion valida!! \n");
				opcionElegida =mostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
			}
	}

	if(opcionElegida == 6){
		printf("Saliendo...");
	}

	return EXIT_SUCCESS;

}










