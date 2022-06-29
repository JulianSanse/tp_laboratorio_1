/*
 * funciones.c
 *
 *  Created on: May 12, 2022
 *      Author: Juli
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/*
 * \brief muestra el menu principal y pregunta que opcion elige el usuario
 * \paran opcionElegida Opcion que elige el usuario
 */
void mostrarMenu(int *opcionElegida){
		setbuf(stdout, NULL);

		utn_getNumero(opcionElegida,  "\n1. ALTAS\n"
					"2. MODIFICAR\n"
					"3. BAJA\n"
					"4. INFORMAR\n"
					"5. Carga forzada de datos\n"
					"6. Salir\n", "Opcion Incorrecta", 1, 6, 3);

}
/*
 * \brief muestra el menu caso dos y pregunta que opcion elige el usuario
 * \paran opcionElegidaCaseDos Opcion que elige el usuario
 */
void mostrarMenuCaseDos(int *opcionElegidaCaseDos){
	setbuf(stdout, NULL);

	utn_getNumero(opcionElegidaCaseDos, "\n1. Modificar Nombre\n"
				"2. Modificar Apellido\n"
				"3. Modificar precio\n"
				"4. Modificar codigo de vuelo\n"
				"5. Modificar tipo de pasajero\n"
				"6. Salir\n", "\nOpcion incorrecta", 1, 6,3);

}
/*
 * \brief muestra el menu informar y pregunta que opcion elige el usuario
 * \paran opcionElegidaCaseDos Opcion que elige el usuario
 */
void mostrarMenuInformar(int *opcionElegidaCaseDos){
	setbuf(stdout, NULL);

	utn_getNumero(opcionElegidaCaseDos, "\n1.Listar pasajeros ordenados alfabeticamente por apellido y tipo"
			"\n2.Total y promedio de los precios y cuantos pasajeros superan el precio promedio"
			"\n3.Listar pasajeros por codigo de vuelo y estado de vuelos Activo"
			"\n4.Salir\n", "\nOpcion incorrecta", 1, 4, 3);
}
/*
 * \brief Pregunta la id al usuario y devuelve dicho id
 * \param mensaje Mensaje que quiere mostrar
 * \return id
 */
int preguntarId(char mensaje[]){
	int id;

	printf("%s", mensaje);
	scanf("%d", &id);

	return id;
}


