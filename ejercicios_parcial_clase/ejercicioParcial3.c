#include <stdio.h>
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h>  // Para rand()

#define arrow_prob 0.6
#define arrow_cant 10


void main(){

    bool hits [arrow_cant];

    int hit_count = 0;
    int miss_count = 0;
    
    for(int i = 0; i < arrow_cant; i++){
        hits[i] = (rand() / (double)RAND_MAX) < arrow_prob;
        if(hits[i]){
            hit_count++;
        }else{
            miss_count++;
        }
    }

    for(int i = 0; i < arrow_cant; i++){
        if(hits[i]){
            printf("Arrow %d: hited\n", i + 1);
        }else{
            printf("Arrow %d: missed\n", i + 1);
        }
    }
    
}