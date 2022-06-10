#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

Passenger* Passenger_new(){
	return (Passenger*) malloc(sizeof(Passenger));
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr){

}

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;

}Passenger;

Alumno* alumno_newParametrosTxt(char* nombre, char* altura, char* id){
	Alumno* auxiliarP = NULL;

	auxiliarP= alumno_new();
	if(auxiliarP != NULL && nombre != NULL && id !=NULL){
		if(alumno_setNombre(auxiliarP, nombre) == -1 ||
		   alumno_setIdTxt(auxiliarP, id) == -1||
		   alumno_setAlturaTxt(auxiliarP, altura) == -1)
		{
			alumno_delete(auxiliarP);
			auxiliarP = NULL;
		}
	}
	return auxiliarP;
}
