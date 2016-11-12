#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define SIZE_MOVIES        100
#define SIZE_GENEROS        14

#define LIBRE                0
#define OCUPADO              1

#define DRAMA                0
#define COMEDIA              1
#define ACCION               2
#define AVENTURA             3
#define TERROR               4
#define CIENCIAFICCION       5
#define ROMANTICO            6
#define MUSICAL              7
#define MELODRAMA            8
#define CATASTROFE           9
#define SUSPENSE            10
#define FANTASIA            11
#define PORNOGRAFICO        12
#define CINE_DE_EXPLOTACION 13


typedef struct{
    char titulo[50];
    int genero;
    char descripcionGenero[30];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];
    int estado;
} eMovie;

typedef struct
{
    int idGenero;
    char descripcion[30];
} eGenero;


/**
 *  Inicializar el array de peliculas, cargando el contenido del archivo binario "movies"
 *  @param array de peliculas a ser inicializadas
 *  @param tamaño del array
 *  @return cantidad de Peliculas cargadas del archivo binario "movies"
 */
int inicializarMovies(eMovie[], int);


/**
 *  Inicializar el array de generos con el numero que corresponde a cada genero
 *  @param array de generos a ser inicializados
 */
void inicializarGeneros(eGenero[]);


/**
 *  Busca una posicion libre en el array de peliculas "movies"
 *  @param array de peliculas en la que se busca una posicion con el estado == LIBRE (0)
 *  @param tamaño del array
 *  @return -1 si no hay posicion libre, el numero de la posicion en caso de que haya un espacio libre
 */
int buscarPosicionLibre(eMovie[], int);


/**
 * Verifica si un titulo dado es valido
 * @param titulo a validar que se pasa como parametro.
 * @return un 1 si el string es valido, un numero menor que 0 en caso contrario
 */
int validarTitulo(char[]);


/**
 * Solicita por stdout un titulo valido para la nueva pelicula
 * @param titulo: la variable que al final contendra el titulo ingresado por el usuario
 */
void getTitulo(char[]);


/**
 *  Muestra el genero de la pelicula por stdout
 *  @param estructura eGenero que contiene los datos del genero de peliculas a mostrar
 */
void mostrarGenero(eGenero);


/**
 *  Muestra los generos de las peliculas por stdout
 *  @param el array que contiene los generos de peliculas
 */
void mostrarGeneros(eGenero[]);


/**
 * Solicita por stdout un genero valido para la nueva pelicula
 * @param el array que contiene los generos de peliculas
 * \return el genero que se cargara en la pelicula ya validado
 *
 */
int getGenero(eGenero[]);


/**
 * Obtiene la descripcion del genero ingresado por el usuario comparando el genero ingresado el idGenero del array generos
 * \param genero: Le paso el genero ingresado y validado ya.
 * \param descripcionGenero: variable de tipo char que guardara la descripcion del genero
 * \param el array que contiene los generos de peliculas
 * \return devuelve 1 si encontro un numero de id que coincida con la variable genero y 0 si no.
 *
 */
int obtenerDescripcionGenero(int, char[], eGenero[]);


/**
 * Solicita por stdout una duracion valida para la nueva pelicula
 * \return devuelve la duracion de la pelicula ya validada
 *
 */
int getDuracion();


/**
 *  Comprueva que la descripcion sea valida
 * \param variable de tipo char donde se va a copiar la descripcion en caso de que sea valida
 *
 */
int validarDescripcion(char[]);


/**
 * Solicita por stdout una descripcion valida para la nueva pelicula
 * \param descripcion: variable de tipo char que guardara la descripcion de la pelicula
 *
 */
void getDescripcion(char[]);


/**
 * Solicita por stdout un puntaje valido para la nueva pelicula
 * \return devuelve el puntaje de la pelicula ya validado
 *
 */
int getPuntaje();


/**
 * Comprueva que el link sea valido
 * \param variable de tipo char donde se va a copiar el link en caso de que sea valido
 *
 */
int validarLink(char Link[]);


/**
 * Solicita por stdout un link de imagen valido para la nueva pelicula
 * \param LinkImagen: variable de tipo char que guardara el link de imagen de la pelicula
 *
 */
void getLinkImagen(char[]);


/**
 * Carga una nueva pelicula en una posicion determinada del array de peliculas "movies" y en el archivo binario "movies"
 * @param movies: el array de peliculas que se pasa como parametro.
 * @param posicion: la posicion dentro del array donde se va a agregar a la nueva pelicula
 * @param titulo: el titulo de la nueva pelicula
 * @param genero: el genero de la nueva pelicula
 * @param duracion: la duracion de la nueva pelicula
 * @param descripcion: la descripcion de la nueva pelicula
 * @param puntaje: el puntaje de la nueva pelicula
 * @param linkImagen: el link de la imagen de la nueva pelicula
 * @param estado: estado de la posicion (LIBRE == 0 || OCUPADO == 1)
 */
void putMovie(eMovie[], int, char[], int, char[], int, char[], int, char[], int);


/**
 *  Agrega una pelicula al array de peliculas "movies", y al archivo binario "movies"
 *  @param array de peliculas "movies" donde sera cargada la nueva pelicula
 *  @param posicion donde se va a cargar la nueva pelicula dentro del array "movies"
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarMovie(eMovie[], int, eGenero[]);


/**
 * Muestra los datos cargados en el array movies
 * @param array de peliculas "movies" de donde tomaremos los datos a mostrar
 */
void mostrarPeliculas(eMovie movies[]);


/** Pide el tiulo de una pelicula que queramos buscar en el array
 * @param array de peliculas "movies" donde se buscara el titulo de la pelicula
 * @param array de tipo char que contiene una frase para mostrarse por printf en la funcion
 * \return devuelve la posicion de la pelicula que coincida con el titulo que ingresamos
 */
int buscarPelicula(eMovie movies[],char frase[]);


/**
 * Borra una pelicula del archivo binario
 * @param array de peliculas "movies" donde borrara la pelicula
 * @param variable del tipo int con el numero de la posicion de la pelicula buscada
 */
void borrar(eMovie movies[], int posicionPeliculaBuscada);


/**
 * Modifica una pelicula del archivo binario
 * @param array de peliculas "movies" donde modificara la pelicula
 * @param variable del tipo int con el numero de la posicion de la pelicula buscada
 * @param array de generos para mostrar los generos a modificar
 */
void modificar(eMovie movies[], int posicionPeliculaBuscada, eGenero generos[]);


/**
 * Crea un archivo con las peliculas cargadas en el array movies
 * @param array de peliculas "movies" de donde toma los datos de las peliculas
 * @param array de tipo char que contiene el nombre del archivo que se va a genera
 */
void generateHtml(eMovie[], char[]);

#endif // FUNCIONES_H_INCLUDED
