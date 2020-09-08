
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* pedirDatos(void* arg){
   
   printf("\nEsto se esta realizando dentro de un hilo!\n");
   int N = 50;
   char* nombre = malloc(sizeof(char) * N);;
   char* apellido = malloc(sizeof(char) * N);;

   printf("Ingrese el nombre: ");
   scanf("%50s",nombre);

   printf("Ingrese el apellido: ");
   scanf("%50s",apellido);

   strcat(nombre,apellido);
   
   size_t stringLength = strlen(nombre);
   stringLength++; //PARA CONTAR EL ESPACIO ENTRE LOS DOS STRINGS
   if(stringLength <= 25){
      printf("NO PROBLEM\n");
   }else{
      printf("WILL TRUNCATE\n");
   }

   free(nombre);
   free(apellido);
   
}



int main(int argc, char const *argv[])
{

   
   //CREACION DE LOS 3 HILOS
   pthread_t hilo1, hilo2, hilo3;

   pthread_create(&hilo1,NULL,pedirDatos,NULL);
   pthread_join(hilo1,NULL);

   pthread_create(&hilo2,NULL,pedirDatos,NULL);
   pthread_join(hilo2,NULL);

   pthread_create(&hilo3,NULL,pedirDatos,NULL);
   pthread_join(hilo3,NULL);

   printf("\nROGRAMA FINALIZADO\n");
   return 0;
}
