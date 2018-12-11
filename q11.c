#include <pthread.h>                              
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS 3

static int out = 2;

void* run (void* args) {
    int me = (int) args;
    while (me != out);
    printf("%d > ", me);
    out = (out + 2) % 4;
    if (!out) ++out;
    pthread_exit(0);
}

int main() {
    
    pthread_t tid[NTHREADS];
    for (int i = 0; i < NTHREADS; ++i) {
        pthread_create(&tid[i], NULL, run, (void*) i + 1);
    }
    for (int i = 0; i < NTHREADS; ++i) {
        pthread_join(tid[i], NULL);
    }
    
    printf("%s\n", "done");
    return EXIT_SUCCESS;
}  

