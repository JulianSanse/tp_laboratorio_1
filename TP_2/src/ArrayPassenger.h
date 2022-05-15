/*
 * ArrayPassenger.h
 *
 *  Created on: May 12, 2022
 *      Author: Juli
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
	int statusFly;
}typedef Passenger;

int initPassengers(Passenger* list, int len);

int addPassanger(Passenger* list, int leng, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFly);

int findPassengerById(Passenger* list, int len,int id);

int sortPassenger(Passenger* list, int leng, int order);

// removePassenger(Passenger* list, int len, int id);

void printPassenger(Passenger* list, int len);


#endif /* ARRAYPASSENGER_H_ */
