#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct{
int id;
char marca[20];
char tipo[20];
float rodado;
}Bicicleta;

int calcularIIBB(float totalFactura, float* x);
int quitarVocales(char cadena[]);
int ordenar(Bicicleta* lista);

int main()
{
    float impuesto;

    calcularIIBB(1000, &impuesto);
    printf("\n\n");

    quitarVocales("democracia");
    printf("\n\n");

    Bicicleta lista[TAM] = {
    {1, "sarasa", "tipoA", 22,5},
    {2, "aaaaa", "btipo", 21,5},
    {3, "marca", "ctipo", 25,5}
    };

    ordenar(lista);
    for(int i = 0 ; i < TAM; i++)
    {
        printf("%d %s %s %f\n", lista[i].id, lista[i].marca, lista[i].tipo, lista[i].rodado);
    }
    return 0;
}


/*1. Crear una función llamada calcularIIBB que reciba como primer parámetro el total
 factura y como segundo parámetro la dirección de memoria de una variable donde debe
 escribir el valor del impuesto(IIBB es 3.5%). La función retorna 1 si salió todo bien o 0 si hubo algún error.
 Realizar la llamada desde main.*/

 int calcularIIBB(float totalFactura, float* x)
 {
     int ret = 0;
     int porcentaje;
     if(x != NULL)
     {
        *x = 3.5;
        porcentaje = *x * totalFactura / 100;
        totalFactura = totalFactura + porcentaje;
        printf("total: %.2f", totalFactura);
        ret = 1;
     }

     return ret;
 }

 /*2. Crear una función que se llame quitarVocales que reciba una cadena de caracteres
 como parámetro  y su responsabilidad es eliminar los caracteres
que sean vocales de la misma. Ejemplo si le pasamos "democracia" la deja como "dmcrc"*/

int quitarVocales(char cadena[])
{
    int ret = 0;
    int tam;
    if(cadena != NULL)
    {
         tam = strlen(cadena);
         for(int i = 0; i < tam; i++)
         {
             if(!(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u'))
             {
                 printf("%c", cadena[i]);
                ret = 1;
             }
         }
    }
    return ret;
}

/*Dada la estructura Bicicleta(id, marca(cadena), tipo(cadena), rodado(float)) generar una función que permita
ordenar un array de dicha estructura por marca descendente Ante igualdad de marca deberá ordenarse por
 precio ascendente. Hardcodear datos y mostrarlos desde el main.*/
int ordenar(Bicicleta* lista)
{
    int ret = 0;
    Bicicleta aux;

    if(lista != NULL && TAM > 0)
    {
        for(int i = 0; i < TAM - 1; i++)
        {
            for(int j = i + 1; j < TAM; j++)
            {
                if(strcmp(lista[i].marca, lista[j].marca) < 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
        ret = 1;
    }
    return ret;
}
