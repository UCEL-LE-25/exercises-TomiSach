#include <stdio.h>
#include <stdlib.h>

int contar_pares(int*arr, int n);
int pares = 0 ;
int impares = 0;


int main(){

    
    int enteros[5] = {6, 2, 3, 4, 5};

    contar_pares(enteros, 5);
    printf("El total de pares es: %d\n", pares);
    printf("El total de impares es: %d\n", impares);



    return 0;
}

int contar_pares(int*arr, int n){

    for(int i = 0; i < n ; i++){
        if(arr[i]%2 ==0){
            pares ++;
            
        }else{
            impares ++;
            
        }
    }
};