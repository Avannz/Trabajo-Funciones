#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargar(Pila *pila1);
void mover (Pila *pila1, Pila *pila2);
void mismoOrden (Pila *pila1, Pila *pila2);
int menor (Pila *pila1);
void ordenarSeleccion (Pila *pila1, Pila *pila2);
void insertar (Pila *pila1, Pila *pila2);
void ordenarInsercion(Pila *pila1);
int suma (Pila *pila1);
int sumarTodo (Pila *pila1);
int validos (Pila *pila1);
float dividir (int val1, int val2);
float promedio(Pila *pila1);
int pasaje (Pila *pila1);
int main()
{

    Pila dada, aux1, aux2, aux3;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);

    int xd;
    float prom;


    cargar(&dada);                          //PUNTO 1
    mostrar(&dada);

    /*mover(&dada, &aux1);                  //PUNTO 2
    mostrar(&aux1);*/

   /* mismoOrden(&dada, &aux1);             //PUNTO 3
    mostrar(&aux1);*/


    /*xd = menor(&dada);                    //PUNTO 4
    printf("\n |%i| \n", xd);*/

    /*ordenarSeleccion(&dada, &aux1);       //PUNTO 5
    mostrar(&aux1);*/

    /*menor(&dada);
    mostrar(&dada);*/

    /*apilar(&aux1, 3);
    insertar(&dada, &aux1);                 //PUNTO 6
    mostrar(&dada);*/

    /*ordenarInsercion(&dada);              //PUNTO 7
    mostrar(&dada);*/

    /*xd = suma(&dada);
    printf("PILA SUMADA: %d", xd);          //PUNTO 8
    */



    /*xd = sumarTodo(&dada);
    printf("La suma total de la pila es de: %i", xd);
    mostrar(&dada);*/

    xd = pasaje(&dada);
    printf("El numero es: %d", xd);

}

void cargar(Pila *pila1)
{

    char letra;

    do
    {

        leer(pila1);
        printf("INGRESA S PARA CONTINUAR");
        fflush(stdin);
        scanf("%c", &letra);
    }
    while(letra=='s');
}

void mover (Pila *pila1, Pila *pila2)
{

    while(!pilavacia(pila1))
    {

        apilar(pila2, desapilar(pila1));

    }

}

void mismoOrden (Pila *pila1, Pila *pila2)
{

    Pila aux;
    inicpila (&aux);

    mover(pila1, &aux);
    mover(&aux, pila2);

}

int menor (Pila *pila1){

    Pila menor, aux;
    inicpila(&menor);
    inicpila(&aux);


    apilar(&menor, desapilar(pila1));
    while (!pilavacia(pila1)){

        if (tope(pila1) < tope(&menor)){

            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(pila1));
        }else{

            apilar(&aux, desapilar(pila1));

        }

    }


        mover(&aux, pila1);

    return tope(&menor);
}


void ordenarSeleccion (Pila *pila1, Pila *pila2){

    while (!pilavacia(pila1)){

        apilar(pila2, menor(pila1));
    }

}

void insertar (Pila *pila1, Pila *pila2){

    Pila aux;
    inicpila(&aux);

    while (!pilavacia(pila1)){

        if (tope (pila1) < tope(pila2) && !pilavacia(pila2)) {

            apilar(&aux, desapilar(pila2));
        }else{

            apilar(&aux, desapilar(pila1));
        }

    }

    if (!pilavacia(pila2)){

        apilar(&aux, desapilar(pila2));
    }

    while (!pilavacia(&aux)){

        apilar(pila1, desapilar(&aux));

    }



}

void ordenarInsercion(Pila *pila1){
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    apilar(&aux, desapilar(pila1));

    while(!pilavacia(pila1)){

        apilar(&aux2, desapilar(pila1));

        insertar(&aux, &aux2);
    }

    mover (&aux, pila1);
}

int suma (Pila *pila1){
    Pila aux;
    inicpila(&aux);

    int suma;

    apilar(&aux, desapilar(pila1));

    suma = tope(pila1) + tope(&aux);
    return suma;
}

int sumarTodo (Pila *pila1) {

    Pila aux;
    inicpila(&aux);

    int suma = 0;

    while(!pilavacia(pila1)){

        suma = tope(pila1) + suma;

        apilar(&aux, desapilar(pila1));

    }

        mover(&aux, pila1);

    return suma;
}

int validos (Pila *pila1){
    Pila aux;
    inicpila(&aux);

    int cont = 0;

    while(!pilavacia(pila1)){

        cont++;
        apilar (&aux, desapilar(pila1));
    }

    mover (&aux, pila1);
    return cont;
}

float dividir (int val1, int val2){

    float resto = 0;

    resto = (float)val1 / val2;

    return resto;
}

float promedio(Pila *pila1){

    float dividendo = 0;
    float promedio = 0;
    int divisor = 0;

    dividendo = sumarTodo(pila1);
    divisor = validos(pila1);

    promedio = dividendo/divisor;

    return promedio;
}

int pasaje (Pila *pila1){

    Pila aux;
    inicpila(&aux);

    int valor=0;
    int i = 1;

    while (!pilavacia(pila1)){

        apilar(&aux, desapilar(pila1));

    }

    while (!pilavacia(&aux)){

        valor = valor + (tope(&aux) * i);
        i = i*10;

        apilar(pila1, desapilar(&aux));

    }

    return valor;
}
