#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Color macros
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PINK "\033[1;35m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

// Function prototypes
void registerUser();
int loginUser();
void startPowerPuff_Quest();

// ---------- REGISTER ----------
void registerUser() {
    char username[50], password[50];

    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf(RED "File error!\n" RESET);
        return;
    }

    printf("\nEnter Username: ");
    scanf("%49s", username);

    printf("Enter Password: ");
    scanf("%49s", password);

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf(GREEN "\nRegistration Successful!\n" RESET);
}

// ---------- LOGIN ----------
int loginUser() {
    char username[50], password[50];
    char fileUser[50], filePass[50];

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf(RED "\nNo users found! Please register first.\n" RESET);
        return 0;
    }

    printf("\nEnter Username: ");
    scanf("%49s", username);

    printf("Enter Password: ");
    scanf("%49s", password);

    int found = 0;

    while (fscanf(fp, "%49s %49s", fileUser, filePass) == 2) {
        if (strcmp(username, fileUser) == 0 &&
            strcmp(password, filePass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf(RED "\nInvalid Username or Password!\n" RESET);
        return 0;
    }

    printf(GREEN "\nLogin Successful!\n" RESET);
    return 1;
}

// ---------- GAME ----------
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
            hp = 120; attack = 20;
            printf(PINK "\nYou chose Blossom!\n" RESET);
            break;

        case 2:
            hp = 100; attack = 15;
            printf(BLUE "\nYou chose Bubbles!\n" RESET);
            break;

        case 3:
            hp = 110; attack = 25;
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

// ---------- MAIN MENU ----------
int main() {
    int choice;
    int isLoggedIn = 0;

    while (1) {
        printf(PINK"\n===== POWERPUFF Quest =====\n"RESET);
        printf(YELLOW"1. Register\n"RESET);
        printf(YELLOW"2. Login\n"RESET);
        printf(YELLOW"3. Start PowerPuff Quest\n"RESET);
        printf(YELLOW"6. Exit\n"RESET);

        printf(CYAN"Choice: "RESET);
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                registerUser();
                break;

            case 2:
                if (loginUser()) {
                    isLoggedIn = 1;
                }
                break;

            case 3:
               if (isLoggedIn) {
                    startPowerPuff_Quest();
               }
               else{
                    printf(RED "\nPlease login first!\n" RESET);
                }
                break;

            case 6:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}

