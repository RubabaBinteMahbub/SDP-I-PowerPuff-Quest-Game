#include <stdio.h>
#include "powerpuff.h"

void startPowerPuff_Quest() {

    int hp, attack, choice;

    char *monsters[5] = {
        "Fuzzy Lumpkins",
        "Mojo Jojo",
        "Sedusa",
        "Gangreen Gang",
        "Godzilla"
    };

    int monsterHP[5] = {50, 60, 70, 80, 100};
    int monsterAttack[5] = {10, 12, 14, 16, 20};

    char *monsterColor[5] = {
        YELLOW, PURPLE, CYAN, WHITE, RED
    };

    printf("\nChoose Your Powerpuff Girl\n");
    printf(PINK "1. Blossom\n" RESET);
    printf(BLUE "2. Bubbles\n" RESET);
    printf(GREEN "3. Buttercup\n" RESET);

    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1:
        hp = 120;
        attack = 20;
        printf(PINK "\nYou chose Blossom!\n" RESET);
        break;

    case 2:
        hp = 100;
        attack = 15;
        printf(BLUE "\nYou chose Bubbles!\n" RESET);
        break;

    case 3:
        hp = 110;
        attack = 25;
        printf(GREEN "\nYou chose Buttercup!\n" RESET);
        break;

    default:
        printf("Invalid Choice!\n");
        return;
    }

    for (int i = 0; i < 5; i++) {

        printf("\n%sLEVEL %d%s\n", monsterColor[i], i + 1, RESET);
        printf("%sMonster: %s%s\n", monsterColor[i], monsters[i], RESET);

        while (hp > 0 && monsterHP[i] > 0) {

            printf("\nYour HP: %d\n", hp);
            printf("Monster HP: %d\n", monsterHP[i]);

            printf("\n1. Attack\n");
            printf("2. Heal (+10 HP)\n");

            printf("Choice: ");
            scanf("%d", &choice);

            switch (choice) {

            case 1:
                monsterHP[i] -= attack;
                printf("You attacked!\n");
                break;

            case 2:
                hp += 10;
                printf("You healed!\n");
                break;

            default:
                printf("Invalid move!\n");
                continue;
            }

            if (monsterHP[i] <= 0)
                break;

            hp -= monsterAttack[i];

            printf("%s%s attacked you!%s\n",
                   monsterColor[i],
                   monsters[i],
                   RESET);
        }

        if (hp <= 0) {
            printf(RED "\nGAME OVER!\n" RESET);
            return;
        }

        printf(GREEN "\nLevel Complete!\n" RESET);

        hp += 20;
    }

    printf(PINK "\nYOU WIN! All monsters defeated!\n" RESET);
}
