#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

pthread_barrier_t waitsort;
double n = 5.0;
double range;
int *array;
int border; //nicht optimal, weil border neu berechnet wird, müsste durch wall aber geschützt sein

void* bogomerge(void * arg){ //übergebene Arrays mergen mit einem Thread
    int * array = (int *) arg; //kann probleme machen
    for(int i = 0; i < border / 2; i++){
        if(array[i]>array[i+border/2]){  //compare
            for(int j = i; j< border/2; j++){    //swap arrays
                int temp = array[j];
                array[j] = array[j+border/2];
                array[j+border/2] = temp;
            }
        }
    }
    pthread_barrier_wait(&waitsort); //aufheben sobald Threads geendet  sind
    pthread_barrier_destroy(&waitsort);
    return NULL;
}

bool isSorted(int *arg){ //prüfen ob Reihenfolge stimmt
    for(int i=0; i<4-1; i++){
        if(array[i]>array[i+1]) return false;
    }
    return true;
}
void* bogosort(void * arg){ //übergebenes Array sortieren 
    int * array = (int *) arg; //kann probleme machen
    while (!isSorted(array)){
        for(int i =0; i < 4-1; i++){
           int random = rand() % 10000;
               int temp = array[i];
               array[i] = array[random];
               array[random] = temp;
        }
    }
    pthread_barrier_wait(&waitsort);
    pthread_barrier_destroy(&waitsort);
    return NULL;
}

void bogosplit(int *array, int arraylength){ //array aufteilen auf anzahl threads
    int thread_wall = range / 4; 
    pthread_barrier_init(&waitsort, NULL, thread_wall); //threadwall initalisieren

    pthread_t threads[arraylength]; 

    for(int i = 0; i < arraylength; i += 4){ //threads 4er Block zuweisen um zu sortieren
        pthread_create(&threads[i], NULL, bogosort, &array[i]); //beginnen bei bogosort erhalten array
    }
    while(thread_wall > 1){ //sortierte arrays iterativ ablaufen und jeweils 2 gleichgroße mergen
        thread_wall = thread_wall / 2;
        border = range / thread_wall;
        pthread_barrier_init(&waitsort, NULL, thread_wall); 

        pthread_t threads[thread_wall];

        for(int j = 0; j < thread_wall; j++){
            pthread_create(&threads[j], NULL, bogomerge, &array[0+j*border]); //erhalten array
        }
    }
}


int main(int argc, char const *argv[]){
    range = pow(2.0,n);
    int arraylength = range *sizeof(int); //größe des arrays errechnen
    array = (int *) malloc(arraylength);
    if(array == NULL) printf("Fehler bei Speicherbelegung\n");

    for(int i = 0; i < range; i++){ //array befüllen
        array[i] = rand() % 10000;
    }
    for(int j = 0; j< (range / 4) -4; j++){ //anfangs array printen
        printf("%d, %d, %d, %d\n",array[j], array[j+1], array[j+2], array[j+3]);
    }
    bogosplit(array,arraylength);
    for(int k = 0; k< (range / 4) -4; k++){ //sortiertes array printen
        printf("%d, %d, %d, %d\n",array[k], array[k+1], array[k+2], array[k+3]);
    }
    free(array);
}


