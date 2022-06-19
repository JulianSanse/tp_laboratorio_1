#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Alumno.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile Archivo desde el cual se van a parsear y leer los datos
 * \param pArrayListPassenger Lista donde se cargaran los datos
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int parser_AlumnoFromText(FILE* pFile , LinkedList* pArrayListAlumno, int* proximoId){

	int retorno = -1;
	char auxiliarId[4096];
	char auxiliarNombre[4096];
	char auxiliarApellido[4096];
	char auxiliarEdad[4096];
	char auxiliarLegajo[4096];
	char auxiliarDivision[4096];
	char auxiliarCondicion[4096];
	Alumno* aux;

	if(pArrayListAlumno != NULL && pFile != NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarApellido, auxiliarEdad, auxiliarLegajo, auxiliarDivision, auxiliarCondicion);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarApellido, auxiliarEdad, auxiliarLegajo, auxiliarDivision, auxiliarCondicion) == 7){

				aux = Alumno_newParametros(auxiliarId, auxiliarNombre, auxiliarApellido, auxiliarEdad, auxiliarLegajo, auxiliarDivision, auxiliarCondicion);
				if(aux !=NULL){
					ll_add(pArrayListAlumno, aux);
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


