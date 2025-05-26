#include <stdio.h>
#include <stdlib.h>

int filtrar_mayores(int *arr,int n,int u , int *arr2);


int main(){

    int enteros[5] = {6, 2, 3, 4, 5};
    int filtro[5];

    filtrar_mayores(enteros, 5, 3, filtro);

   for(int i = 0; i < 5 ; i++){
        if(filtro[i] != 0){
            printf("El filtro es: %d\n", filtro[i]);
        }
    }
    



    return 0;
}

int filtrar_mayores(int *arr, int n ,int u , int *arr2){

    for(int i = 0; i < n ; i++){
        if(arr[i] > u){
            arr2[i] = arr[i];
        }
    }

   
};