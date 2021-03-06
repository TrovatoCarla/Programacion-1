#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#include <string.h>
#define MAX_ID 10
#define MAX_CARACTER 50

typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[250];
    float precio;
    char tipo [5];
}Pantalla;


int initArrayPantalla(Pantalla* pantallas,int limite);
void muestraArrayPantalla(Pantalla* pantallas,int limite);
int buscaVacio(Pantalla* pantallas,int limite,int* posicionVacia);
int buscarId(Pantalla* pantallas,int limite,char* msj,char* msjError,int maximo,int minimo,int reintentos,int* idEncontrado);
int getInt(char *message, char *errorMessage, int minimum, int maximum, int retries, int *input);
int isValidInt(int number, int minimum, int maximum);
int isValidNombre(char *cadena);
int isValidFloat(float number, float minimum, float maximum);
int getName (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getString (char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getFloat(char *message, char *errorMessage, float minimum, float maximum, int retries, float *input);
int pan_alta(Pantalla* pantallas,char* msjError,int limite,int posicionLibre);
int pan_baja(Pantalla* pantallas,char limite);
int pan_modificacion(Pantalla* pantallas,char limite);


#endif // PANTALLA_H_INCLUDED
