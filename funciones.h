#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief Validar un numero flotante y que no sea un caracter
 *
 * \param operando (letra) a validar
 * Ingresamos la letra del operando para mostrar que operando estamos validando.
 * Mientras que el valor ingresado para el operando no sea un numero, pide ingresar un numero de nuevo.
 * \return devuelve el numero validado para el operando
 *
 */

float validarOperando(char);


/** \brief Validar que haya valores cargados en los operandos
 *
 * \param bandera (flag) del primer operando
 * \param bandera del segundo operando
 * Si hay datos cargados en los dos operandos, el valor de ambas vanderas es igual a 1 y la funcion nos devuelve un 1 (estan cargados).
 * Si la bandera de alguno de los dos operandos esta en 0, no esta cargado el valor y nos pedira cargar de nuevo el valor de ese operando.
 * \return nos devuelve 1 si estan cargados los valores de los operandos y 0 si no estan cargados los dos o uno de ellos.
 *
 */

int operandosCargados(int, int);


/** \brief Validar que haya un valor cargado en el operando
 *
 * \param bandera(flag) del operando
 * Si hay algun dato cargado la bandera tiene valor 1 y la funcion nos devuelve 1(esta cargado).
 * Si no hay ningun dato cargado la bandera tiene valor 0 y nos pedira ingresar un valor para el operando de nuevo(no esta cargado).
 * \return nos devuelve 1 si esta cargado el valor del operando y 0 si no esta cargado.
 *
 */

int operandoCargado(int);


/** \brief Sumar dos numeros flotantes
 *
 * \param x valor a sumar
 * \param y valor a sumar
 * \return devuelve el valor de la suma de los numeros ingresados como un numero flotante
 *
 */

float sumar(float, float);


/** \brief Restar dos numeros flotantes
 *
 * \param x valor al que se le resta
 * \param y valor que restamos
 * \return devuelve el valor de la resta de los numeros ingresados como un numero flotante
 *
 */

float restar(float,float);


/** \brief Dividir dos numeros flotantes
 *
 * \param x valor que se divide
 * \param y valor por el cual dividimos si es distinto de cero
 * Si y es igual a cero, nos muestra un mensaje de error y nos pide ingresar un numero distinto de cero
 * Si y es distinto de 0 lo divide por x
 * \return devuelve el valor de la division de los numeros ingresados como numero flotante
 *
 */

float dividir(float,float);


/** \brief Multiplicar dos numeros flotantes
 *
 *\param x valor a multiplicar
 *\param y valor a multiplicar
 *\return devuelve el valor de la multiplicacion de los numeros ingresados como un numero flotante
 *
 */

float multiplicar(float,float);


/** \brief Factorial de un numero flotante
 *
 * \param x valor del numero a calcular el factorial
 * Si el valor de x es un numero negativo muestra un mensaje de error pidiendo que se ingrese un numero positivo
 * Sino,entra al for y calcula el factorial del valor de x
 *\return devuelve el valor del factorial como un numero entero
 *
 */

int factorial(float);


#endif // FUNCIONES_H_INCLUDED



