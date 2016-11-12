#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"


int inicializarMovies(eMovie movies[], int sizeMovies)
{
    int i;
    int moviesFileSize = 0;
    int cantMovies = 0;
    FILE* moviesFile;

    // Verifico si se puede abrir el archivo binario "movies" para lectura
    if((moviesFile = fopen("movies", "rb")) == NULL)
    {
        // Si no lo puedo abrir para lectura, tal vez no existe
        // Intento crear el archivo
        if((moviesFile = fopen("movies", "w+b")) == NULL)
        {
            printf("ERROR: El archivo \"movies\" no pudo ser abierto\n");
            exit(1);
        }
    }

    // Inicializo el array de peliculas "movies" vacio, con estado == LIBRE (0)
    for(i = 0; i < sizeMovies; i++)
    {
        movies[i].estado = LIBRE;
    }

    // Cargo el contenido del archivo binario en el array "movies"
    fseek(moviesFile, 0, SEEK_END);
	moviesFileSize = ftell(moviesFile);
	cantMovies = moviesFileSize / sizeof(eMovie);

	fseek(moviesFile, 0, SEEK_SET);

	for(i = 0; i < cantMovies; i++)
    {
        fread(&movies[i], sizeof(eMovie), 1, moviesFile);
    }

    fclose(moviesFile);

    return cantMovies;
}


void inicializarGeneros(eGenero generos[])
{
    generos[0].idGenero = DRAMA;
    strcpy(generos[0].descripcion, "Drama");

    generos[1].idGenero = COMEDIA;
    strcpy(generos[1].descripcion, "Comedia");

    generos[2].idGenero = ACCION;
    strcpy(generos[2].descripcion, "Accion");

    generos[3].idGenero = AVENTURA;
    strcpy(generos[3].descripcion, "Aventura");

    generos[4].idGenero = TERROR;
    strcpy(generos[4].descripcion, "Terror");

    generos[5].idGenero = CIENCIAFICCION;
    strcpy(generos[5].descripcion, "Ciencia ficcion");

    generos[6].idGenero = ROMANTICO;
    strcpy(generos[6].descripcion, "Romantico");

    generos[7].idGenero = MUSICAL;
    strcpy(generos[7].descripcion, "Musical");

    generos[8].idGenero = MELODRAMA;
    strcpy(generos[8].descripcion, "Melodrama");

    generos[9].idGenero = CATASTROFE;
    strcpy(generos[9].descripcion, "Catastrofe");

    generos[10].idGenero = SUSPENSE ;
    strcpy(generos[10].descripcion, "Suspense");

    generos[11].idGenero = FANTASIA;
    strcpy(generos[11].descripcion, "Fantasia");

    generos[12].idGenero = PORNOGRAFICO;
    strcpy(generos[12].descripcion, "Pornografico");

    generos[13].idGenero = CINE_DE_EXPLOTACION;
    strcpy(generos[13].descripcion, "Cine de explotacion");
}


int buscarPosicionLibre(eMovie movies[], int sizeMovies)
{
    int i;

    for(i = 0; i < sizeMovies; i++)
    {
        if(movies[i].estado == LIBRE)
        {
            return i;
        }
    }

    // Si no encontro ninguna posicion libre, retorna -1
    return -1;
}


int validarTitulo(char titulo[])
{
    //const char patron[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHYJKLMNOPQRSTUVWXYZ";

    if (titulo[0] == '\n')
    {
        printf("ERROR: El titulo no puede ser vacio.\n");
        return -1;
    }
    else if (strchr(titulo, '\n') == NULL)
    {
        printf("ERROR: El titulo no puede tener mas de 50 caracteres (49 letras + el \\0).\n");
        return -2;
    }
    /*else if (titulo[strspn(titulo, patron)] != '\n') // MAGIA!!! Con strspn(titulo, patron) obtengo la primer posicion que no contenga el patron
    {
        printf("ERROR: El titulo solo puede contener caracteres que sean letras (salvo la enie).\n");
        return -3;
    }*/
    else
    {
        return 1;
    }
}


void getTitulo(char titulo[])
{
    // Un caracter mas porque con fgets, el string leido termina en '\n\0', y al eliminar el '\n'
    // me quedan justo 49 caracteres mas el '\0'
    char tituloAux[51];

    printf("Ingrese el titulo: ");

    while(fgets(tituloAux, sizeof(tituloAux), stdin) == NULL || validarTitulo(tituloAux) < 0) {
        fflush(stdin);
        printf("ERROR: Ingrese un titulo valido: ");
    }

    fflush(stdin);

    // Elimino el /n que trae el fgets()
    tituloAux[strcspn(tituloAux, "\r\n")] = 0;

    strcpy(titulo, tituloAux);
}


void mostrarGenero(eGenero generos)
{
    printf("%d - %s\n", generos.idGenero, generos.descripcion);
}


void mostrarGeneros(eGenero generos[])
{
    int i;

    for(i = 0; i < SIZE_GENEROS; i++)
    {
        mostrarGenero(generos[i]);
    }

    printf("\n");
}


int getGenero(eGenero generos[])
{
    system("cls");

    int genero = 0;
    int flagValidarGenero = 0;

    printf("\nA continuacion se le mostraran los generos disponibles para seleccionar.\n");
    printf("\n*****GENEROS******\n");
    mostrarGeneros(generos);

    printf("Ingrese el genero: ");
    flagValidarGenero = scanf("%d", &genero);
    fflush(stdin);

    while(flagValidarGenero != 1 || (genero < 0 || genero > 13))
    {
        printf("ERROR: Ingrese un genero valido: ");
        flagValidarGenero = scanf("%d", &genero);
        fflush(stdin);
    }

    return genero;
}


int obtenerDescripcionGenero(int genero, char descripcionGenero[], eGenero generos[])
{
    int i;
    int flagEncontro = 0;

    for(i = 0; i < SIZE_GENEROS; i++)
    {
        if(genero == generos[i].idGenero)
        {
            strcpy(descripcionGenero, generos[i].descripcion);
            flagEncontro = 1;
            break;
        }
    }

    if (flagEncontro == 0)
    {
        strcpy(descripcionGenero, "No Existe ese genero");
    }

    return flagEncontro;
}


int getDuracion()
{
    system("cls");

    int duracion = 0;
    int flagValidarDuracion = 0;

    printf("Ingrese la duracion de la pelicula en minutos: ");

    flagValidarDuracion = scanf("%d", &duracion);
    fflush(stdin);

    while(flagValidarDuracion != 1 || (duracion < 0 || duracion > 300) )
    {
        printf("ERROR: Ingrese una duracion valida (entre 0 y 300 minutos): ");
        flagValidarDuracion = scanf("%d", &duracion);
        fflush(stdin);
    }

    return duracion;
}


int validarDescripcion(char descripcion[])
{
    //const char patron[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHYJKLMNOPQRSTUVWXYZ";

    if (descripcion[0] == '\n')
    {
        printf("ERROR: La descripcion no puede ser vacio.\n");
        return -1;
    }
    else if (strchr(descripcion, '\n') == NULL)
    {
        printf("ERROR: La descripcion no puede tener mas de 500 caracteres (499 letras + el \\0).\n");
        return -2;
    }
    /*else if (descripcion[strspn(descripcion, patron)] != '\n') // MAGIA!!! Con strspn(descripcion, patron) obtengo la primer posicion que no contenga el patron
    {
        printf("ERROR: La descripcion solo puede contener caracteres que sean letras (salvo la enie).\n");
        return -4;
    }*/
    else
    {
        return 1;
    }
}


void getDescripcion(char descripcion[])
{
    system("cls");
    // Un caracter mas porque con fgets, el string leido termina en '\n\0', y al eliminar el '\n'
    // me quedan justo 499 caracteres mas el '\0'
    char descripcionAux[501];

    // Ingreso el nombre de la Persona
    printf("Ingrese la descripcion de la pelicula: ");

    while(fgets(descripcionAux, sizeof(descripcionAux), stdin) == NULL || validarDescripcion(descripcionAux) < 0) {
        fflush(stdin);
        printf("ERROR: Ingrese una descripcion valida: ");
    }

    fflush(stdin);

    // Elimino el /n que trae el fgets()
    descripcionAux[strcspn(descripcionAux, "\r\n")] = 0;

    strcpy(descripcion, descripcionAux);
}


int getPuntaje()
{
    system("cls");

    int puntaje = 0;
    int flagValidarPuntaje = 0;

    printf("Ingrese el puntaje de la pelicula del 1 al 10: ");

    flagValidarPuntaje = scanf("%d", &puntaje);
    fflush(stdin);

    while(flagValidarPuntaje != 1 || (puntaje < 1 || puntaje > 10))
    {
        printf("ERROR: Ingrese un puntaje valido (entre 1 y 10): ");
        flagValidarPuntaje = scanf("%d", &puntaje);
        fflush(stdin);
    }

    return puntaje;
}


int validarLink(char Link[])
{

    if (Link[0] == '\n')
    {
        printf("ERROR: El link no puede ser vacio.\n");
        return -1;
    }
    else if (strchr(Link, '\n') == NULL)
    {
        printf("ERROR: El link no puede tener mas de 500 caracteres (499 letras + el \\0).\n");
        return -2;
    }
    else if (strchr(Link, ' ') != NULL)
    {
        printf("ERROR: El link no puede contener espacios en blanco.\n");
        return -3;
    }
    else
    {
        return 1;
    }
}


void getLinkImagen(char LinkImagen[])
{
    system("cls");

    // Un caracter mas porque con fgets, el string leido termina en '\n\0', y al eliminar el '\n'
    // me quedan justo 499 caracteres mas el '\0'
    char LinkAux[501];

    printf("Ingrese el link de la imagen: ");

    while(fgets(LinkAux, sizeof(LinkAux), stdin) == NULL || validarLink(LinkAux) < 0)
    {
        fflush(stdin);
        printf("ERROR: Ingrese un link de imagen valido: ");
    }

    fflush(stdin);

    // Elimino el /n que trae el fgets()
    LinkAux[strcspn(LinkAux, "\r\n")] = 0;

    strcpy(LinkImagen, LinkAux);
}


void putMovie(eMovie movies[], int posicion, char titulo[], int genero, char descripcionGenero[], int duracion, char descripcion[], int puntaje, char linkImagen[], int estado)
{
    FILE* moviesFile;

    strcpy(movies[posicion].titulo, titulo);
    movies[posicion].genero = genero;
    strcpy(movies[posicion].descripcionGenero, descripcionGenero);
    movies[posicion].duracion = duracion;
    strcpy(movies[posicion].descripcion, descripcion);
    movies[posicion].puntaje = puntaje;
    strcpy(movies[posicion].linkImagen, linkImagen);
    movies[posicion].estado = estado;

    // Abro el archivo binario "movies" para lectura/escritura
    moviesFile = fopen("movies", "r+b");

    // Busco la posicion dentro del archivo binario donde colocar la nueva pelicula
    fseek(moviesFile, posicion * sizeof(eMovie), SEEK_SET);

    // Escribo los datos de la nueva pelicula en dicha posicion
    fwrite(&movies[posicion], sizeof(eMovie), 1, moviesFile);

    fclose(moviesFile);
}


void agregarMovie(eMovie movies[], int posicionLibre, eGenero generos[])
{
    char titulo[50];
    char descripcion[500];
    char linkImagen[500];
    int genero;
    int duracion;
    int puntaje;
    char descripcionGenero[30];


    printf("\nA continuacion se procedera a la carga de datos de la pelicula.\n\n");

    getTitulo(titulo);
    genero = getGenero(generos);
    obtenerDescripcionGenero(genero, descripcionGenero, generos);
    duracion = getDuracion();
    getDescripcion(descripcion);
    puntaje = getPuntaje();
    getLinkImagen(linkImagen);

    // Guardo los datos en el array de peliculas "movies"
    putMovie(movies, posicionLibre, titulo, genero, descripcionGenero, duracion, descripcion, puntaje, linkImagen, OCUPADO);

    printf("\nSe ha agregado exitosamente a la nueva pelicula.\n");

}


void mostrarPeliculas(eMovie movies[])
{
    int i;

    system("cls");

    printf("\n*****************PELICULAS********************\n");

    for(i = 0; i < SIZE_MOVIES; i++)
    {
        if(movies[i].estado == OCUPADO)
        {
            printf("\nTITULO:%s\nGENERO:%s\nDURACION:%d\nDESCRIPCION:%s\nPUNTAJE:%d\nLINK DE IMAGEN:%s\n",movies[i].titulo, movies[i].descripcionGenero, movies[i].duracion, movies[i].descripcion,movies[i].puntaje, movies[i].linkImagen);
        }
    }
    printf("\n\n");

}


int buscarPelicula(eMovie movies[], char frase[])
{
    int i;
    char titulo[50];
    int retorno = -1;

    printf("%s", frase);

    getTitulo(titulo);

    for(i = 0; i < SIZE_MOVIES; i++)
    {
        if(strcmp(titulo, movies[i].titulo) == 0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


void borrar(eMovie movies[], int posicionPeliculaBuscada)
{
    putMovie(movies, posicionPeliculaBuscada, "", 0, "", 0, "", 0, "", LIBRE);
}


void modificar(eMovie movies[], int posicionPeliculaBuscada, eGenero generos[])
{
    int opcion = 0;
    int validarOpcion = 0;
    char titulo[50];
    int genero = 0;
    char descripcionGenero[30];
    int duracion = 0;
    char descripcion[500];
    int puntaje = 0;
    char LinkImagen[500];
    char seguir = 's';
    FILE* moviesFile;

    system("cls");

    do
    {

        printf(" __________________________ \n");
        printf("|                          |\n");
        printf("|      MENU MODIFICAR      |\n");
        printf("|__________________________|\n");
        printf("|                          |\n");
        printf("| 1.MODIFICAR NOMBRE       |\n");
        printf("| 2.MODIFICAR GENERO       |\n");
        printf("| 3.MODIFICAR DURACION     |\n");
        printf("| 4.MODIFICAR DESCRIPCION  |\n");
        printf("| 5.MODIFICAR PUNTAJE      |\n");
        printf("| 6.MODIFICAR LINK IMAGEN  |\n");
        printf("| 7.FINALIZAR MODIFICACION |\n");
        printf("|__________________________|\n");

        printf("\n\n Indique que dato de la pelicula desea modificar:\n");
        validarOpcion = scanf("%d", &opcion);
        fflush(stdin);

        while(validarOpcion !=0 && opcion < 1 && opcion > 7)
        {
            printf("\nNo se ha ingresado una opcion valida. Ingrese una opcion de las anteriores: ");
            validarOpcion = scanf("%d", &opcion);
            fflush(stdin);
        }

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("\nIngrese el nuevo titulo de la pelicula:");
                getTitulo(titulo);
                fflush(stdin);

                strcpy(movies[posicionPeliculaBuscada].titulo, titulo);

                printf("\nSe ha modificado el titulo con exito");

            break;

            case 2:
                system("cls");
                printf("\nIngrese el nuevo genero:");
                genero = getGenero(generos);
                obtenerDescripcionGenero(genero,descripcionGenero,generos);

                movies[posicionPeliculaBuscada].genero = genero;
                strcpy(movies[posicionPeliculaBuscada].descripcionGenero, descripcionGenero);

                printf("\nSe ha modificado el genero con exito");

            break;

            case 3:
                system("cls");
                printf("\nIngrese la nueva duracion de la pelicula:");
                duracion = getDuracion();

                movies[posicionPeliculaBuscada].duracion = duracion;

                printf("\nSe ha ingresado la nueva duracion con exito");

            break;

            case 4:
                system("cls");

                printf("\nIngrese la nueva descripcion de la pelicula:");

                getDescripcion(descripcion);

                strcpy(movies[posicionPeliculaBuscada].descripcion, descripcion);

                printf("\nSe ha ingresado la nueva descripcion de la pelicula con exito");

            break;

            case 5:
                system("cls");
                printf("\nIngrese el nuevo puntaje de la pelicula:");

                puntaje = getPuntaje();

                movies[posicionPeliculaBuscada].puntaje = puntaje;

                printf("\nSe ha ingresado el nuevo puntaje de la pelicula con exito");

            break;

            case 6:
                system("cls");
                printf("\nIngrese el nuevo link de imagen de la pelicula:");

                getLinkImagen(LinkImagen);

                strcpy(movies[posicionPeliculaBuscada].linkImagen, LinkImagen);

                printf("\nSe ha ingresado el nuevo link de imagen con exito");

            break;

            case 7:
                system("cls");
                seguir = 'n';
            break;
        }
    } while(seguir == 's');

    // Abro el archivo binario "movies" para lectura/escritura
    moviesFile = fopen("movies", "r+b");

    // Busco la posicion dentro del archivo binario donde colocar la nueva pelicula
    fseek(moviesFile, posicionPeliculaBuscada * sizeof(eMovie), SEEK_SET);

    // Escribo los datos de la nueva pelicula en dicha posicion
    fwrite(&movies[posicionPeliculaBuscada], sizeof(eMovie), 1, moviesFile);

    fclose(moviesFile);

}

void generateHtml(eMovie movies[], char html[])
{
    FILE* htmlFile;
    int i;
    char htmlHeader[] = "<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n\t<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n\t<title>Lista peliculas</title>\n\t<!-- Bootstrap Core CSS -->\n\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n\t<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n\t<link href='css/custom.css' rel='stylesheet'>\n\t<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n\t<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n\t<!--[if lt IE 9]>\n\t\t<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n\t\t<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n\t<![endif]-->\n</head>\n<body>\n\t<div class='container'>\n\t\t<div class='row'>\n\n";
    char htmlFooter[] = "\n\t\t</div>\n\t\t<!-- /.row -->\n\t</div>\n\t<!-- /.container -->\n\t<!-- jQuery -->\n\t<script src='js/jquery-1.11.3.min.js'></script>\n\t<!-- Bootstrap Core JavaScript -->\n\t<script src='js/bootstrap.min.js'></script>\n\t<!-- IE10 viewport bug workaround -->\n\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n\t<!-- Placeholder Images -->\n\t<script src='js/holder.min.js'></script>\n</body>\n</html>";

    htmlFile = fopen(html, "w");

    if(htmlFile == NULL)
    {
        printf("\nError!!No se ha podido crear el archivo %s", html);
    }
    else
    {
        // Guardo la cabecera del archivo index.html
        fprintf(htmlFile, "%s", htmlHeader);


        for(i = 0; i < SIZE_MOVIES; i++)
        {
            if(movies[i].estado == OCUPADO)
            {
                fprintf(htmlFile, "%s", "\t\t\t<!-- Repetir esto para cada pelicula -->\n\t\t\t<article class='col-md-4 article-intro'>\n\t\t\t\t<a href='#'>\n\t\t\t\t\t<img class='img-responsive img-rounded' src='");
                fprintf(htmlFile, "%s", movies[i].linkImagen);
                fprintf(htmlFile, "%s", "' alt=''>\n\t\t\t\t</a>\n\t\t\t\t<h3>\n\t\t\t\t\t<a href='#'>");
                fprintf(htmlFile, "%s", movies[i].titulo);
                fprintf(htmlFile, "%s", "</a>\n\t\t\t\t</h3>\n\t\t\t\t<ul>\n\t\t\t\t\t<li>Género:");
                fprintf(htmlFile, "%s", movies[i].descripcionGenero);
                fprintf(htmlFile, "%s", "</li>\n\t\t\t\t\t<li>Puntaje:");
                fprintf(htmlFile, "%d", movies[i].puntaje);
                fprintf(htmlFile, "%s", "</li>\n\t\t\t\t\t<li>Duración:");
                fprintf(htmlFile, "%d", movies[i].duracion);
                fprintf(htmlFile, "%s", "</li>\n\t\t\t\t</ul>\n\t\t\t\t<p>");
                fprintf(htmlFile, "%s", movies[i].descripcion);
                fprintf(htmlFile, "%s", "</p>\n\t\t\t</article>\n\t\t\t<!-- Repetir esto para cada pelicula -->\n");
            }
        }

        // Guardo el pie del archivo index.html
        fprintf(htmlFile, "%s", htmlFooter);

    }

    fclose(htmlFile);
}
