#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListAlumnos, int* proximoId);
int controller_ListAlumno(LinkedList* pArrayListAlumnos);
int controller_addAlumno(LinkedList* pArrayListAlumno, int *proximoId);
int controller_editAlumno(LinkedList* pArrayListAlumno);
int controller_removeAlumno(LinkedList* pArrayListAlumno);
int controller_sortAlumnos(LinkedList* pArrayListAlumno);
int controller_saveAsText(char* path , LinkedList* pArrayListAlumno);
int controller_saveAsBinary(char* path , LinkedList* pArrayListAlumno);
int controller_deleteAlumnos(LinkedList* pArrayListAlumno);
int controller_buscarAlumno(LinkedList* pArraListAlumno);
#endif /* CONTROLLER_H_ */
