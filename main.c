#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir = 's';
    int opcion = 0;
    float x;
    float y;
    int flagA = 0; // Marca si alguna vez se cargo el 1er operando A
    int flagB = 0; // Marca si alguna vez se cargo el 2do operando B

    while(seguir == 's')
    {
        system("cls");

        printf("MENU DE OPCIONES\n");

        if(flagA == 0)
        {
            printf("1 - Ingresar 1er operando (A=X)\n");
        }
        else
        {
            printf("1 - Ingresar 1er operando (A=%f)\n", x);
        }

        if(flagB == 0)
        {
            printf("2 - Ingresar 2do operando (B=Y)\n");
        }
        else
        {
            printf("2 - Ingresar 2do operando (B=%f)\n", y);
        }

        printf("3 - Calcular la suma (A+B)\n");
        printf("4 - Calcular la resta (A-B)\n");
        printf("5 - Calcular la division (A/B)\n");
        printf("6 - Calcular la multiplicacion (A*B)\n");
        printf("7 - Calcular el factorial (A!)\n");
        printf("8 - Calcular todas las operaciones\n");
        printf("9 - Salir\n\n");

        printf("Indique una opcion:\n\n");
        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                x = validarOperando('A'); // La funcion scanf se repite hasta que se ingrese un numero
                flagA = 1;  // Marco que se cargo un valor en el 1er operando A
                break;

            case 2:
                y = validarOperando('B'); // La funcion scanf se repite hasta que se ingrese un numero
                flagB = 1;  // Marco que se cargo un valor en el 2do operando B
                break;

            case 3:
                if(operandosCargados(flagA, flagB) == 1)
                {
                    printf("A + B: %f\n", sumar(x, y));
                }
                break;

            case 4:
                if(operandosCargados(flagA, flagB) == 1)
                {
                    printf("A - B: %f\n", restar(x, y));
                }
                break;

            case 5:
                if(operandosCargados(flagA, flagB) == 1)
                {
                    printf("A / B: %f\n", dividir(x, y));
                }
                break;

            case 6:
                if(operandosCargados(flagA, flagB) == 1)
                {
                    printf("A * B: %f\n", multiplicar(x, y));
                }
                break;

            case 7:
                if(operandoCargado(flagA) == 1)
                {
                    printf("Factorial de A: %d\n", factorial(x));
                }
                break;

            case 8:
                if(operandosCargados(flagA, flagB) == 1)
                {
                    printf("A + B: %f\n", sumar(x, y));
                    printf("A - B: %f\n", restar(x, y));
                    printf("A / B: %f\n", dividir(x, y));
                    printf("A * B: %f\n", multiplicar(x, y));
                    printf("Factorial de A: %d\n\n", factorial(x));
                }
                break;

            case 9:
                seguir = 'n';
                break;
        }

        // Pausar únicamente cuando la la opción no es salir
        if(opcion != 9)
        {
            system("pause");
        }

    }

    return 0;
}
