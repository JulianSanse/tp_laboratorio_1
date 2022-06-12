#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path Path del archivo a leer
 * \param pArrayListPassenger lista donde se van a guardar los datos
 * \param proximoId puntero al proximo id
 * \return -1 en caso de error y 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* proximoId)
{
	int retorno = -1;
	FILE* fp;
	fp = fopen(path, "r");

	if(!parser_PassengerFromText(fp, pArrayListPassenger, proximoId)){
		retorno = 0;
	};

	fclose(fp);
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
 * \param path Path del archivo a leer
 * \param pArrayListPassenger Lista donde se cargaran los datos
 * \return -1 en caso de error y 0 en caso de exito
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* fp;
	fp = fopen(path, "rb");

	if(!parser_PassengerFromBinary(fp, pArrayListPassenger)){
		retorno = 0;
	};

	fclose(fp);
	return retorno;

    return 1;
}

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger Lista donde se va a agregar el pasajero
 * \param proximoId Id que se le debe asignar al pasajero
 * \return -1 en caso de error y 0 en caso de exito
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int *proximoId)
{
	int retorno = -1;
	char auxId[50];
	*proximoId = *proximoId + 1;
	itoa(*proximoId, auxId, 10);
	char auxNombre[NOMBRE_LEN];
	char auxApellido[NOMBRE_LEN];
	char auxPrecio[NOMBRE_LEN];
	char auxTipoPasajero[NOMBRE_LEN];
	char auxCodigoVuelo[NOMBRE_LEN];
	char auxStatusVuelo[NOMBRE_LEN];
	Passenger* aux;

	utn_getString(auxNombre, NOMBRE_LEN, "\nIntroduzca el nombre del pasajero", "No es posible asignar ese nombre", 3);
	utn_getString(auxApellido,NOMBRE_LEN, "\nIntroduzca el apellido del pasajero","No es posible asignas ese apellido",3);
	utn_getString(auxPrecio, NOMBRE_LEN,"\nIntroduzca el precio del vuelo", "Error al ingresar el precio", 3);
	utn_getString(auxTipoPasajero, NOMBRE_LEN, "\nIntroduzca el tipo de pasajero", "No es posible asignar el tipo de pasajero", 3);
	utn_getString(auxCodigoVuelo, NOMBRE_LEN, "\nIntroduzca el codigo del vuelo", "No es posible asignar ese codigo de vuelo", 3);
	utn_getString(auxStatusVuelo, NOMBRE_LEN, "\nIntroduzca el status del vuelo", "No es posible asignar ese status de vuelo", 3);


	aux = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxStatusVuelo);

	if(aux!=NULL){
		ll_add(pArrayListPassenger, aux);
		printf("\nId del pasajero cargado: %d\n", aux->id);
		retorno = 0;
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger lista donde se encuentra el pasajero a modificar
 * \return -1 en caso de error y 0 en caso de exito
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* aux;
	int idModificar;
	int len;
	len = ll_len(pArrayListPassenger);
	utn_getNumero(&idModificar, "Que id desea modificar?", "Id no encontrado", 0, len, 3);

	aux = ll_get(pArrayListPassenger, idModificar -1);
	if(aux!= NULL){
		if(!Passenger_modificar(aux)){
			retorno = 0;
		}
	}else{
		printf("No se encontro ese id");
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger Lista donde se encuentra el pasajeor a eliminar
 * \return -1 en caso de error y 0 en caso de exito
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int index;
	int retorno = -1;
	int respuesta;
	Passenger* aux;
	int idEliminar;
	int len;
	len = ll_len(pArrayListPassenger);
	utn_getNumero(&idEliminar, "Que id desea eliminar?", "Id no encontrado", 0, len, 3);



	aux= ll_get(pArrayListPassenger, idEliminar-1);
	printf("Desea modificar el siguiente pasajero?\n");
	Passenger_imprimir(aux);
	utn_getNumero(&respuesta, " 1.SI\n 2.NO", "opcion incorrecta", 1, 2, 3);
	if(respuesta == 1){
		index = ll_indexOf(pArrayListPassenger, aux);
		Passenger_delete(aux);
		aux= NULL;
		ll_pop(pArrayListPassenger, index);

		retorno = 0;
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList lista donde se encuentran todos los pasajeros a imprimir
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
    Passenger* aux;
	int len = ll_len(pArrayListPassenger);
	int i;

	printf("____________________LISTA PASAJEROS______________________\n");
	if(pArrayListPassenger != NULL){
		for(i = 0; i<len; i++){
			aux=ll_get(pArrayListPassenger, i);
			if(aux!=NULL){
				Passenger_imprimir(aux);
			}
		}
		retorno =0;
	}
	return retorno;

}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger lista de los pasajeros a ordenar
 * \return -1  en caso de error y 0 en caso de exito
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int orden;
	utn_getNumero(&orden, "0. Orden Descendente\n1. Orden ascendente \n ", "Opcion incorrecta", 0, 1, 3);

	if(pArrayListPassenger != NULL){
		ll_sort(pArrayListPassenger, Passenger_sortByName, orden);
		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path direccion donde se van a guardar los elementos
 * \param pArrayListPassenger Lista de los elementos a guardar
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno =-1;
	int i;
	FILE* fpArchivo;
	int len;
	Passenger* aux;
	int auxId;
	char auxNombre[NOMBRE_LEN];
	char auxApellido[NOMBRE_LEN];
	float auxPrecio;
	char auxTipoPasajero[NOMBRE_LEN];
	char auxCodigoVuelo[NOMBRE_LEN];
	char auxStatusVuelo[NOMBRE_LEN];
	len = ll_len(pArrayListPassenger);

	fpArchivo = fopen(path, "w");
			if(fpArchivo!=NULL){
				retorno = 0;
				fprintf(fpArchivo,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
				for(i=0; i<len; i++){
					aux=ll_get(pArrayListPassenger,i);
					if(aux != NULL){
						Passenger_getId(aux, &auxId);
						Passenger_getNombre(aux, auxNombre);
						Passenger_getApellido(aux, auxApellido);
						Passenger_getPrecio(aux, &auxPrecio);
						Passenger_getTipoPasajero(aux, auxTipoPasajero);
						Passenger_getCodigoVuelo(aux, auxCodigoVuelo);
						Passenger_getStatusVuelo(aux, auxStatusVuelo);

						fprintf(fpArchivo,"%d,%s,%s,%.0f,%s,%s,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxStatusVuelo);

					}
				}
				fclose(fpArchivo);
			}


		return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path direccion donde se van a guardar los elementos
 * \param pArrayListPassenger Lista de los elementos a guardar
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* fpArchivo;
	int retorno= -1;
	Passenger* aux;
	fpArchivo = fopen(path, "wb");
	int len;
	len = ll_len(pArrayListPassenger);
	int i;
	if(fpArchivo != NULL){
		for(i=0; i<len; i++){
			aux=ll_get(pArrayListPassenger,i);
			if(aux!=NULL){
				fwrite(aux, sizeof(Passenger),1,fpArchivo);
			}
		}
		retorno = 0;
	}
    return retorno;
}

