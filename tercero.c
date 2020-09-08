#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


struct Persona {
    char nombre[30];
    char dui[11];
    int edad;
};

void* imprimirDatos(void* args){

    struct Persona* personaPtr = (struct Persona*) args;
    printf("\nNombre: %s\nDUI: %s\nEdad: %d\n",personaPtr->nombre,personaPtr->dui,personaPtr->edad);
}

int main(int argc, char const *argv[])
{
    
    struct Persona miPersona;

    printf("Ingrese el nombre de la persona: ");
    fgets(miPersona.nombre,30,stdin);

    printf("Ingrese el dui de la persona: ");
    fgets(miPersona.dui,11,stdin);

    printf("Ingrese la edad de la persona: ");
    scanf("%d",&miPersona.edad);

    pthread_t hilo;
    pthread_create(&hilo,NULL,imprimirDatos,(void*)&miPersona);
    pthread_join(hilo,NULL);

    printf("\nPROGRAMA FINALIZADO\n");


    return 0;
}
