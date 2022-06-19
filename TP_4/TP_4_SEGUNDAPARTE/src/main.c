/****************************************************
    Menu:
     1. Cargar los datos de los alumno desde el archivo data.csv (modo texto).
     2. Alta de alumno
     4. Modificar datos de alumno
     5. Baja de alumno
     6. Listar alumnos
     7. Ordenar alumnos por Apellido
     8. Guardar los datos de los alumnos en el archivo data.csv (modo texto).
    10. Salir
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Alumno.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);
	int option = 0;
	int proximoId = 0 ;
	int cargoAlumno = 0;
	int banderaGuardado =0;
	int cargoArchivo = 0;
	int idEncontrado;
	LinkedList* listaAlumnos = ll_newLinkedList();

	do{
		utn_getNumero(&option, "\n1. Cargar los datos de los alumnos desde el archivo data.csv (modo texto)\n"
		    	    							"2. Alta de alumno\n"
		    	    							"3. Modificar datos de alumno\n"
		    	    							"4. Baja de alumno\n"
		    	    							"5. Listar alumnos\n"
		    	    							"6. Ordenar alumnos por apellido\n"
		    	    							"7. Guardar los datos de los alumnos en el archivo data.csv (modo texto).\n"
		    	    							"8. Guardar los datos de los alumnos en el archivo data.csv (modo binario).\n"
		    	    							"9. Eliminar todos los elemntos de la lista\n"
												"10.Buscar Id de alumno por legajo\n"
												"11. Salir\n",
												"opcion invalida", 1,10,3);

		switch(option){
			case 1:
			    if(!controller_loadFromText("data.csv",listaAlumnos, &proximoId)){
			    	printf("\nLista Cargada exitosamente\n");
			        cargoAlumno = 1;
			        cargoArchivo = 1;
			    }else{
			    	printf("error al cargar lista\n");
			    }
				break;
			case 2:
				if(cargoArchivo){
					if(!controller_addAlumno(listaAlumnos, &proximoId)){
						printf("\n Alumno cargado correctamente!!\n");
						cargoAlumno= 1;
					}else{
						printf("\nError al cargar el alumno\n");
					}
				}else{
					printf("\n Debe cargar el archivo primero!!\n");
				}

				break;
			case 3:
				if(!controller_editAlumno(listaAlumnos)){
					printf("\n Alumno modificado correctamente");
				}else{
					printf("\n Error al modificar el alumno\n");
				}
				break;
			case 4:
				if(!controller_removeAlumno(listaAlumnos)){
					printf("\n Alumno eliminado correctamente!\n");
				}else{
					printf("\n Error al eliminar el alumno!\n");
				}
				break;
			case 5:
				if(cargoAlumno){
					controller_ListAlumno(listaAlumnos);
				}else{
					printf("\n Debes cargar un alumno primero!!\n");
				}
				break;
			  case 6:
			     if(!controller_sortAlumnos(listaAlumnos)){
			         printf("\n Lista ordenada correctamente!\n");
			     }else{
			    	 printf("\n Error al ordenar la lista!!\n");
			     }
			     break;
			  case 7:
				  if(!controller_saveAsText("data.csv", listaAlumnos)){
					  printf("\n Alumnos guardados en el archivo de texto correctamente\n");
					  banderaGuardado =1;
				  }else{
					  printf("\n Error al guardar los alumnos en el archivo de texto \n");
				  }
				break;
			  case 8:
				  if(!controller_saveAsBinary("data.bin", listaAlumnos)){
					  printf("\n Alumnos guardados en el archivo binario correctamente\n");
					  banderaGuardado =1;
				  }else{
					  printf("\n Error al guardar los alumnos en el archivo binario\n");
				  }
				  break;
			  case 9:
				  if(controller_deleteAlumnos(listaAlumnos)){
					  printf("Lista borrada correctamente");
				  }else{
					  break;
				  }
				  break;
			  case 10:
				  idEncontrado = controller_buscarAlumno(listaAlumnos);
				  if(idEncontrado >= 0){
					  printf("\nEl id de ese alumno es %d\n", idEncontrado);
				  }else{
					  printf("\nNo hay un alumno con ese legajo\n");
				  }
				  break;
			  case 11:
				  if(banderaGuardado){
					  break;
				  }else{
					  printf("\nDebes guardar el archivo antes de salir!\n");
					  utn_getNumero(&option, "\n1. Cargar los datos de los alumnos desde el archivo data.csv (modo texto)\n"
					  		    	    							"2. Alta de alumno\n"
					  		    	    							"3. Modificar datos de alumno\n"
					  		    	    							"4. Baja de alumno\n"
					  		    	    							"5. Listar alumnos\n"
					  		    	    							"6. Ordenar alumnos por apellido\n"
					  		    	    							"7. Guardar los datos de los alumnos en el archivo data.csv (modo texto).\n"
					  		    	    							"8. Guardar los datos de los alumnos en el archivo data.csv (modo binario).\n"
					  		    	    							"9. Hacer una copia de la lista"
							  	  	  	  	  	  	  	  	  	  	"10. Salir\n",
					  												"opcion invalida", 1,10,3);
				  }
				  break;
		}
	}while(option != 11);
	return EXIT_SUCCESS;
}
