#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

struct timeval t0, t1;

void *mostrarTiempo(void *arg)
{
    gettimeofday(&t1, NULL);
    unsigned int ut1 = t1.tv_sec * 1000000 + t1.tv_usec;
    unsigned int ut0 = t0.tv_sec * 1000000 + t0.tv_usec;
    printf("%f\n", (double)(ut1 - ut0) / 100);
}

int main(int argc, char const *argv[])
{
    int i;
    int id = -1;
    gettimeofday(&t0, NULL);
    for (i = 0; i < 100; i++)
    {
        id = fork();
        if (id == 0)
            return 0;
    }
    if (id != 0)
    {
        gettimeofday(&t1, NULL);
        unsigned int ut1 = t1.tv_sec * 1000000 + t1.tv_usec;
        unsigned int ut0 = t0.tv_sec * 1000000 + t0.tv_usec;
        printf("%f\n", (double)(ut1 - ut0) / 100);
    }

    gettimeofday(&t0, NULL);

    pthread_t hilo1;
    pthread_create(&hilo1, NULL, mostrarTiempo, NULL);
    pthread_join(hilo1,NULL);

    return 0;
}
