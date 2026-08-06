#include <stdio.h>
#include <string.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PINK "\033[1;35m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

//==================== CHECK USERNAME ====================
int usernameExists(char username[]) {
    FILE *fp = fopen("users.txt", "r");

    if (fp == NULL) {
        return 0;
    }

    char fileUser[50];
    char filePass[50];

    while (fscanf(fp, "%49s %49s", fileUser, filePass) == 2) {
        if (strcmp(username, fileUser) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

//==================== REGISTER ====================
int registerUser() {
    char username[50];
    char password[50];

    printf(CYAN "\nEnter Username: " RESET);
    scanf("%49s", username);

    if (usernameExists(username)) {
        printf(RED "\nUsername already registered!\n" RESET);
        printf(RED "Try another username or login!\n" RESET);
        return 0;
    }

    printf(CYAN "Enter Password (must contain less than 50 characters): " RESET);
    scanf("%49s", password);

    FILE *fp = fopen("users.txt", "a");

    if (fp == NULL) {

        printf(RED "File Error!\n" RESET);
        return 0;
    }

    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);

    printf(GREEN "\nRegistration Successful!\n" RESET);
    printf(GREEN "Now login to play the game!\n" RESET);

    return 1;
}

//==================== LOGIN ====================
int loginUser() {
    char username[50], password[50];
    char fileUser[50], filePass[50];;

    FILE *fp = fopen("users.txt", "r");

    if (fp == NULL) {
        printf(RED "\nNo registered users found!\n" RESET);
        return 0;
    }

    printf(CYAN "\nEnter Username: " RESET);
    scanf("%49s", username);

    printf(CYAN "Enter Password (must contain less than 50 characters): " RESET);
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

// ---------- GAME CORE ----------
void startPowerPuff_Quest() {
    int choice;

    int hp;
    int maxHP;
    int attack;

    char *monsters[5] = {"Fuzzy Lumpkins", "Mojo Jojo", "Sedusa", "Gangreen Gang", "HIM"};

    int monsterHP[5] = {40, 50, 60, 70, 80};

    int monsterAttack[5] = {10, 12, 14, 16, 20};

    char *absorbedSkills[5] = {"Freeze Ray", "Sonic Scream", "Laser Eye", "Thunder Clap", "Ultimate Power"};

     // Short Team Dialogue
    printf(PURPLE "\n[Blossom]: Girls, Townsville needs us!\n" RESET);
    printf(PURPLE "[Bubbles]: Let's do this!\n" RESET);
    printf(PURPLE "[Buttercup]: Time to smash villains!\n" RESET);


    // Character Choice
    printf(PINK "\n===== POWERPUFF QUEST =====\n" RESET);
    printf(PINK  "1. Blossom\n" RESET);
    printf(BLUE  "2. Bubbles\n" RESET);
    printf(GREEN "3. Buttercup\n" RESET);

    printf(CYAN "Choose Your Character: " RESET);
    scanf("%d", &choice);

    switch(choice) {
    case 1:
        hp = maxHP = 120;
        attack = 20;
        printf(PINK "\nYou chose Blossom!\n" RESET);
        printf(PINK "Your hp : 120\n" RESET);
        printf(PINK "Attack : 20\n" RESET);
        break;

    case 2:
        hp = maxHP = 100;
        attack = 15;
        printf(BLUE "\nYou chose Bubbles!\n" RESET);
        printf(BLUE "Your hp : 100\n" RESET);
        printf(BLUE "Attack : 15\n" RESET);
        break;

    case 3:
        hp = maxHP = 110;
        attack = 25;
        printf(GREEN "\nYou chose Buttercup!\n" RESET);
        printf(GREEN "Your hp : 120\n" RESET);
        printf(GREEN "Attack : 25\n" RESET);
        break;

    default:
        printf(RED "Invalid Choice!\n" RESET);
        return;
    }

    //==========LEVEL LOOP==========
    for (int i = 0; i < 5; i++) {

        printf(YELLOW "\n--- LEVEL %d: %s ---\n" RESET, i + 1, monsters[i]);

        while (hp > 0 && monsterHP[i] > 0) {

            // Current Score of Player and Monster
            printf("\nYour HP: %d | Monster HP: %d\n", hp, monsterHP[i]);

            printf("\n1. Attack\n");
            printf("2. Heal (+10 HP)\n");

            printf(CYAN "Choice : " RESET);
            scanf("%d", &choice);

            switch(choice) {
            case 1:
                monsterHP[i] -= attack;
                printf(GREEN "\nYou attacked %s!\n" RESET, monsters[i]);
                break;

            case 2:
                hp = (hp + 10 > maxHP) ? maxHP : hp + 10;
                printf(BLUE "\nYou healed +10 HP!\n" RESET);
                break;

            default:
                printf(RED "\nInvalid Move!\n" RESET);
                continue;
            }

            if (monsterHP[i] <= 0) break;

            hp -= monsterAttack[i];

            printf(RED "%s hit you for %d damage!\n" RESET, monsters[i], monsterAttack[i]);
        }

        if (hp <= 0) {
            printf(RED "\nGAME OVER!\n" RESET);
            return;
        }

        attack += 5;
        hp = (hp + 20 > maxHP) ? maxHP : hp + 20;

        printf(GREEN "Level Clear! Absorbed Skill: '%s' (+5 Attack Power)\n" RESET, absorbedSkills[i]);

    }
    // End of Level Loop

    printf(PINK
           "\n=====================================\n"
           " YOU WIN!\n"
           " YOU DEFEATED ALL MONSTERS!\n"
           " YOU SAVED TOWNSVILLE!\n"
           "=====================================\n"
           RESET);
}
int main() {
    int choice;
    int isLoggedIn = 0;
    int isRegistered = 0;

    FILE *fp = fopen("users.txt", "r");
    if (fp != NULL) {
        isRegistered = 1;
        fclose(fp);
    }

    while (1) {
        printf(PINK "\n===== POWERPUFF QUEST =====\n" RESET);

        if (!isLoggedIn) {
            if (!isRegistered) {
                printf(YELLOW "1. Register\n" RESET);
                printf(YELLOW "2. Login\n" RESET);
                printf(YELLOW "3. Exit\n" RESET);

                printf(CYAN "Enter Choice: " RESET);
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    if (registerUser()) {
                        isRegistered = 1;
                    }
                    break;

                case 2:
                    if (loginUser()) {
                        isLoggedIn = 1;
                    }
                    break;

                case 3:
                    printf(GREEN "\nGoodbye!\n" RESET);
                    return 0;

                default:
                    printf(RED "\nInvalid Choice!\n" RESET);
                }
            }

            else {
                printf(YELLOW "1. Login\n" RESET);
                printf(YELLOW "2. Exit\n" RESET);

                printf(CYAN "Enter Choice: "RESET);
                scanf("%d", &choice);

                switch (choice) {

                case 1:
                    if (loginUser()) {
                        isLoggedIn = 1;
                    }
                    break;

                case 2:
                    printf(GREEN "\nGoodbye!\n" RESET);
                    return 0;

                default:
                    printf(RED "\nInvalid Choice!\n" RESET);
                }
            }
        }

        else {

            printf(YELLOW "1. Start Game\n" RESET);
            printf(YELLOW "2. Exit\n" RESET);

            printf(CYAN "Enter Choice: " RESET);
            scanf("%d", &choice);

            switch (choice) {

            case 1:
                printf(GREEN "\nStarting Game...\n" RESET);
                startPowerPuff_Quest();
                break;

            case 2:
                printf(GREEN "\nGoodbye!\n" RESET);
                return 0;

            default:
                printf(RED "\nInvalid Choice!\n" RESET);
            }
        }
    }

    return 0;
}
