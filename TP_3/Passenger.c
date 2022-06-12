#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"

static int esNumerica(char* cadena, int limite);
static int esNombre(char* cadena, int longitud);
static int esFlotante(char* cadena, int limite);

/**
 *\brief Crea un lugar en memoria para un nuevo pasajero
 *return Retorna el espacio en memoria del nuevo pasajero
 */
Passenger* Passenger_new(){
	return (Passenger*) malloc(sizeof(Passenger));
}
/**
 * \brief Crea un lugar en memoria para un nuevo pasajero y le asigna sus parametros
 * \param idStr Id del pasajero en string
 * \param nombreStr Nombre del pasajero en string
 * \param apellidoStr Apellido del pasajero en string
 * \param precioStr Precio del vuel del pasajero en string
 * \param tipoPasajeroStr Tipo de pasajero en string
 * \param codigoVueloStr Codigo del video del pasajero en string
 * \param statusVueloStr Status del vuelo del pasajero en string
 * return devuelve el puntero al pasajero creado
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* statusVueloStr){
	Passenger* auxiliarPasajero= NULL;
	auxiliarPasajero = Passenger_new();
	if(auxiliarPasajero!= NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && statusVueloStr != NULL ){
		if(Passenger_setIdTxt(auxiliarPasajero, idStr) == -1 ||
		   Passenger_setNombre(auxiliarPasajero, nombreStr) == -1 ||
		   Passenger_setApellido(auxiliarPasajero, apellidoStr) == -1 ||
		   Passenger_setPrecioTxt(auxiliarPasajero, precioStr) == -1 ||
		   Passenger_setTipoPasajero(auxiliarPasajero, tipoPasajeroStr) == -1 ||
		   Passenger_setCodigoVuelo(auxiliarPasajero, codigoVueloStr) == -1 ||
		   Passenger_setStatusVuelo(auxiliarPasajero, statusVueloStr) == -1)
		{
			Passenger_delete(auxiliarPasajero);
			auxiliarPasajero= NULL;
			printf("\nSe devolvio un pasajero nulo\n");
		}
	}
	return auxiliarPasajero;
}
/**
 * \brief Libera el lugar en la memoria de un pasajero
 * \param this Pasajero a eliminar/ liberar memoria
 */
void Passenger_delete(Passenger* this){
	if(this != NULL){
		free(this);
	}
}

//****************************************************************************************************************************//

/**
 * \brief establece el id en int de un pasajero
 * \param this Pasajero a setearle el id
 * \param id Id que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setId(Passenger* this,int id){
	int retorno = -1;

	if(this != NULL && id>0 ){
		this->id= id;
		retorno =0;
	}

	return retorno;
}
/**
 * \brief establece el id en texto de un pasajero
 * \param this Pasajero a setearle el id en texto
 * \param id Id que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setIdTxt(Passenger* this, char* id){
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
 * \brief obtiene el id en int de un pasajero
 * \param this Pasajero a obtenerle el id en int
 * \param id puntero a la variable donde queremos guardar ese id
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getId(Passenger* this,int* id){
	int retorno = -1;

	if(this != NULL && id >= 0){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief obtiene el id en texto de un pasajero
 * \param this Pasajero a obtenerle el id en texto
 * \param id puntero a la variable (De texto) donde queremos guardar ese id
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getIdTxt(Passenger* this, char* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		sprintf(id, "%d", this->id);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief establece el nombre de un pasajero
 * \param this Pasajero a setearle el nombre
 * \param nombre nombre que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setNombre(Passenger* this,char* nombre){
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
 * \brief obtiene el nombre en texto de un pasajero
 * \param this Pasajero a obtenerle el nombre
 * \param nombre puntero a la variable (De texto) donde queremos guardar ese nombre
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief establece el apellido de un pasajero
 * \param this Pasajero a setearle el apellido
 * \param apellido Apellido que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setApellido(Passenger* this,char* apellido){
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
 * \brief obtiene el apellido en texto de un pasajero
 * \param this Pasajero a obtenerle el apellido
 * \param nombre puntero a la variable (De texto) donde queremos guardar ese apellido
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief establece el codigo de vuelo de un pasajero
 * \param this Pasajero a setearle el codigo de vuelo
 * \param codigoVuelo Codigo de vuelo que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
			strcpy(this->codigoVuelo, codigoVuelo);
			retorno = 0;
	}

	return retorno;
}
/**
 * \brief obtiene el codigo de vuelo en texto de un pasajero
 * \param this Pasajero a obtenerle el codigo de vuelo
 * \param codigoVuelo puntero a la variable (De texto) donde queremos guardar ese codigo de vuelo
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
/**
 * \brief establece el tipo de pasajero de un pasajero
 * \param this Pasajero a setearle el tipo de pasajero
 * \param tipoPasajero tipo de pasajero que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL){
			strcpy(this->tipoPasajero, tipoPasajero);
			retorno = 0;
	}

	return retorno;
}
/**
 * \brief obtiene el Tipo de Pasajero en texto de un pasajero
 * \param this Pasajero a obtenerle el tipo de pasajero
 * \param TipoPasajero puntero a la variable (De texto) donde queremos guardar ese Tipo de Pasajero
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL){
		strcpy(tipoPasajero, this->tipoPasajero);
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief establece el precio del vuelo de un pasajero
 * \param this Pasajero a setearle el tipo de precio
 * \param precio Precio que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setPrecio(Passenger* this,float precio){
	int retorno = -1;

	if(this != NULL && precio >= 0){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief establece el precio del vuelo en txt de un pasajero
 * \param this Pasajero a setearle el tipo de precio
 * \param precio Precio en txt que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setPrecioTxt(Passenger* this, char* precio){
	int retorno = -1;
	float auxiliarPrecio;
	if(this != NULL && precio != NULL){
		if(esFlotante(precio, 6)){
			auxiliarPrecio= atof(precio);
			if(auxiliarPrecio > 0){
				this->precio = auxiliarPrecio;
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief obtiene el precio en float de un pasajero
 * \param this Pasajero a obtenerle el precio
 * \param precio puntero a la variable float donde queremos guardar ese precio
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno = -1;

	if(this != NULL && precio >= 0){
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief obtiene el precio en texto de un pasajero
 * \param this Pasajero a obtenerle el precio
 * \param precio puntero a la variable texto donde queremos guardar ese precio
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getPrecioTxt(Passenger* this, char* precio){
	int retorno = -1;

	if(this != NULL && precio != NULL){
		sprintf(precio, "%f", this->precio);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief establece el status del vuelo de un pasajero
 * \param this Pasajero a setearle el status del vuelo
 * \param statusVuelo status del vuelo que le queremos setear
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_setStatusVuelo(Passenger* this,char* statusVuelo){
	int retorno = -1;

	if(this != NULL && statusVuelo != NULL){
			strcpy(this->statusVuelo, statusVuelo);
			retorno = 0;
	}

	return retorno;
}
/**
 * \brief obtiene el status del vuelo  de un pasajero
 * \param this Pasajero a obtenerle el status del vuelo
 * \param prestatusVuelo puntero a la variable texto donde queremos guardar ese status del vuelo
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_getStatusVuelo(Passenger* this,char* statusVuelo){
	int retorno = -1;

		if(this != NULL && statusVuelo != NULL){
			strcpy(statusVuelo, this->statusVuelo);
			retorno = 0;
		}

		return retorno;
}
//******************************************************************************************************************
/**
 * \brief imprime el pasajero que le pasemos
 * \param this pasajero a imprimir
 * return -1 en caso de error y 0 en caso de exito
 */
int Passenger_imprimir(Passenger* this){
	int retorno = -1;

	if(this != NULL){
		printf("ID: %d - NOMBRE: %s - APELLIDO: %s - PRECIO: %f - CODIGO DE VUELO: %s - TIPO DE PASAJERO: %s - STATUS EL VUELO: %s\n", this->id, this->nombre, this->apellido, this->precio, this->codigoVuelo, this->tipoPasajero, this->statusVuelo);
		retorno =0;
	}
	return retorno;
}
/**
 * \brief Pregunta al usuario si esta seguro de modificar ese pasajero y le pregunta que dato desea modificar, dandole opcion de modificarlo
 * \param this El pasajero a modificar
 * return retorna -1 en caso de error y 0 en caso de exito
 */
int Passenger_modificar(Passenger* this){

	int retorno = -1;
	char nombreAux[NOMBRE_LEN];
	char apellidoAux[NOMBRE_LEN];
	char precioAux[NOMBRE_LEN];
	char codigoVueloAux[NOMBRE_LEN];
	char tipoPasajeroAux[NOMBRE_LEN];
	char statusVueloAux[NOMBRE_LEN];

	int respuesta;
	printf("Desea modificar el siguiente pasajero?\n");
	Passenger_imprimir(this);
	utn_getNumero(&respuesta, " 1.SI\n 2.NO", "opcion incorrecta", 1, 2, 3);
	if(respuesta == 1){
		utn_getNumero(&respuesta, "Que dato desea modificar?\n 1.Nombre\n 2.Apellido\n 3.Precio\n 4.Codigo de vuelo\n 5.Tipo de pasajero\n 6. Status del vuelo\n ","Opcion Incorrecta", 1, 6, 3);
		switch(respuesta){
			case 1:
				utn_getString(nombreAux, NOMBRE_LEN, "Ingrese el nuevo nombre\n", "nombre invalido", 3);
				Passenger_setNombre(this, nombreAux);
				printf("\n Nombre cambiado exitosamente\n");
				retorno = 0;
				break;
			case 2:
				utn_getString(apellidoAux, NOMBRE_LEN, "Ingrese el nuevo apellido\n", "apellido invalido", 3);
				Passenger_setApellido(this, apellidoAux);
				printf("\n Apellido cambiado exitosamente\n");
				retorno = 0;
				break;
			case 3:
				utn_getString(precioAux, NOMBRE_LEN, "Ingrese el nuevo precio\n", "precio invalido", 3);
				Passenger_setPrecioTxt(this, precioAux);
				printf("\n Precio cambiado exitosamente\n");
				retorno = 0;
				break;
			case 4:
				utn_getString(codigoVueloAux, NOMBRE_LEN, "Ingrese el nuevo codigo del vuelo\n", "codigo de vuelo invalido", 3);
				Passenger_setCodigoVuelo(this, codigoVueloAux);
				printf("\n Codigo del vuelo cambiado exitosamente\n");
				retorno = 0;
				break;
			case 5:
				utn_getString(tipoPasajeroAux, NOMBRE_LEN, "Ingrese el nuevo tipo de pasajero\n", "tipo de pasajero invalido", 3);
				Passenger_setTipoPasajero(this, tipoPasajeroAux);
				printf("\n Tipo de pasajero cambiado exitosamente\n");
				retorno = 0;
				break;
			case 6:
				utn_getString(statusVueloAux,NOMBRE_LEN, "Ingrese el nuevo status del vuelo\n", "status invalido", 3);
				Passenger_setStatusVuelo(this, statusVueloAux);
				printf("\n Status de vuelo cambiado exitosamente\n");
				retorno = 0;
				break;
		}
	}

	return retorno;
}
/**
 * \brief Compara el nombre de dos pasajeros y devuelve cual es el mayor
 * \param pasajero1 Primer pasajero a comparar el nombre
 * \param pasajero2 segundo pasajero a comparar el nombre
 * \return el mayor
 */
int Passenger_sortByName(Passenger* pasajero1, Passenger* pasajero2){
	int retorno;
	char nombrePasajero1[NOMBRE_LEN];
	char nombrePasajero2[NOMBRE_LEN];

	if(pasajero1 != NULL && pasajero2!= NULL){
		Passenger_getNombre(pasajero1, nombrePasajero1);
		Passenger_getNombre(pasajero2, nombrePasajero2);

		if(nombrePasajero1 != NULL && nombrePasajero2 != NULL){
			retorno = strcmp(nombrePasajero1, nombrePasajero2);
		}
	}

	return retorno;
}
//**********************************************************************************************************************

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
/*
 * \brief Define si una cadena de texto es flotante
 * \param cadena cadena de texto a analizar
 * \param limite limite de la cadena
 * return -1 en caso de error y 0 en caso de exito
 */
static int esFlotante(char* cadena, int limite){

	int retorno = -1;
	int i;
	int contadorPuntos =0;

	if(cadena != NULL && limite > 0){
		retorno = 1;
		for(i=0; i<limite && cadena[i] != '\0'; i++){
			if(i==0 &&  (cadena[i] == '+' || cadena[i] == '-')){
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0'){
				if(cadena[i] == '.' && contadorPuntos == 0){
					contadorPuntos++;
				}else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
