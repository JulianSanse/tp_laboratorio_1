#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile Archivo desde el cual se van a parsear y leer los datos
 * \param pArrayListPassenger Lista donde se cargaran los datos
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, int* proximoId){

	int retorno = -1;
	char auxiliarId[4096];
	char auxiliarNombre[4096];
	char auxiliarApellido[4096];
	char auxiliarPrecio[4096];
	char auxiliarTipoPasajero[4096];
	char auxiliarCodigoVuelo[4096];
	char auxiliarStatusVuelo[4096];
	Passenger* aux;


	if(pArrayListPassenger != NULL && pFile != NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarApellido, auxiliarPrecio, auxiliarCodigoVuelo, auxiliarTipoPasajero, auxiliarStatusVuelo);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarApellido, auxiliarPrecio, auxiliarCodigoVuelo, auxiliarTipoPasajero, auxiliarStatusVuelo) == 7){

					aux = Passenger_newParametros(auxiliarId, auxiliarNombre, auxiliarApellido, auxiliarPrecio, auxiliarTipoPasajero, auxiliarCodigoVuelo, auxiliarStatusVuelo);
				if(aux !=NULL){
					ll_add(pArrayListPassenger, aux);
					if(atoi(auxiliarId) > *proximoId){
						*proximoId = atoi(auxiliarId);
					}
					retorno = 0;
				}else{
					printf("Error al agregar el pasajero a la lista\n");
				}
			}else{
				printf("error al leer el archivo");
			}
		}while(!feof(pFile));
	}

    return retorno;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param pFile Archivo desde el cual se van a parsear y leer los datos
 * \param pArrayListPassenger Lista donde se cargaran los datos
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int cantidad;
	Passenger* aux;

	if(pFile!= NULL){
		while(!feof(pFile)){
			aux = Passenger_new();
			cantidad = fread(aux, sizeof(Passenger),1,pFile);

			if(cantidad == 1){
				ll_add(pArrayListPassenger, aux);
				retorno = 0;
			}
		}
	}
    return retorno;
}
