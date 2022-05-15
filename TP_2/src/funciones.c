/*
 * funciones.c
 *
 *  Created on: May 12, 2022
 *      Author: Juli
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarMenu(int *opcionElegida){
		setbuf(stdout, NULL);

		printf( "\n1. ALTAS\n"
					"2. MODIFICAR\n"
					"3. BAJA\n"
					"4. INFORMAR\n"
					"5. Carga forzada de datos\n"
					"6. Salir\n");
		printf("\n Ingrese una opcion: ");
		scanf("%d", opcionElegida);

}

void mostrarMenuCaseDos(int *opcionElegidaCaseDos){
	setbuf(stdout, NULL);

	printf( "\n1. Modificar Nombre\n"
				"2. Modificar Apellido\n"
				"3. Modificar precio\n"
				"4. Modificar tipo de pasajero\n"
				"5. Modificar codigo de vuelo\n"
				"6. Salir\n");
	printf("\n Ingrese una opcion: ");
	scanf("%d", opcionElegidaCaseDos);

}

void preguntarChar(char charArray[], char text[]){

	printf("%s", text);
	scanf("%s", charArray);
	fflush(stdin);
}

void preguntarFloat(float *price, char text[]){
	printf("%s", text);
	scanf("%f", price);
	fflush(stdin);
}

void preguntarInteger(int *integer, char text[]){
	printf("%s", text);
	scanf("%d", integer);
	fflush(stdin);
}

int preguntarId(char mensaje[]){
	int id;

	printf("%s", mensaje);
	scanf("%d", &id);

	return id;
}

//float promedioVuelos(Passenger* list, int len, float *total){
//	int contador = 0;
//	float promedio;
//
//	for(int i=0; i<len; i++){
//		if(list[i].isEmpty != 1){
//			total = total + list[i].price;
//			contador++;
//		}
//	}
//
//	promedio = total/ contador;
//
//	return promedio;
//}


