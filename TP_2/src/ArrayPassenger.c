#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayPassenger.h"
#include "utn.h"

/*
 * \brief Inicializa el array de pasajeros
 * \param list Lista de pasajero a inicializar
 * \param len largo de la lista
 * return -1 en caso de error y 0 en caso de exito
 */
int initPassengers(Passenger* list, int len)
{
	int retorno = -1;

	if (len <= 2000 && list != NULL){
		for(int i = 0; i<= len; i++){
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief agrega un pasajero a la lista
 * \param pArray array donde quiero agregar el pasajero
 * \param largo largo del array
 * \param auxPasajero pasajero que quiero agregar a la lista
 * return -1 en caso de error y 0 en caso de exito
 */
int addPassanger(Passenger* pArray, int largo, Passenger auxPasajero){
	int retorno = -1;
	if(pArray != NULL && largo > 0){
		for(int i = 0; i < largo; i++){
			if(pArray[i].isEmpty == 1){
				pArray[i] = auxPasajero;
				printf("----------------------------------------------------------\n"
						"El pasajero se cargo correctamente!! Id del pasajero: %d \n"
						"----------------------------------------------------------\n" ,pArray[i].id);
				break;
			}
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * \brief busca a un pasajero por su id y devuelve su index
 * \param list Lista de pasajeros donde busco el id
 * \param len largo de la lista
 * \param id id que quiero buscar
 * return -1 en caso de error y un numero > 0 que seria el indice en caso de exito
 */
int findPassengerById(Passenger* list, int len,int id){

		for(int i = 0; i< len; i++){
			if(list[i].id == id && list[i].isEmpty == 0){
				return i;
			}
		}
		return -1;
}
/*
 * \brief Recibe una posicion de index y da un menu para elegir que parametro modificar de ese pasajero
 * \param pasajeros Listas de pasajeros donde se encuentra el pasajero qquiero modificar
 * \param len largo de la lista
 * \param indexPosicion posicion donde se encuentra el pasajero en la lista
 * return -1 en caso de error y 0 en caso de exito
 */
int modificarPassenger(Passenger* pasajeros, int len, int indexPosicion){
	int retorno = -1;
	int opcionElegida;
	int respuesta;
	if(pasajeros!= NULL && len >= 0 && indexPosicion >= 0){
		printf("\nDesea modificar el siguiente pasajero?");
		printPassenger(pasajeros[indexPosicion]);
		utn_getNumero(&respuesta, "\n1.Si \n2.No ", "\nOpcion incorrecta", 1, 2, 3);
		if(respuesta == 1){
			mostrarMenuCaseDos(&opcionElegida);
		    switch(opcionElegida){
				case 1:
					utn_getString(pasajeros[indexPosicion].name, NOMBRE_LEN, "\nIngrese el nombre del pasajero a modificar ", "\nNombre incorrecto ", 3);
					retorno = 0;
					break;
				case 2:
					utn_getString(pasajeros[indexPosicion].lastName, NOMBRE_LEN, "\nIngrese el apellido del pasajero a modificar ", "\nApellido incorrecto ", 3);
					retorno = 0;
					break;
				case 3:
					utn_getNumeroFlotante(&pasajeros[indexPosicion].price, "\n Ingrese el precio del vuelo del pasajero a modificar ", "\nPrecio del vuelo incorrecto ", 0, 9999999999999, 3);
					retorno = 0;
					break;
				case 4:
					utn_getString(pasajeros[indexPosicion].flycode, 10, "\n Ingrese el codigo del vuelo del pasajero a modificar ", "\nCodigo del vuelo incorrecto ", 3);
					retorno = 0;
					break;
				case 5:
					utn_getNumero(&pasajeros[indexPosicion].typePassenger, "\n Ingrese el tipo de pasajero a modificar \n1.Para clase turista \n2.Para clase ejecutiva \n3.Para vip\n", "\nTipo de pasajero incorrecto ", 1, 3, 3);
					retorno = 0;
					break;
				case 6:
					retorno = 1;
					break;
				default:
					printf("Ingrese una opcion valida");
			}
		}else{
			retorno = 1;
		}
	}
	return retorno;
}
/*
 * \brief borra un pasajero de la lista
 *\param list Lista donde se encuentra el pasajero que quiero borrar
 *\param len largo de la lista
 *\param id id del pasajero que se desea eliminar
 *return -1 en caso de error y 0 en caso de exito
 */
int removePassenger(Passenger* list, int len, int id){
	int retorno = -1;
	int respuesta;

	if (id != -1){
		for(int i = 0; i <2000; i++){
			if (list[i].id == id){
				printf("\nDesea eliminar el siguiente pasajero?");
				printPassenger(list[i]);
				utn_getNumero(&respuesta, "\n1.Si \n2.No ", "\nOpcion incorrecta", 1, 2, 3);
				if(respuesta == 1){
					list[i].isEmpty= 1;
					retorno = 0;
					break;
				}else{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}
/*
 *\brief Ordena la lista por apellido y tipo de pasajero
 *\param list lista a ordenar
 *\param len largo de la lista a ordenar
 *\param order 1 para ascendente 0 para descendente
 *return -1 en caso de error y 0 en caso de exito
 */
int sortPassenger(Passenger* list, int len, int order)
{
	Passenger auxiliar;
	int retorno = -1;
		if (list != NULL && len >= 0){
			if (order == 1){
				for (int i = 0; i < len; i++){
					for(int j = i + 1; j < len - 1; j++){
						if (strcmp(list[i].lastName, list[j].lastName) > 0){
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if(strcmp(list[i].lastName, list[j].lastName) == 0){
							if(list[i].typePassenger > list[j].typePassenger){
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
			}else{
				for (int i = 0; i < len; i++){
					for(int j = i + 1; j < len - 1; j++){
						if (strcmp(list[i].lastName, list[j].lastName) < 0){
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
						if(strcmp(list[i].lastName, list[j].lastName) == 0){
							if(list[i].typePassenger > list[j].typePassenger){
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
							}
						}
					}
				}


		}
			retorno = 0;
	}

		return retorno;

}
/*
 * \brief imprime un pasajero
 * \param pasajero a imprimir
 */
void printPassenger(Passenger pasajero){
	char tipoAux[20];
	char estadoAux[20];

	if(pasajero.isEmpty != 1){
			switch(pasajero.typePassenger){
				case 1:
					strcpy(tipoAux, "Turista");
					break;
				case 2:
					strcpy(tipoAux, "Ejecutiva");
				    break;
				case 3:
					strcpy(tipoAux, "VIP");
					break;

			}

			switch(pasajero.statusFly){
				case 1:
					strcpy(estadoAux, "Activo");
					break;
				case 2:
					strcpy(estadoAux, "Inactivo");
					break;
			}
			printf("\n ID: %d - NOMBRE: %s - APELLIDO: %s - PRECIO: %.2f - CODIGO: %s - TIPO: %s - ESTATUS: %s", pasajero.id, pasajero.name , pasajero.lastName,pasajero.price, pasajero.flycode, tipoAux, estadoAux);
		}
}
/*
 *\brief Imprime la lista de pasajeros
 *\param list lista a imprimir
 *\param len largo de la lista
 *return -1 en caso de error y 0 en caso de exito
 */
int printPassengers(Passenger* list, int len){
	int retorno = -1;
	if(list!= NULL && len >=0){
		printf("____________________________________________________________LISTA PASAJEROS___________________________________________");
		for(int i = 0; i< len; i++){
			printPassenger(list[i]);
		}
		retorno = 0;
	}
	return retorno;

}
/*
 *\brief calcula el promedio y el total del precio
 *\param list lista de pasajeros a calcular
 *\param len largo de la lista
 *\param totalPrecio puntero donde se va a guardar el total del precio
 *\param promedio puntero donde se va a guardar el promedio
 */
void calcularPromedio(Passenger* list, int len, float* totalPrecio, float* promedio){
	int i;
	int contador = 0;

	if(list != NULL && len > 0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == 0){
				*totalPrecio = *totalPrecio + list[i].price;
				contador++;
			}
		}
	}

	*promedio = *totalPrecio/ contador;

}
/*
 *\brief calcula cuantos pasajeros superan el promedio
 *\param list lista de pasajeros a calcular
 *\param len largo de la lista
 *\param superaPromedio puntero donde se va a guardar la cantidad de pasajeros q superen el promedio
 *\param promedio puntero que otorga el valor del promedio
 */
void superaPromedio(Passenger* list, int len, int* superaPromedio, float* promedio){
	int i;
	if(list!= NULL && len>0){
		for(i=0; i< len; i++){
			if(list[i].isEmpty == 0 && list[i].price > *promedio){
				*superaPromedio = *superaPromedio + 1 ;
			}
	    }
	}

}
/*
 *\brief Ordena la lista por codigo y el estatus de vuelo
 *\param list lista a ordenar
 *\param len largo de la lista a ordenar
 *\param order 1 para ascendente 0 para descendente
 *return -1 en caso de error y 0 en caso de exito
 */
int sortPassengersByCode(Passenger* list, int len, int order)
{
	Passenger auxiliar;
	int retorno = -1;

	if (list != NULL && len >= 0){
		if (order == 1){
			for (int i = 0; i < len; i++){
				for(int j = i + 1; j < len - 1; j++){
					if(strcmp(list[i].flycode, list[j].flycode) > 0){
						auxiliar = list[j];
						list[j] = list[i];
						list[i] = auxiliar;
					}
					if(strcmp(list[i].flycode, list[j].flycode) == 0){
						if(list[i].statusFly > list[j].statusFly){
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
					}
				}
			}
		}else{
			for (int i = 0; i < len; i++){
				for(int j = i + 1; j < len - 1; j++){
					if (strcmp(list[i].flycode, list[j].flycode) < 0){
						auxiliar = list[j];
						list[j] = list[i];
						list[i] = auxiliar;
					}
					if(strcmp(list[i].flycode, list[j].flycode) == 0){
						if(list[i].statusFly > list[j].statusFly){
							auxiliar = list[j];
							list[j] = list[i];
							list[i] = auxiliar;
						}
					}
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}
/*
 * \brief carga pasajeros de forma forzada
 * \param list lista donde se van a cargar los pasajeros
 * \param len largo de la lista
 * \param id id que se les va a otorgar
 */
void cargaForzada(Passenger* list, int len, int* id){
	Passenger auxPasajero;

	auxPasajero.id= *id;
	strcpy(auxPasajero.name, "Ian");
	strcpy(auxPasajero.lastName, "Ramirez");
	auxPasajero.price = 250000;
	strcpy(auxPasajero.flycode, "CCC212");
	auxPasajero.typePassenger = 1;
	auxPasajero.statusFly= 1;
	auxPasajero.isEmpty = 0;
	*id = *id + 1;

	addPassanger(list, len, auxPasajero);

	auxPasajero.id= *id;
	strcpy(auxPasajero.name, "Julian");
	strcpy(auxPasajero.lastName, "Sanse");
	auxPasajero.price = 200000;
	strcpy(auxPasajero.flycode, "BBB121");
	auxPasajero.typePassenger = 2;
	auxPasajero.statusFly= 2;
	auxPasajero.isEmpty = 0;
	*id = *id + 1;

	addPassanger(list, len, auxPasajero);

	auxPasajero.id= *id;
	strcpy(auxPasajero.name, "Jorge");
	strcpy(auxPasajero.lastName, "Nieva");
	auxPasajero.price = 150000;
	strcpy(auxPasajero.flycode, "AAA012");
	auxPasajero.typePassenger = 3;
	auxPasajero.statusFly= 1;
	auxPasajero.isEmpty = 0;
	*id = *id + 1;

	addPassanger(list, len, auxPasajero);

	auxPasajero.id= *id;
	strcpy(auxPasajero.name, "Juan");
	strcpy(auxPasajero.lastName, "Dominguez");
	auxPasajero.price = 100000;
	strcpy(auxPasajero.flycode, "ababa10");
	auxPasajero.typePassenger = 1;
	auxPasajero.statusFly= 1;
	auxPasajero.isEmpty = 0;
	*id = *id + 1;

	addPassanger(list, len, auxPasajero);

	auxPasajero.id= *id;
	strcpy(auxPasajero.name, "Matias");
	strcpy(auxPasajero.lastName, "Moreyra");
	auxPasajero.price = 250000;
	strcpy(auxPasajero.flycode, "ZZZ999");
	auxPasajero.typePassenger = 3;
	auxPasajero.statusFly= 2;
	auxPasajero.isEmpty = 0;
	*id = *id + 1;

	addPassanger(list, len, auxPasajero);

}
