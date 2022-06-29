/*
 * ArrayPassenger.h
 *
 *  Created on: May 12, 2022
 *      Author: Juli
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define NOMBRE_LEN 51

struct{
	int id;
	char name[NOMBRE_LEN];
	char lastName[NOMBRE_LEN];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
	int statusFly;
}typedef Passenger;

int initPassengers(Passenger* list, int len);

int addPassanger(Passenger* pArray, int largo, Passenger auxPasajero);

int findPassengerById(Passenger* list, int len,int id);

int sortPassenger(Passenger* list, int leng, int order);

int modificarPassenger(Passenger* pasajeros, int len, int indexPosicion);

int removePassenger(Passenger* list, int len, int id);

int printPassengers(Passenger* list, int len);

void printPassenger(Passenger pasajero);

void mostrarMenuInformar(int *opcionElegidaCaseDos);

void calcularPromedio(Passenger* list, int len, float* totalPrecio, float* promedio);

void superaPromedio(Passenger* list, int len, int* superaPromedio, float* promedio);

int sortPassengersByCode(Passenger* list, int len, int order);

void cargaForzada(Passenger* list, int len, int* id);
#endif /* ARRAYPASSENGER_H_ */
