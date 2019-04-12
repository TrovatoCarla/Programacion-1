#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
#include "misValid.h"

int getInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int *resultado)
{
    int auxiliar;
    int i;
    int retorno=-1;
        if(mensaje!=NULL &&
            mensajeError!=NULL &&
            maximo>=minimo &&
            reintentos>=0 &&
            resultado!=NULL)

            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%d",&auxiliar);
                if(isValidInt(auxiliar,maximo,minimo))
                {
                    *resultado=auxiliar;
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                }
            }


    return retorno;
}

int getFloat(char *mensaje,char *mensajeError,float maximo,float minimo,int reintentos,float *resultado)
{
    float auxiliar;
    int i;
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>=0 && resultado!=NULL)
        {
            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%f",&auxiliar);
                if(isValidFloat(auxiliar,maximo,minimo))
                {
                    *resultado=auxiliar;
                    retorno=0;
                    break;
                }
                else
                    printf("%s",mensajeError);
            }
        }
    return retorno;
}

int getChar(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{
    char buffer;
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>0 && resultado!=NULL)
        {
           do
           {
               printf("%s",mensaje);
               scanf("%c",&buffer);
               if(isValidChar(buffer,maximo,minimo))
               {
                   *resultado=buffer;
                   retorno=0;
                   break;
               }
               else
                printf("%s",mensajeError);
           }while(reintentos>=0);
        }
    return retorno;
}



