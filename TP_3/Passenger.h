#ifndef PASSENGER_H_
#define PASSENGER_H_

#define NOMBRE_LEN 50
typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	float precio;
	char tipoPasajero[NOMBRE_LEN];
	char codigoVuelo[NOMBRE_LEN];
	char statusVuelo[NOMBRE_LEN];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* statusVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);
int Passenger_setIdTxt(Passenger* this, char* id);
int Passenger_getIdTxt(Passenger* this, char* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_setPrecioTxt(Passenger* this, char* precio);
int Passenger_getPrecioTxt(Passenger* this, char* precio);

int Passenger_setStatusVuelo(Passenger* this,char* statusVuelo);
int Passenger_getStatusVuelo(Passenger* this,char* statusVuelo);

int Passenger_imprimir(Passenger* this);
int Passenger_modificar(Passenger* this);
int Passenger_sortByName(Passenger* pasajero1, Passenger* pasajero2);


#endif /* PASSENGER_H_ */
