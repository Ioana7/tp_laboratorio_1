#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float validarOperando(char operando)
{

    float numero;

    printf("Ingrese el valor de %c: ", operando);

    // Repito hasta que se ingrese un número
    while(scanf("%f", &numero) != 1)
    {
        printf("\nError: El valor ingreado no es un numero\n");
        printf("Ingrese nuevamente el valor de %c: ", operando);
        fflush(stdin);
    }

    return numero;

}


int operandosCargados(int flagA, int flagB)
{

    if (flagA == 1 && flagB == 1)
    {
        return 1;
    }
    else
    {
        if (flagA == 0)
        {
            printf("Error: Para realizar la operacion es necesario cargar el valor del 1er operando A\n");
        }
        if (flagB == 0)
        {
            printf("Error: Para realizar la operacion es necesario cargar el valor del 2do operando B\n");
        }

        return 0;
    }

}


int operandoCargado(int flagA)
{

    if (flagA == 1)
    {
        return 1;
    }
    else
    {
        printf("Error: Para realizar la operacion es necesario cargar el valor del 1er operando A\n");
        return 0;
    }

}


float sumar(float x, float y)
{
    float suma = 0;

    suma = x + y;

    return suma;
}


float restar(float x, float y)
{
    float resta = 0;

    resta = x - y;

    return resta;
}


float dividir(float x, float y)
{
    float division = 0;

    if(y == 0)
    {
        printf("ERROR!!No se puede dividir por 0. Ingrese el valor de B de nuevo!!\n");
    }
    else
    {
        division = x / y;
    }

    return division;
}


float multiplicar(float x, float y)
{
     float multiplicacion;

     multiplicacion = x * y;

     return multiplicacion;
}


int factorial(float x)
{
    int i;
    float factor = 1;

    if( x < 0)
    {
         printf("ERROR!!\nNo existe factorial de numero negativo!!Ingrese un nuevo valor de A positivo!\n");
    }
    else
    {
        for(i = 1; i <= x; ++i)
        {
            factor *= i;              // factorial = factorial*i;
        }

    }

    return factor;
}
