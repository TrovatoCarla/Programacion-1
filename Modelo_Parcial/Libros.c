#ifndef LIBROS_C_INCLUDED
#define LIBROS_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "Autores.h"
#include "funcionesUTN.h"
#include "misValid.h"
#include "Libros.h"

int lib_initArray(Libros* libro,int limite)
{
    int i;
    int retorno;
    for(i=0;i<limite;i++)
    {
        libro[i].isEmpty=VACIO;
        retorno=0;
    }
    return retorno;
}

int lib_alta(Libros* libro,int limite,int posicionLibre,int id)
{
    int retorno;

    if(lib_buscaPosicionLibre(libro,MAX_ARRAY,&posicionLibre)==0)
    {
        if(getString("\nIngrese titulo del libro: ","\nError,titulo invalido",MAXIMO_CARACTER,2,3,libro[posicionLibre].titulo)==0)
        {
            if(getInt("\nIngrese codigo del autor: ","\nError,codigo invalido",MAXIMO_CARACTER,2,3,&libro[posicionLibre].codigoAutor)==0)
            {
                libro[posicionLibre].isEmpty=HABILITADO;
                libro[posicionLibre].codigoLibro=id;
                retorno=0;
            }
        }
    }
    return retorno;
}

int lib_buscaPorId(Libros* libro,int limite,int idBusqueda,int* indice)///Agrego idBusqueda e indice
{
    int i;
    int retorno=-1;
    ///Saco bufferID y lo reemplazo por idBusqueda
    ///Quito el getInt de aca y lo agrego al main.

    for(i=0;i<limite;i++)
    {
        if(idBusqueda==libro[i].codigoAutor)
        {
            *indice=i;///Cambio idEncontrado por indice
            retorno=0;
            break;
        }
    }

    return retorno;
}

int lib_buscaPosicionLibre(Libros* libro,int len,int* posicionLibre)
{
    int i;
    int retorno;

    for(i=0;i<len;i++)
    {
        if(libro[i].isEmpty==VACIO)
        {
            *posicionLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int lib_modificar(Libros* libro,int limite,int idAmodificar)
{
    int retorno;
    char seguir='s';
    int opcion;
    char auxTitulo[MAXIMO_CARACTER];
    int auxCodigoAutor=-1;
    int indiceAmodificar;///Agrego indiceAmodificar


    if(lib_buscaPorId(libro,MAX_ARRAY,idAmodificar,&indiceAmodificar)==0)///cambio puntero de idMofic aca y puso indiceAmodif
    {
        while(seguir=='s')
        {
            printf("\nMENU DE MOFICICACIONES: \n 1-Titulo \n 2-Codigo de autor\n 3-Salir\n");
            do
            {

            }while(getInt("\nIngrese una opcion: ","\nError,opcion invalida",3,1,2,&opcion));

            switch(opcion)
            {
                case 1:
                    if(getString("\nIngrese titulo: ","\nTitulo invalido",MAXIMO_CARACTER,2,3,auxTitulo)==0)
                    {
                        strncpy(libro[indiceAmodificar].titulo,auxTitulo,MAXIMO_CARACTER);
                        printf("\nTITULO MODIFICADO CORRECTAMENTE\n");
                    }
                break;
                case 2:
                    if(getInt("\nIngrese codigo de autor: ","\nCodigo invalido\n",100,0,3,&auxCodigoAutor)==0)
                    {
                        libro[indiceAmodificar].codigoAutor=auxCodigoAutor;
                        printf("\nCODIGO DE AUTOR MODIFICADO CORRECTAMENTE");
                    }
                    break;
                case 3:
                    seguir='n';
                    retorno=0;
            }
        }
    }
    return retorno;
}

int lib_bajaLibro(Libros* libro,int limite,int idBaja)
{
    int retorno=-1;
    int indice;///agrego variable

    if(lib_buscaPorId(libro,limite,idBaja,&indice)==0)///y lo utiliza de puntero
    {
        printf(" estoy dando de baja aaaa %d\n",libro[indice].codigoLibro);
        printf(" el estado anterior es %d \n",libro[indice].isEmpty);
        libro[indice].isEmpty=INHABILITADO;
        printf(" el nuevo es %d \n",libro[indice].isEmpty);
        retorno=0;
    }
    else
    {
        printf("\n ID NO ENCONTRADO");
    }
    lib_muestraLibros(libro,limite);
return retorno;
}

int lib_muestraLibros(Libros* libro,int limite)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++)
    {
        if(libro[i].isEmpty==HABILITADO)
        {
            __fpurge(stdin);
            printf("\nPosicion %d:  Codigo Libro: %d",i,libro[i].codigoLibro);
            printf("\n             Titulo: %s",libro[i].titulo);
            printf("\n             Codigo Autor: %d",libro[i].codigoAutor);
            printf("\n             IsEmpty: %d",libro[i].isEmpty);
            retorno=0;
        }
    }
    return retorno;
}
#endif // LIBROS_C_INCLUDED