#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"
#include "ArrayPassenger.h"

int main(void) {
	setbuf(stdout, NULL);


	int opcionElegida;
	int opcionElegidaInformar;
	int elementos = 2000;
	int id = 0;
	int indexPosicion;
	int modificado;
	int eliminado;
	float totalPrecio = 0;
	float promedio = 0;
	int superaPromedioCant = 0;
	int ingresoPasajero= 0;

	Passenger pasajeros[elementos];
	Passenger auxPasajero;
	initPassengers(pasajeros, elementos);

	do{
		mostrarMenu(&opcionElegida);
		switch(opcionElegida){
			case 1:
			{
				if(utn_getString(auxPasajero.name, NOMBRE_LEN, "\nIntroduzca el nombre del pasajero ", "Nombre incorrecto", 3) == -1 ||
				   utn_getString(auxPasajero.lastName, NOMBRE_LEN, "\nIntroduzca el apellido del pasajero ", "Apellido incorrecto", 3) == -1 ||
				   utn_getNumeroFlotante(&auxPasajero.price, "\nIntroduzca el precio del vuelo ", "Precio incorrecto", 0, 9999999999999, 3) == -1 ||
				   utn_getString(auxPasajero.flycode, 10, "\nIntroduzca el codigo del vuelo ", "Codigo del vuelo incorrecto ", 3) == -1 ||
				   utn_getNumero(&auxPasajero.typePassenger, "\nIntroduzca el tipo de pasajero \n1.Para clase turista \n2.Para clase ejecutiva \n3.Para vip\n", "Tipo de pasajero incorrecto", 1, 3, 3) == -1 ||
				   utn_getNumero(&auxPasajero.statusFly, "\nIntroduzca el estado del vuelo \n1.Activo \n2.Inactivo", "Estado del vuelo incorrecto\n", 1, 2, 3) == -1)
				   {
					printf("\n Error al agregar pasajero");
				   }
				else{
					auxPasajero.id= id;
					id++;
					auxPasajero.isEmpty= 0;
					addPassanger(pasajeros, elementos, auxPasajero);
					ingresoPasajero = 1;
				}
				break;
			}
			case 2:
				if(ingresoPasajero == 1){
					id = preguntarId("\nCual es la id que quiere modificar? ");
					indexPosicion= findPassengerById(pasajeros, elementos, id);

					if(indexPosicion== -1){
						printf("\n Id no encontrada!!\n");
					}else{
						modificado = modificarPassenger(pasajeros, elementos, indexPosicion);
						if(!modificado){
							printf("\nPasajero modificado correctamente!!!");
						}else{
							if(modificado == 1){
								printf("\nVolviendo al menu...");
							}else{
								printf("\nError al modifcar le pasajero!!");
							}
						}
					}
				}else{
					printf("\nDebe ingresar un pasajero primero!!");
				}
				break;
			case 3:
			{
				if(ingresoPasajero == 1){
					id = preguntarId("\nCual es la id del pasajero que quiere eliminar?");
					indexPosicion= findPassengerById(pasajeros, elementos, id);

					if (indexPosicion == -1){
						printf("\nEsa id no existe");
					}else{
						eliminado = removePassenger(pasajeros, elementos, indexPosicion);
						if(!eliminado){
							printf("\nPasajero eliminado correctamente!!");
						}else{
							if(eliminado == 1){
								printf("\nVolviendo al menu...");
							}else{
								printf("\nError al eliminar el pasajero");
							}
						}
					}
				}else{
					printf("\nDebe ingresar un pasajero primero!!");
				}

				break;
			}
			case 4:
			{
				if(ingresoPasajero == 1){
					mostrarMenuInformar(&opcionElegidaInformar);

					switch(opcionElegidaInformar){
						case 1:
							if(!sortPassenger(pasajeros, 2000, 1)){
								printPassengers(pasajeros, elementos);
							}
							break;
						case 2:
							calcularPromedio(pasajeros, 2000, &totalPrecio, &promedio);
							printf("\nEl total de los precios es: %.2f y el promedio es %.2f", totalPrecio, promedio);
							superaPromedio(pasajeros, 2000, &superaPromedioCant, &promedio);
							printf("\nSuperan el promedio %d pasajeros", superaPromedioCant);
							break;
						case 3:
							if(!sortPassengersByCode(pasajeros, 2000, 1)){
								printPassengers(pasajeros, elementos);
							}
						case 4:
							break;
					}
				}else{
					printf("\nDebe ingresar un pasajero primero!");
				}

				break;
			}
			case 5:
			{
				cargaForzada(pasajeros, 2000, &id);
				ingresoPasajero = 1;
				break;
			}
			case 6:
			{
				printf("Saliendo....");
				break;
			}
		}
	}while(opcionElegida != 6);



};
