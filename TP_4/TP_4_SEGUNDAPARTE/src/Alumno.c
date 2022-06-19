#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Alumno.h"
#include "utn.h"

static int esNumerica(char* cadena, int limite);
static int esNombre(char* cadena, int longitud);

/**
 *\brief Crea un lugar en memoria para un nuevo alumno
 *return Retorna el espacio en memoria del nuevo alumno
 */
Alumno* Alumno_new(){
	return (Alumno*) malloc(sizeof(Alumno));
}

Alumno* Alumno_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* edadStr,char* legajoStr, char* divisionStr, char* condicionStr){
	Alumno* auxiliarAlumno= NULL;
	auxiliarAlumno = Alumno_new();
	if(auxiliarAlumno!= NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && edadStr != NULL && legajoStr != NULL && divisionStr != NULL && condicionStr != NULL ){
		if(Alumno_setIdTxt(auxiliarAlumno, idStr) == -1 ||
		   Alumno_setNombre(auxiliarAlumno, nombreStr) == -1 ||
		   Alumno_setApellido(auxiliarAlumno, apellidoStr) == -1 ||
		   Alumno_setEdadTxt(auxiliarAlumno, edadStr) == -1 ||
		   Alumno_setLegajo(auxiliarAlumno, legajoStr) == -1 ||
		   Alumno_setDivision(auxiliarAlumno, divisionStr) == -1 ||
		   Alumno_setCondicion(auxiliarAlumno, condicionStr) == -1)
		{
			Alumno_delete(auxiliarAlumno);
			auxiliarAlumno= NULL;
			printf("\nSe devolvio un Alumno nulo\n");
		}
	}
	return auxiliarAlumno;
}
/**
 * \brief Libera el lugar en la memoria de un alumno
 * \param this Alumno a eliminar/ liberar memoria
 */
void Alumno_delete(Alumno* this){
	if(this != NULL){
		free(this);
	}
}
//******************************************************************************************************************
/**
 * \brief imprime el alumno que le pasemos
 * \param this alumno a imprimir
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_imprimir(Alumno* this){
	int retorno = -1;

	if(this != NULL){
		printf("ID: %d - NOMBRE: %s - APELLIDO: %s - EDAD: %d - LEGAJO: %s - DIVISION: %s - CONDICION: %s\n", this->id, this->nombre, this->apellido, this->edad, this->legajo, this->division, this->condicion);
		retorno =0;
	}
	return retorno;
}

/**
 * \brief Pregunta al usuario si esta seguro de modificar ese alumno y le pregunta que dato desea modificar, dandole opcion de modificarlo
 * \param this El alumno a modificar
 * return retorna -1 en caso de error y 0 en caso de exito
 */
int Alumno_modificar(Alumno* this){

	int retorno = -1;
	char nombreAux[NOMBRE_LEN];
	char apellidoAux[NOMBRE_LEN];
	char edadAux[NOMBRE_LEN];
	char legajoAux[NOMBRE_LEN];
	char divisionAux[NOMBRE_LEN];
	char condicionAux[NOMBRE_LEN];

	int respuesta;
	printf("Desea modificar el siguiente alumno?\n");
	Alumno_imprimir(this);
	utn_getNumero(&respuesta, " 1.SI\n 2.NO", "opcion incorrecta", 1, 2, 3);
	if(respuesta == 1){
		utn_getNumero(&respuesta, "Que dato desea modificar?\n 1.Nombre\n 2.Apellido\n 3.Edad\n 4.Legajo\n 5.Division\n 6. Condicion\n ","Opcion Incorrecta", 1, 6, 3);
		switch(respuesta){
			case 1:
				utn_getString(nombreAux, NOMBRE_LEN, "Ingrese el nuevo nombre\n", "nombre invalido", 3);
				Alumno_setNombre(this, nombreAux);
				printf("\n Nombre cambiado exitosamente\n");
				retorno = 0;
				break;
			case 2:
				utn_getString(apellidoAux, NOMBRE_LEN, "Ingrese el nuevo apellido\n", "apellido invalido", 3);
				Alumno_setApellido(this, apellidoAux);
				printf("\n Apellido cambiado exitosamente\n");
				retorno = 0;
				break;
			case 3:
				utn_getString(edadAux, NOMBRE_LEN, "Ingrese la nueva edad\n", "edad invalida", 3);
				Alumno_setEdadTxt(this, edadAux);
				printf("\n Edad cambiada exitosamente\n");
				retorno = 0;
				break;
			case 4:
				utn_getString(legajoAux, NOMBRE_LEN, "Ingrese el legajo del alumno\n", "legajo invalido", 3);
				Alumno_setLegajo(this, legajoAux);
				printf("\n Legajo cambiado exitosamente\n");
				retorno = 0;
				break;
			case 5:
				utn_getString(divisionAux, NOMBRE_LEN, "Ingrese la division del alumno\n", "division invalida", 3);
				Alumno_setDivision(this, divisionAux);
				printf("\n Division del alumno cambiada exitosamente\n");
				retorno = 0;
				break;
			case 6:
				utn_getString(condicionAux,NOMBRE_LEN, "Ingrese la nueva condicion del alumno\n", "condicion invalida", 3);
				Alumno_setCondicion(this, condicionAux);
				printf("\n Condicion del alumno cambiada exitosamente\n");
				retorno = 0;
				break;
		}
	}

	return retorno;
}
/**
 * \brief Compara el apellido de dos alumnos y devuelve cual es el mayor
 * \param alumno1 Primer alumno a comparar el apellido
 * \param alumno2 segundo alumno a comparar el apellido
 * \return el mayor
 */
int Alumno_sortByApellido(void* alumno1, void* alumno2){
	int retorno;
	char apellidoAlumno1[NOMBRE_LEN];
	char apellidoAlumno2[NOMBRE_LEN];

	if(alumno1 != NULL && alumno2!= NULL){
		Alumno_getApellido(alumno1, apellidoAlumno1);
		Alumno_getApellido(alumno2, apellidoAlumno2);

		if(apellidoAlumno1 != NULL && apellidoAlumno2 != NULL){
			retorno = strcmp(apellidoAlumno1, apellidoAlumno2);
		}
	}

	return retorno;
}
//******************************************SETTERS AND GETTERS***************************************************

/**
 * \brief establece el id en int de un alumno
 * \param this Alumno a setearle el id
 * \param id Id que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setId(Alumno* this,int id){
	int retorno = -1;

	if(this != NULL && id>0 ){
		this->id= id;
		retorno =0;
	}

	return retorno;
}
/**
 * \brief obtiene el id en int de un Alumno
 * \param this Alumno a obtenerle el id en int
 * \param id puntero a la variable donde queremos guardar ese id
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getId(Alumno* this,int* id){
	int retorno = -1;

	if(this != NULL && id >= 0){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief establece el id en texto de un Alumno
 * \param this Alumno a setearle el id en texto
 * \param id Id que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setIdTxt(Alumno* this, char* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		if(esNumerica(id, 10)){
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}
/**
 * \brief obtiene el id en texto de un Alumno
 * \param this Alumno a obtenerle el id en texto
 * \param id puntero a la variable (De texto) donde queremos guardar ese id
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getIdTxt(Alumno* this, char* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		sprintf(id, "%d", this->id);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief establece el nombre de un Alumno
 * \param this Alumno a setearle el nombre
 * \param nombre nombre que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setNombre(Alumno* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		if(esNombre(nombre, NOMBRE_LEN)){
			strcpy(this->nombre, nombre);
			retorno = 0;
		}
	}

	return retorno;
}
/**
 * \brief obtiene el nombre en texto de un Alumno
 * \param this Alumno a obtenerle el nombre
 * \param nombre puntero a la variable (De texto) donde queremos guardar ese nombre
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getNombre(Alumno* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief establece el apellido de un Alumno
 * \param this Alumno a setearle el apellido
 * \param apellido Apellido que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setApellido(Alumno* this,char* apellido){
	int retorno = -1;

	if(this != NULL && apellido != NULL){
		if(esNombre(apellido, NOMBRE_LEN)){
			strcpy(this->apellido, apellido);
			retorno = 0;
		}
	}

	return retorno;
}
/**
 * \brief obtiene el apellido en texto de un Alumno
 * \param this Alumno a obtenerle el apellido
 * \param nombre puntero a la variable (De texto) donde queremos guardar ese apellido
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getApellido(Alumno* this,char* apellido){
	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief establece la edad en int de un Alumno
 * \param this Alumno a setearle la edad
 * \param edad Edad que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setEdad(Alumno* this,int edad){
	int retorno = -1;

	if(this != NULL && edad>0 ){
		this->edad= edad;
		retorno =0;
	}

	return retorno;
}
/**
 * \brief obtiene la edad en int de un Alumno
 * \param this Alumno a obtenerle la edad en int
 * \param edad puntero a la variable donde queremos guardar esa edad
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getEdad(Alumno* this,int* edad){
	int retorno = -1;

	if(this != NULL && edad >= 0){
		*edad = this->id;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief establece la edad en texto de un Alumno
 * \param this Alumno a setearle el edad en texto
 * \param edad Edad que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setEdadTxt(Alumno* this, char* edad){
	int retorno = -1;

	if(this != NULL && edad != NULL){
		if(esNumerica(edad, 10)){
			retorno = 0;
			this->edad = atoi(edad);
		}
	}
	return retorno;
}
/**
 * \brief obtiene la edad en texto de un Alumno
 * \param this Alumno a obtenerle la edad en texto
 * \param edad puntero a la variable (De texto) donde queremos guardar esa edad
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getEdadTxt(Alumno* this, char* edad){
	int retorno = -1;

	if(this != NULL && edad != NULL){
		sprintf(edad, "%d", this->edad);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief establece el legajo de un Alumno
 * \param this Alumno a setearle el legajo
 * \param legajo Legajo que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setLegajo(Alumno* this,char* legajo){
	int retorno = -1;

	if(this != NULL && legajo != NULL){

			strcpy(this->legajo, legajo);
			retorno = 0;

	}

	return retorno;
}
/**
 * \brief obtiene el legajo en texto de un Alumno
 * \param this Alumno a obtenerle el legajo
 * \param legajo puntero a la variable (De texto) donde queremos guardar ese legajo
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getLegajo(Alumno* this,char* legajo){
	int retorno = -1;

	if(this != NULL && legajo != NULL){
		strcpy(legajo, this->legajo);
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief establece la division de un Alumno
 * \param this Alumno a setearle la division
 * \param division Division que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setDivision(Alumno* this,char* division){
	int retorno = -1;

	if(this != NULL && division != NULL){

			strcpy(this->division, division);
			retorno = 0;

	}

	return retorno;
}
/**
 * \brief obtiene la division en texto de un Alumno
 * \param this Alumno a obtenerle la division
 * \param division puntero a la variable (De texto) donde queremos guardar la division
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getDivision(Alumno* this, char* division){
	int retorno = -1;

	if(this != NULL && division != NULL){
		strcpy(division, this->division);
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief establece la condicion de un Alumno
 * \param this Alumno a setearle la condicion
 * \param condicion Condicion que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_setCondicion(Alumno* this,char* condicion){
	int retorno = -1;

	if(this != NULL && condicion != NULL){
		if(esNombre(condicion, NOMBRE_LEN)){
			strcpy(this->condicion, condicion);
			retorno = 0;
		}
	}

	return retorno;
}
/**
 * \brief obtiene la condicion en texto de un Alumno
 * \param this Alumno a obtenerle la condicion
 * \param condicion puntero a la variable (De texto) donde queremos guardar la condicion
 * return -1 en caso de error y 0 en caso de exito
 */
int Alumno_getCondicion(Alumno* this,char* condicion){
	int retorno = -1;

	if(this != NULL && condicion != NULL){
		strcpy(condicion, this->condicion);
		retorno = 0;
	}

	return retorno;
}

//************************************************************************************************************************
/*
 * \brief Define si una cadena de texto es numerica
 * \param cadena cadena de texto a analizar
 * \param limite limite de la cadena
 * return -1 en caso de error y 0 en caso de exito
 */
static int esNumerica(char* cadena, int limite){

	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0){
		retorno = 1;
		for(i=0; i<limite && cadena[i] != '\0'; i++){
			if(i==0 &&  (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0'){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * \brief Define si una cadena de texto es un nombre
 * \param cadena cadena de texto a analizar
 * \param longitud limite de la cadena
 * return -1 en caso de error y 0 en caso de exito
 */
static int esNombre(char* cadena, int longitud){
	int i =0;
	int retorno = -1;

	if(cadena!= NULL && longitud >0){
		for(i = 0; cadena[i] != '\0' && i< longitud; i++){
			if((cadena[i]<'A' || cadena[i] > 'Z') && (cadena[i] <'a' || cadena[i] > 'z')){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
