#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayPassenger.h"


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

int addPassanger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFly){
	int retorno = -1;

	for(int i = 0; i < len; i++){
		if(list[i].isEmpty == 1 && list != NULL){
				list[i].id = id;
				strcpy ( list[i].name , name);
				strcpy ( list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy ( list[i].flycode, flycode);
				list[i].isEmpty = 0;
				list[i].statusFly= statusFly;

				retorno = 0;
			}
	}


	return retorno;
}
int findPassengerById(Passenger* list, int len,int id){

		for(int i = 0; i< len; i++){
			if(list[i].id == id){
				return i;
			}
		}
		return -1;
}

//int removePassenger(Passenger* list, int len, int id){
//	int retorno = -1;
//	if (id != -1){
//		for(int i = 0; i <2000; i++){
//			if (list[i].id == id){
//				list[i].id = NULL;
//				strcpy ( list[i].name , "");
//				strcpy ( list[i].lastName, "");
//				list[i].price = NULL;
//				list[i].typePassenger = NULL;
//				strcpy ( list[i].flycode, "");
//				list[i].statusFly= NULL;
//				list[i].isEmpty = 1;
//			}
//		}
//		retorno = 0;
//	}
//	return retorno;
//}

int sortPassenger(Passenger* list, int size, int order)
{
	Passenger auxiliar;
	int retorno = -1;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			switch(order)
			{
				case 1:
					if(list[i].typePassenger<list[j].typePassenger) //REEMPLAZAR TYPE PASSENGER POR CODE FLY Y LASTNAME POR ESTATUS FLY
					{
						auxiliar=list[i];
						list[i]=list[j];
						list[j]=auxiliar;
					}
					else
					{
						if((strcmp(list[i].lastName, list[j].lastName)>0) && (list[i].typePassenger==list[j].typePassenger))
						{
							auxiliar=list[i];
							list[i]=list[j];
							list[j]=auxiliar;
						}
					}
					retorno=0;
					break;
				case 2:
					if(list[i].typePassenger>list[j].typePassenger)
					{
						auxiliar=list[i];
						list[i]=list[j];
						list[j]=auxiliar;
					}
					else
					{
						if((strcmp(list[i].lastName, list[j].lastName)<0) && (list[i].typePassenger==list[j].typePassenger))
						{
							auxiliar=list[i];
							list[i]=list[j];
							list[j]=auxiliar;
						}
					}
					retorno=0;
					break;
				default:
					break;
			}

		}
	}

	return retorno;
}

void printPassenger(Passenger* list, int len){
	for(int i = 0; i< len; i++){
		if(list[i].isEmpty != 1){
			printf("\n Nombre del pasajero: %s"
				   "\n Apellido del pasajero %s"
				   "\n Precio del vuelo: %f"
				   "\n Codigo del vuelo: %s"
				   "\n Tipo de pasajero: %d"
				   "\n Estatus del vuelo: %d", list[i].name , list[i].lastName, list[i].price, list[i].flycode, list[i].typePassenger, list[i].statusFly );
		}
	}

}



