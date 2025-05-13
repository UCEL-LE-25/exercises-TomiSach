#include <stdio.h>
#include <stdlib.h>  
#include <time.h>  // Para time()

#define table_p 50
#define nail_p 50
#define rope_p 10

int random_number(int min, int max);

int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {  // Cambiado de void main() a int main()
    // Inicializar la semilla para rand()
    srand((unsigned int)time(NULL));

    int player_coins = random_number(100, 300);

    struct material {
        char name[20];
        int price;
    };

    struct material table = {"Table", table_p};
    struct material nail = {"Nail", nail_p};
    struct material rope = {"Rope", rope_p};

    int trap_cost = 2 * table.price + 4 * nail.price + rope.price;

    if (trap_cost < player_coins) {
        printf("You have enough coins to build the trap\n");
        printf("You will have %d coins left after building the trap\n", player_coins - trap_cost);
    } else if (player_coins >= rope.price) {
        printf("You have enough coins to buy a rope\n");
        printf("You will have %d coins left after buying the rope\n", player_coins - rope.price);
    } else {
        printf("You don't have enough coins to buy anything\n");
    }

    return 0;  // Agregado return 0 para indicar éxito
}