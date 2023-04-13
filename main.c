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
int main()
{

    Pila dada, aux1, aux2, aux3;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);

    int xd;


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
