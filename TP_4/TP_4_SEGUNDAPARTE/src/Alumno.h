#ifndef ALUMNO_H_
#define ALUMNO_H_

#define NOMBRE_LEN 50

typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	int edad;
	char legajo[NOMBRE_LEN];
	char division[NOMBRE_LEN];
	char condicion[NOMBRE_LEN];
}Alumno;

Alumno* Alumno_new();
Alumno* Alumno_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* edadStr,char* legajoStr, char* divisionStr, char* condicionStr);
void Alumno_delete(Alumno* this);

int Alumno_setId(Alumno* this,int id);
int Alumno_getId(Alumno* this,int* id);
int Alumno_setIdTxt(Alumno* this, char* id);
int Alumno_getIdTxt(Alumno* this, char* id);

int Alumno_setNombre(Alumno* this,char* nombre);
int Alumno_getNombre(Alumno* this,char* nombre);

int Alumno_setApellido(Alumno* this,char* apellido);
int Alumno_getApellido(Alumno* this,char* apellido);

int Alumno_setEdad(Alumno* this,int edad);
int Alumno_getEdad(Alumno* this,int* edad);
int Alumno_setEdadTxt(Alumno* this, char* edad);
int Alumno_getEdadTxt(Alumno* this, char* edad);


int Alumno_setLegajo(Alumno* this,char* legajo);
int Alumno_getLegajo(Alumno* this,char* legajo);

int Alumno_setDivision(Alumno* this,char* division);
int Alumno_getDivision(Alumno* this, char* division);


int Alumno_setCondicion(Alumno* this,char* condicion);
int Alumno_getCondicion(Alumno* this,char* condicion);

int Alumno_imprimir(Alumno* this);
int Alumno_modificar(Alumno* this);
int Alumno_sortByApellido(void* alumno1, void* alumno2);



#endif /* ALUMNO_H_ */
