#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void putPersona(EPersona lista[], int posicion, char nombre[50], int dni, int edad, int estado)
{
    // Copio el nombre, el dni y la edad en la Persona que esta en la posicion que se pasa como parametro
    // y cambio el estado de la posicion
    strcpy(lista[posicion].nombre, nombre);
    lista[posicion].dni = dni;
    lista[posicion].edad = edad;
    lista[posicion].estado = estado; // LIBRE == 0 (macro)
}

void inicializarListaPersonas(EPersona lista[])
{
    int i;

    // Inicializa cada Persona del Array con estado == LIBRE
    for (i = 0; i < 20; i++)
    {
        // lista, posicion, nombre, dni, edad, estado
        putPersona(lista, i, "", 0, 0, LIBRE);
    }
}

int getOpcionMenu()
{
    int opcionMenu = 0;
    int flagOpcionValida = scanf(" %d", &opcionMenu);

    // Mientras que la opcion ingresada no sea un numero int, requerir otro valor
    while(flagOpcionValida != 1)
    {
        fflush(stdin);
        printf("ERROR: Indique una opcion valida: ");
        flagOpcionValida = scanf(" %d", &opcionMenu);
    };

    fflush(stdin);

    return opcionMenu;
}

int obtenerEspacioLibre(EPersona lista[])
{
    int i;

    for(i = 0; i < 20; i++)
    {
        if (lista[i].estado == LIBRE)   // LIBRE == 0
        {
            return i;
        }
    }

    // Si no hay lugares libres, retorno -1
    return -1;
}

int getDNI()
{
    int dni = 0;
    int flagDNIValido = 0;

    // Ingreso el DNI de la Persona
    printf("Ingrese el numero de DNI (sin puntos): ");

    flagDNIValido = scanf(" %d", &dni);

    // Valida que el DNI sea un numero int
    // y que sea un DNI valido (entre 00.000.001 y 99.999.999)
    while (flagDNIValido != 1  || dni < 1 || dni > 99999999)
    {
        fflush(stdin);

        if(flagDNIValido == 1 && dni < 1)
        {
            printf("ERROR: El numero de DNI debe ser mayor o igual que 1 (00.000.001)\n");
        }
        else if(flagDNIValido == 1 && dni > 99999999)
        {
            printf("ERROR: El numero de DNI debe ser menor o igual que 99999999 (99.999.999)\n");
        }

        printf("ERROR: Ingrese un numero de DNI valido: ");
        flagDNIValido = scanf(" %d", &dni);
    }

    fflush(stdin);

    return dni;
}

int getEdad()
{
    int edad = 0;
    int flagEdadValida = 0;

    // Ingreso la edad la Persona
    printf("Ingrese la edad: ");

    flagEdadValida = scanf(" %d", &edad);

    // Valida que la edad sea un numero int
    // y que sea positivo y menor o igual que 200 (años)
    while (flagEdadValida != 1 || edad < 0 || edad > 200)
    {
        fflush(stdin);

        if(flagEdadValida == 1 && edad < 0)
        {
            printf("ERROR: La edad debe ser un numero mayor o igual a 0\n");
        }
        else if(flagEdadValida == 1 && edad > 200)
        {
            printf("ERROR: La edad debe ser un numero menor o igual a 200\n");
        }

        printf("ERROR: Ingrese una edad valida: ");
        flagEdadValida = scanf(" %d", &edad);
    }

    fflush(stdin);

    return edad;
}

int validarNombre(char nombre[])
{
    const char patron[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHYJKLMNOPQRSTUVWXYZ";

    if (nombre[0] == '\n')
    {
        printf("ERROR: El nombre no puede ser vacio.\n");
        return -1;
    }
    else if (strchr(nombre, '\n') == NULL)
    {
        printf("ERROR: El nombre no puede tener mas de 50 caracteres (49 letras + el \\0).\n");
        return -2;
    }
    else if (strchr(nombre, ' ') != NULL)
    {
        printf("ERROR: El nombre no puede contener espacios en blanco.\n");
        return -3;
    }
    else if (nombre[strspn(nombre, patron)] != '\n') // MAGIA!!! Con strspn(nombre, patron) obtengo la primer posicion que no contenga el patron
    {
        printf("ERROR: El nombre solo puede contener caracteres que sean letras (salvo la enie).\n");
        return -4;
    }
    else
    {
        return 1;
    }
}

void getNombre(char nombre[])
{
    // Un caracter mas porque con fgets, el string leido termina en '\n\0', y al eliminar el '\n'
    // me quedan justo 49 caracteres mas el '\0'
    char nombreAux[51];

    // Ingreso el nombre de la Persona
    printf("\nIngrese el nombre: ");

    while(fgets(nombreAux, sizeof(nombreAux), stdin) == NULL || validarNombre(nombreAux) < 0) {
        fflush(stdin);
        printf("ERROR: Ingrese un nombre valido: ");
    }

    fflush(stdin);

    // MAGIA!!! Elimino el \n del string que viene del fgets
    nombreAux[strcspn(nombreAux, "\n")] = 0;

    // Copio el nombre definitivo y corregido al parametro pasado en la llamada a la funcion
    strcpy(nombre, nombreAux);
}

void agregarNuevaPersona(EPersona lista[], int posicionLibre)
{
    char nombre[50];

    printf("\nA continuacion se le requeriran los datos de la nueva persona\n");

    getNombre(nombre);

    // La nueva Persona pasa a ocupar un espacio que estaba libre
    putPersona(lista, posicionLibre, nombre, getDNI(), getEdad(), OCUPADO);

    printf("\nSe ha agregado exitosamente a la nueva persona\n");

}

int buscarPorDni(EPersona lista[], int dni)
{
    int i;

    for(i = 0; i < 20; i++)
    {
        if(lista[i].dni == dni)
        {
            printf("El DNI %d coincide con la persona de la posicion %d.\n", dni, i);
            printf("A continuacion se borraran los datos de %s\n", lista[i].nombre);
            return i;
        }
    }

    // Si no encuentro dicho dni en la lista, retorno -1
    return -1;
}

void borrarPersona(EPersona lista[], int posicion)
{
    // Reseteo los datos de la Persona en la posicion dada
    // especialmente el estado, que pasa a estar LIBRE

    // lista, posicion, nombre, dni, edad, estado
    putPersona(lista, posicion, "", 0, 0, LIBRE);
}

void ordenarListaPorNombre(EPersona lista[])
{
    int i;
    int j = 0;
    int flagComparacion = 0;
    EPersona aux;

    // Ordenamiento por Burbujeo (BubbleSort) segun el nombre de la Persona en forma ascendente
    for(i = 0; i < 20; i++)
    {
        for(j = i+1; j < 21; j++)
        {
            flagComparacion = strcmp(lista[i].nombre, lista[j].nombre);

            if(flagComparacion > 0)
            {
                // El nombre de la posicion j deberia ir antes que el nombre de la posicion i
                // Entonces hay que intercambiar a estas Personas
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

}

void imprimirLista(EPersona lista[])
{
    int i;

    // Imprimir cabeceras
    printf("                      NOMBRE                        ");
    printf("  DNI     ");
    printf("EDAD  ");
    printf("ESTADO\n");
    printf("__________________________________________________  ");
    printf("________  ");
    printf("____  ");
    printf("______\n");

    for(i = 0; i < 20; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            printf("%-50s  %08d  %4d  %3d\n", lista[i].nombre, lista[i].dni, lista[i].edad, lista[i].estado);
        }
    }

}

void imprimirGrafico(EPersona lista[])
{
    int i;
    int j;
    int personasMenor18 = 0;
    int personas19a35 = 0;
    int personasMayor35 = 0;
    int maxCant = 0;

    // Obtengo las cantidades de cada rango
    for(i = 0; i < 20; i++)
    {
       if(lista[i].estado == 1 && lista[i].edad > 35)
       {
           personasMayor35++;
       }
       if(lista[i].estado == 1 && lista[i].edad > 18 && lista[i].edad <= 35)
       {
           personas19a35++;
       }
       if(lista[i].estado == 1 && lista[i].edad <= 18)
       {
           personasMenor18++;
       }
    }

    // Obtengo el rango con mayor cantidad de personas
    if (personasMenor18 >= personas19a35)
    {
        maxCant = personasMenor18;
    }
    else
    {
        maxCant = personas19a35;
    }

    if (maxCant <  personasMayor35)
    {
        maxCant = personasMayor35;
    }

    // Muestro los asteriscos y los rangos

    printf("\n");

    for(j = maxCant; j > 0; j--)
    {
        if (j <= personasMenor18)
        {
            printf(" *    ");
        }
        if (j <= personas19a35)
        {
            printf("  *     ");
        }
        if (j <= personasMayor35)
        {
            printf(" *    ");
        }

        printf("\n");

    }

     printf("<18   19-35   >35\n\n");

}



