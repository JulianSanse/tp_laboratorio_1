#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Alumno.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los alumnos desde el archivo data.csv (modo texto).
 *
 * \param path Path del archivo a leer
 * \param pArrayListAlumno lista donde se van a guardar los datos
 * \param proximoId puntero al proximo id
 * \return -1 en caso de error y 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListAlumno, int* proximoId)
{
	int retorno = -1;
	FILE* fp;
	fp = fopen(path, "r");

	if(fp!= NULL){
		if(!parser_AlumnoFromText(fp, pArrayListAlumno, proximoId)){
			retorno = 0;
		}else{
			printf("Error en el parser");
		}
	}else{
		printf("archivo nulo");
	}


	fclose(fp);
	return retorno;
}
/** \brief Alta de alumno
 *
 * \param pArrayListAlumno Lista donde se va a agregar el alumno
 * \param proximoId Id que se le debe asignar al alumno
 * \return -1 en caso de error y 0 en caso de exito
 *
 */
int controller_addAlumno(LinkedList* pArrayListAlumno, int *proximoId)
{
	int retorno = -1;
	char auxId[50];
	*proximoId = *proximoId + 1;
	itoa(*proximoId, auxId, 10);
	char auxNombre[NOMBRE_LEN];
	char auxApellido[NOMBRE_LEN];
	char auxEdad[NOMBRE_LEN];
	char auxLegajo[NOMBRE_LEN];
	char auxDivision[NOMBRE_LEN];
	char auxCondicion[NOMBRE_LEN];
	Alumno* aux;

	utn_getString(auxNombre, NOMBRE_LEN, "\nIntroduzca el nombre del alumno", "No es posible asignar ese nombre", 3);
	utn_getString(auxApellido,NOMBRE_LEN, "\nIntroduzca el apellido del alumno","No es posible asignas ese apellido",3);
	utn_getString(auxEdad, NOMBRE_LEN,"\nIntroduzca la edad del alumno", "Error al ingresar esa edad", 3);
	utn_getString(auxLegajo, NOMBRE_LEN, "\nIntroduzca el legajo del alumno", "No es posible asignar el legajo", 3);
	utn_getString(auxDivision, NOMBRE_LEN, "\nIntroduzca la division del alumno", "No es posible asignar esa division", 3);
	utn_getString(auxCondicion, NOMBRE_LEN, "\nIntroduzca la condicion del alumno", "No es posible asignar esa condicion", 3);


	aux = Alumno_newParametros(auxId, auxNombre, auxApellido, auxEdad, auxLegajo, auxDivision, auxCondicion);

	if(aux!=NULL){
		ll_add(pArrayListAlumno, aux);
		printf("\nId del alumno cargado: %d\n", aux->id);
		retorno = 0;
	}
	return retorno;
}
/** \brief Modificar datos de alumno
 *
 * \param pArrayListAlumno lista donde se encuentra el alumno a modificar
 * \return -1 en caso de error y 0 en caso de exito
 *
 */
int controller_editAlumno(LinkedList* pArrayListAlumno)
{
	int retorno = -1;
	Alumno* aux;
	int idModificar;
	int len;
	len = ll_len(pArrayListAlumno);
	utn_getNumero(&idModificar, "Que id desea modificar?", "Id no encontrado", 0, len, 3);

	aux = ll_get(pArrayListAlumno, idModificar -1);
	if(aux!= NULL){
		if(!Alumno_modificar(aux)){
			retorno = 0;
		}
	}else{
		printf("No se encontro ese id");
	}
    return retorno;
}
/** \brief Listar alumnos
 *
 * \param pArrayListAlumno LinkedList lista donde se encuentran todos los alumnos a imprimir
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int controller_ListAlumno(LinkedList* pArrayListAlumno)
{
	int retorno = -1;
    Alumno* aux;
	int len = ll_len(pArrayListAlumno);
	int i;

	printf("______________________________________________________LISTA ALUMNOS__________________________________________\n");
	if(pArrayListAlumno != NULL){
		for(i = 0; i<len; i++){
			aux=ll_get(pArrayListAlumno, i);
			if(aux!=NULL){
				Alumno_imprimir(aux);
			}
		}
		retorno =0;
	}
	return retorno;

}
/** \brief Baja de alumno
 *
 * \param pArrayListAlumno Lista donde se encuentra el pasajeor a eliminar
 * \return -1 en caso de error y 0 en caso de exito
 *
 */
int controller_removeAlumno(LinkedList* pArrayListAlumno)
{
	int index;
	int retorno = -1;
	int respuesta;
	Alumno* aux;
	int idEliminar;
	int len;
	len = ll_len(pArrayListAlumno);
	utn_getNumero(&idEliminar, "Que id desea eliminar?", "Id no encontrado", 0, len, 3);

	aux= ll_get(pArrayListAlumno, idEliminar-1);
	printf("Desea eliminar el siguiente alumno?\n");
	Alumno_imprimir(aux);
	utn_getNumero(&respuesta, " 1.SI\n 2.NO", "opcion incorrecta", 1, 2, 3);
	if(respuesta == 1){
		index = ll_indexOf(pArrayListAlumno, aux);
		Alumno_delete(aux);
		aux= NULL;
		ll_pop(pArrayListAlumno, index);

		retorno = 0;
	}

    return retorno;
}

/** \brief Ordenar alumnos
 *
 * \param path char*
 * \param pArrayListAlumno lista de los alumnos a ordenar
 * \return -1  en caso de error y 0 en caso de exito
 *
 */
int controller_sortAlumnos(LinkedList* pArrayListAlumno)
{
	int retorno = -1;
	int orden;
	utn_getNumero(&orden, "0. Orden Descendente\n1. Orden ascendente \n ", "Opcion incorrecta", 0, 1, 3);

	if(pArrayListAlumno != NULL){
		ll_sort(pArrayListAlumno, Alumno_sortByApellido, orden);
		retorno = 0;
	}
	return retorno;
}
/** \brief Guarda los datos de los alumnos en el archivo data.csv (modo texto).
 *
 * \param path direccion donde se van a guardar los elementos
 * \param pArrayListAlumno Lista de los elementos a guardar
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListAlumno)
{
	int retorno =-1;
	int i;
	FILE* fpArchivo;
	int len;
	Alumno* aux;
	int auxId;
	char auxNombre[NOMBRE_LEN];
	char auxApellido[NOMBRE_LEN];
	int auxEdad;
	char auxLegajo[NOMBRE_LEN];
	char auxDivision[NOMBRE_LEN];
	char auxCondicion[NOMBRE_LEN];
	len = ll_len(pArrayListAlumno);

	fpArchivo = fopen(path, "w");
			if(fpArchivo!=NULL){
				retorno = 0;
				fprintf(fpArchivo,"id,name,lastname,price,flycode,typeAlumno,statusFlight\n");
				for(i=0; i<len; i++){
					aux=ll_get(pArrayListAlumno,i);
					if(aux != NULL){
						Alumno_getId(aux, &auxId);
						Alumno_getNombre(aux, auxNombre);
						Alumno_getApellido(aux, auxApellido);
						Alumno_getEdad(aux, &auxEdad);
						Alumno_getLegajo(aux, auxLegajo);
						Alumno_getDivision(aux, auxDivision);
						Alumno_getCondicion(aux, auxCondicion);

						fprintf(fpArchivo,"%d,%s,%s,%d,%s,%s,%s\n", auxId, auxNombre, auxApellido, auxEdad, auxLegajo, auxDivision, auxCondicion);

					}
				}
				fclose(fpArchivo);
			}


		return retorno;
}

/** \brief Guarda los datos de los alumnos en el archivo data.csv (modo binario).
 *
 * \param path direccion donde se van a guardar los elementos
 * \param pArrayListAlumno Lista de los elementos a guardar
 * \return int -1 en caso de error y 0 en caso de exito
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListAlumno)
{
	FILE* fpArchivo;
	int retorno= -1;
	Alumno* aux;
	fpArchivo = fopen(path, "wb");
	int len;
	len = ll_len(pArrayListAlumno);
	int i;
	if(fpArchivo != NULL){
		for(i=0; i<len; i++){
			aux=ll_get(pArrayListAlumno,i);
			if(aux!=NULL){
				fwrite(aux, sizeof(Alumno),1,fpArchivo);
			}
		}
		retorno = 0;
	}
    return retorno;
}

int controller_deleteAlumnos(LinkedList* pArrayListAlumno){
	int retorno = -1;
	int respuesta;
	if(pArrayListAlumno != NULL){
		utn_getNumero(&respuesta, "Esta seguro que quiere eliminar todos los alumnos?\n 1.Si\n 2.No", "Opcion incorrecta", 1, 2, 3);
		if( respuesta == 1){
			ll_clear(pArrayListAlumno);
			retorno = 0;
		}
	}
	return retorno;
}

int controller_buscarAlumno(LinkedList* pArrayListAlumno){
	int retorno = -1;
	char respuesta[200];
	int i;
	int len = ll_len(pArrayListAlumno);
	Node* aux;
	Alumno* auxAlumno;
	if(pArrayListAlumno != NULL && len > 0){
		utn_getString(respuesta, 200, "Cual es el legajo del alumno del cual quiere saber la id?", "Legajo inexistente", 3);
		for(i= 0; i < len; i++){
			aux = test_getNode(pArrayListAlumno, i);
			auxAlumno = aux->pElement;
			if(strcmp(auxAlumno->legajo, respuesta) == 0){
				retorno=  auxAlumno->id;
				break;
			}
		}

	}

	return retorno;
}
