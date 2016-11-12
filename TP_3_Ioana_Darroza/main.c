#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    char seguir = 's';
    int opcion = 0;
    int posicion = -1;
    int posicionPeliculaBuscada = -1;
    int cantMovies = 0;

    eMovie movies[SIZE_MOVIES];
    eGenero generos[SIZE_GENEROS];

    cantMovies = inicializarMovies(movies, SIZE_MOVIES);
    inicializarGeneros(generos);


    do
    {
        printf("************************\n");
        printf("*   MENU DE OPCIONES   *\n");
        printf("************************\n");
        printf("1 - Agregar pelicula\n");
        printf("2 - Borrar pelicula\n");
        printf("3 - Modificar pelicula\n");
        printf("4 - Generar pagina web\n");
        printf("5 - Salir\n\n");

        printf("Elija una opcion: ");

        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:

                system("cls");

                posicion = buscarPosicionLibre(movies, SIZE_MOVIES);

                if(posicion != -1)
                {
                    agregarMovie(movies, posicion, generos);
                    cantMovies++;
                }
                else
                {
                    printf("\nNo se ha encontrado espacio libre para cargar mas peliculas\n");
                }

                break;

            case 2:
                system("cls");

                if(cantMovies != 0)
                {
                    printf("\nA continuacion se le mostraran las peliculas listadas\n");

                    mostrarPeliculas(movies);

                    posicionPeliculaBuscada = buscarPelicula(movies,"\nA continuacion ingrese el titulo de la pelicula a borrar.\n");

                    if(posicionPeliculaBuscada != -1)
                    {
                        printf("A continuacion se borraran los datos de la pelicula %s\n", movies[posicionPeliculaBuscada].titulo);
                        borrar(movies, posicionPeliculaBuscada);
                        cantMovies --;
                    }
                    else
                    {
                        printf("El titulo ingresado no coincide con ninguno de los titulos del sistema\n");
                    }
                 }
                 else
                 {
                     printf("\nNo se han encontrado peliculas cargadas en el sistema\n");
                 }

                break;

            case 3:
                system("cls");

                if(cantMovies != 0)
                {
                    printf("\nA continuacion se le mostraran las peliculas listadas\n");

                    mostrarPeliculas(movies);

                    posicionPeliculaBuscada = buscarPelicula(movies,"\nIngrese el titulo de la pelicula que desea modificar\n");

                    if(posicionPeliculaBuscada != -1)
                    {
                        printf("A continuacion se modificaran los datos de la pelicula %s",movies[posicionPeliculaBuscada].titulo);
                        modificar(movies, posicionPeliculaBuscada, generos);
                    }
                    else
                    {
                        printf("El titulo ingresado no coincide con ninguno de los titulos del sistema\n");
                    }
                 }
                 else
                 {
                     printf("\nNo se han encontrado peliculas cargadas en el sistema\n");
                 }

               break;
            case 4:

               if(cantMovies != 0)
               {
                   generateHtml(movies, "index.html");
               }
               else
               {
                   printf("\nNo se han encontrado peliculas cargadas en el sistema para generar el html\n");
               }
               break;
            case 5:
                system("cls");

                seguir = 'n';
                break;
            default:
                printf("\nNo se ha ingresado una opcion valida. Intentelo nuevamente.\n\n");
                break;
        }

        if(opcion != 5)
        {
            system("pause");
        }

	    system("cls");

    } while(seguir == 's');

    return 0;
}
