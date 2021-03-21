#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct Character
{
    char* name = (char*) malloc(128);
    char race[128];
    int level;
    int health;
    int mana;
    int experience;
    float damage;
    bool dead = false;
};

Character init(char* name)
{
    Character player;
    strcpy(player.name, name);
    strcpy(player.race, "Human");
    player.level = 1;
    player.health = 40;
    player.mana = 20;
    player.damage = 5;
    player.experience = 0;
    return player;
}

char* read()
{
    printf("Input character name: ");
    char s[128];
    scanf("%s", &s);
    return s;
}

void display(const Character& ch)
{
    printf("Name: %s\nRace: %s\nLevel: %d\nExperience: %d / 100\nHealth: %d\nMana: %d\nDamage: %.2f\n\n", ch.name, ch.race, ch.level, ch.experience, ch.health, ch.mana, ch.damage);
}

void level_up(Character& ch)
{
    ch.level++;
    ch.health = 40 * ch.level;
    ch.mana = 20 * ch.level;
    ch.damage = 5 * ch.level;
}

void add(Character& ch, int exp)
{
    ch.experience += exp;
    while (ch.experience >= 100)
    {
        ch.experience -= 100;
        level_up(ch);
    }
}


void take_damage(Character& ch, int dmg)
{
    ch.health -= dmg;
    if (ch.health <= 0)
    {
        ch.health = 40 * ch.level;
        ch.experience = 0;
        ch.dead = true;
        printf("You're dead\n");
    }
}

int main()
{
    char* name = (char*) malloc(128);
    printf("Create character 1\n");
    strcpy(name, read());
    Character player = init(name);
    display(player);
    printf("Create character 2\n");
    strcpy(name, read());
    Character player2 = init(name);
    display(player2);
    printf("Adding experience to characters.\n");
    add(player, 245);
    add(player2, 512);
    display(player);
    display(player2);
    take_damage(player, 150);
    display(player);
    
}

