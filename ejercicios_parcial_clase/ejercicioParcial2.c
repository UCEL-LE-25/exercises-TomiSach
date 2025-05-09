#include <stdio.h>
#include <stdlib.h>  // Para rand()
#include <stdbool.h>

#define mage_damage 40
#define increase_mana 1.15


int random_number(int min, int max);
int calc_damage(int enemy_mana);


int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int calc_damage(int enemy_mana) {
    int damage = mage_damage + (enemy_mana * 0.15);

    if (damage > 80) {
        printf("CRITICAL HIT\n");
    } else {
        printf("NORMAL HIT\n");
    }
    return damage;
}

int main() {
    // Inicializar la semilla para rand()
    

    int enemy_mana = random_number(120, 300);
    int damage = calc_damage(enemy_mana);

    printf("Enemy mana: %d\n", enemy_mana);
    printf("Damage dealt: %d\n", damage);

    return 0;
}