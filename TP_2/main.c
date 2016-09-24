#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;

    EPersona listaPersonas[20];

    int posicionLibre = -1;
    int posicionPersonaBuscada = -1;

    // Inicializo el array con Personas que tienen estado == LIBRE == 0
    inicializarListaPersonas(listaPersonas);

    while(seguir == 's')
    {
        system("cls");

        printf("MENU DE OPCIONES\n");
        printf("1 - Agregar persona\n");
        printf("2 - Borrar persona\n");
        printf("3 - Imprimir lista ordenada por nombre\n");
        printf("4 - Imprimir grafico de edades\n");
        printf("5 - Salir\n");

        printf("\nIndique una opcion: ");

        // Valida que la opcion ingresada sea un numero int
        opcion = getOpcionMenu();

        switch(opcion)
        {
            case 1:
                // Verifico si hay lugar libre
                posicionLibre = obtenerEspacioLibre(listaPersonas);

                if (posicionLibre != -1)
                {
                    // Si hay lugar libre, agrego los datos de la nueva Persona en dicha posicion
                    agregarNuevaPersona(listaPersonas, posicionLibre);
                }
                else
                {
                    printf("No es posible agregar mas personas. Todos los lugares estan ocupados\n");
                }

                break;

            case 2:
                // Busco a la Persona segun el DNI ingresado por el usuario
                printf("\nA continuacion se le requerira el DNI de la persona que desea borrar\n");
                posicionPersonaBuscada = buscarPorDni(listaPersonas, getDNI());

                if(posicionPersonaBuscada != -1)
                {
                    // Si encontro a la Persona, la borro
                    borrarPersona(listaPersonas, posicionPersonaBuscada);
                }
                else
                {
                    printf("No existe ninguna Persona dentro de la lista con dicho DNI\n");

                }

                break;

            case 3:
                // Ordeno la lista de Personas por nombre y la imprimo ordenada
                ordenarListaPorNombre(listaPersonas);
                imprimirLista(listaPersonas);
                break;

            case 4:
                imprimirGrafico(listaPersonas);
                break;

            case 5:
                seguir = 'n';
                break;

            default:
                // Opcion para los numeros que no sean {1, 2, 3, 4, 5}
                printf("ERROR: el valor ingresado no es una opcion valida. Intentelo nuevamente.\n");
        }

        // Pausar únicamente cuando la la opción no es Salir
        if (opcion != 5) {
            system("pause");
        }

    }

    return 0;
}
