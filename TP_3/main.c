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
	int banderaGuardado =0;
	int cargoPasajero = 0;
    int option = 0;
    int proximoId = 0 ;
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	utn_getNumero(&option, "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
    	    							"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
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
                if(!controller_loadFromText("data.csv",listaPasajeros, &proximoId)){
                	printf("/nLista Cargada exitosamente/n");
                	cargoPasajero = 1;
                }else{
                	printf("error al cargar lista\n");
                }
                break;
            case 2:
            	if(!controller_loadFromBinary("data.bin" ,listaPasajeros)){
            		printf("/nLista Cargada exitosamente/n");
            		cargoPasajero = 1;
            	}
            	break;
            case 3:
            	if(!controller_addPassenger(listaPasajeros, &proximoId)){
            		printf("\nPasajero cargado correctamente!!\n");
            		cargoPasajero = 1;
            	}
            	break;
            case 4:
            	if(!controller_editPassenger(listaPasajeros)){
            		printf("\nPasajero modificado correctamente!!\n");
            	}
            	break;
            case 5:
            	if(!controller_removePassenger(listaPasajeros)){
            		printf("\nPasajero borrado correctamente!!\n");
            	}
            	break;
            case 6:
            	if(cargoPasajero == 1){
            		if(!controller_ListPassenger(listaPasajeros)){
            			printf("\nLista cargada correctamente\n");
            		 }
            	}else{
            		printf("\n Debes cargar un pasajero primero!!\n");
            	}

            	break;
            case 7:
            	if(!controller_sortPassenger( listaPasajeros)){
            		printf("Ordenado correctamente");
            	};
            	break;
            case 8:
            	if(!controller_saveAsText("data.csv" , listaPasajeros)){
            		printf("\nDatos guardados correctamente!!\n");
            	};
            	banderaGuardado =1;
            	break;
            case 9:
            	if(!controller_saveAsBinary("data.bin" , listaPasajeros)){
            		printf("\nDatos guardados correctamente!!\n");
            		banderaGuardado =1;
            	}
            	break;
            case 10:
            	if(banderaGuardado == 0){
            		printf("\nNo puedes salir del programa sin antes guardar!!\n");
            		utn_getNumero(&option, "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
            	    	    							"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
            	    	    							"3. Alta de pasajero\n"
            	    	    							"4. Modificar datos de pasajero\n"
            	    	    							"5. Baja de pasajero\n"
            	    	    							"6. Listar pasajeros\n"
            	    	    							"7. Ordenar pasajeros\n"
            	    	    							"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
            	    	    							"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
            	    	    							"10. Salir\n",
            	    									"opcion invalida", 1,10,3);
            	}else{
            		break;
            	}

        }
    }while(option != 10);
    return 0;
}

