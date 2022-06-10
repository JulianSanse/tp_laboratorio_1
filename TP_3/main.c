#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	utn_getNumero(&option, "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
    	    							"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    	    							"3. Alta de pasajero\n"
    	    							"4. Modificar datos de pasajero\n"
    	    							"5. Baja de pasajero\n"
    	    							"6. Listar pasajeros\n"
    	    							"7. Ordenar pasajeros\n"
    	    							"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    	    							"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    	    							"10. Salir\n",
    									"opcion invalida", 1,10,3);
    	switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                break;
        }
    }while(option != 10);
    return 0;
}

