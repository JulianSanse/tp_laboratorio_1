/*
 ============================================================================
 Name        : TP_2.c
 Author      : Julian San Sebastian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//NO OLVIDARSE LA CARGA FORZADA!!!!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayPassenger.h"

int main(void) {
	setbuf(stdout, NULL);


	int opcionElegida;
	int opcionElegidaCaseDos;
	int elementos = 2000;
	int id = 0;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int indexPosicion;
	int statusFly;
	float total= 0;

	Passenger pasajeros[elementos];
	initPassengers(pasajeros, elementos);

	do{
		mostrarMenu(&opcionElegida);
		switch(opcionElegida){
			case 1:
			{
				id++;

				preguntarChar(name, "\n Ingrese el nombre del pasajero");

				preguntarChar(lastName, "\n Ingrese el apellido del pasajero");

				preguntarFloat(&price, "\n Ingrese el precio del vuelo");

				preguntarChar(flycode, "\n Ingrese el codigo del vuelo");

				preguntarInteger(&typePassenger, "\n Ingrese el tipo de pasajero 1.Para clase turista 2. Para clase ejecutiva 3. Para vip");

				preguntarInteger(&statusFly, "\n Ingrese el estado del vuelo 1. para activo 2. para inactivo");

				addPassanger(pasajeros, elementos, id, name, lastName, price, typePassenger, flycode, statusFly);

				break;
			}
			case 2:
				id = preguntarId("Cual es la id que quiere modificar?");
				indexPosicion= findPassengerById(pasajeros, elementos, id);

				if(indexPosicion== -1){
					printf("\n Id no encontrada!!\n");
				}else{
					do{
						mostrarMenuCaseDos(&opcionElegidaCaseDos);

						switch(opcionElegidaCaseDos){
							case 1:
								preguntarChar(pasajeros[indexPosicion].name, "\n Ingrese el nombre del pasajero");
								break;
							case 2:
								preguntarChar(pasajeros[indexPosicion].lastName, "\n Ingrese el nombre del pasajero");
								break;
							case 3:
								preguntarFloat(&pasajeros[indexPosicion].price, "\n Ingrese el precio del vuelo");
								break;
							case 4:
								preguntarChar(pasajeros[indexPosicion].flycode, "\n Ingrese el codigo del vuelo");
								break;
							case 5:
								preguntarInteger(&pasajeros[indexPosicion].typePassenger, "\n Ingrese el tipo de pasajero");
								break;
							case 6:
								break;
							default:
								printf("Ingrese una opcion valida");
						}

					}while(opcionElegidaCaseDos != 6);
				}
				break;
			case 3:
			{
				printf("%s",pasajeros[0].name);
				id = preguntarId("Cual es la id del pasajero que quiere eliminar?");
				indexPosicion= findPassengerById(pasajeros, elementos, id);

				if (indexPosicion == -1){
					printf("Esa id no existe");
				}else{
//					removePassenger(pasajeros, elementos, indexPosicion);

					printf("pasajero eliminado correctamente");
				}
				break;
			}
			case 4:
			{
				sortPassenger(pasajeros, elementos, 1);

				printPassenger(pasajeros, elementos);

//				promedioVuelos(pasajeros, elementos, &total);

				printf("%s", pasajeros[0].name);
				break;
			}
			case 5:
			{
				printf("Selecciono la opcion CINCO");
				break;
			}
			case 6:
			{
				printf("Saliendo....");
				break;
			}
			default:
			{
				printf("Opcion incorrecta");
				break;
			}
		}
	}while(opcionElegida != 6);



};
