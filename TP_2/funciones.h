#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define LIBRE    0
#define OCUPADO  1

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2

typedef struct {

    char nombre[50];
    int edad;
    int estado; // 1 = OCUPADO, 0 = LIBRE
    int dni;

}EPersona;

/**
 * Carga una nueva Persona en una posicion determinada del array.
 * @param lista: el array de Personas que se pasa como parametro.
 * @param posicion: la posicion dentro del array donde se va a agregar a la nueva Persona
 * @param nombre: el nombre de la nueva Persona
 * @param dni: el DNI de la nueva Persona
 * @param edad: la edad de la nueva Persona
 * @param estado: estado de la posicion (LIBRE == 0 || OCUPADO == 1)
 */
void putPersona(EPersona lista[], int posicion, char nombre[50], int dni, int edad, int estado);

/**
 * Inicializa las Personas del array con estado == LIBRE == 0, nombre == "", edad == -1, dni == -1
 * @param lista: el array de Personas que se pasa como parametro.
 */
void inicializarListaPersonas(EPersona lista[]);

/**
 * Solicita por stdout una opcion valida del Menu.
 * @return un numero int que representa la opcion del Menu elegida por el usuario
 */
int getOpcionMenu();

/**
 * Obtiene el primer indice libre del array.
 * @param lista: el array de Personas que se pasa como parametro.
 * @return el primer indice disponible, -1 si no hay espacios libres
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Solicita por stdout un DNI valido.
 * @return un numero int que representa el DNI ingresado por el usuario
 */
int getDNI();

/**
 * Solicita por stdout una edad valida.
 * @return un numero int que representa la edad ingresada por el usuario
 */
int getEdad();

/**
 * Verifica si un nombre dado es valido (solo contiene letras, salvo la enie)
 * @param nombre: el nombre a validar que se pasa como parametro.
 * @return un 1 si el string es valido, un numero menor que 0 en caso contrario
 */
int validarNombre(char nombre[]);

/**
 * Solicita por stdout un nombre valido.
 * @param nombre: la variable que al final contendra el nombre ingresado por el usuario
 */
void getNombre(char nombre[]);

/**
 * Obtiene los datos de una nueva Persona, los valida, y carga dicha Persona en una posicion libre del array, con estado == OCUPADO == 1
 * @param lista: el array de Personas que se pasa como parametro.
 * @param posicionLibre: la posicion dentro del array que no esta ocupada
 */
 void agregarNuevaPersona(EPersona lista[], int posicionLibre);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista: el array que se pasa como parametro.
 * @param dni: el dni a ser buscado en el array.
 * @return el indice en donde se encuentra la primer Persona que coincide con el parametro dni, -1 si no hay coincidencias
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Elimina los datos de la Persona que se encuentra en la posicion dada dentro del array y pone su estado == LIBRE == 0
 * @param lista: el array de Personas que se pasa como parametro.
 * @param posicionLibre: la posicion dentro del array que no esta ocupada
 */
void borrarPersona(EPersona lista[], int posicion);

/**
 * Ordeno la lista de Personas segun el nombre de forma ascendente (BubbleSort).
 * @param lista: el array de Personas que se pasa como parametro.
 */
void ordenarListaPorNombre(EPersona lista[]);

/**
 * Muestro la lista de Personas por stdout
 * @param lista: el array de Personas que se pasa como parametro.
 */
void imprimirLista(EPersona lista[]);

/**
 * Muestro un grafico para estadisticas por rango de edad <=18, 19-35, >35 por stdout
 * @param lista: el array de Personas que se pasa como parametro.
 */
void imprimirGrafico(EPersona lista[]);

#endif // FUNCIONES_H_INCLUDED
