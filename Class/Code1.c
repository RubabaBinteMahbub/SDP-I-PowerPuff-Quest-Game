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
// Global skill states
int unlockedSkillsCount = 0;

// ---------- REGISTER ----------
void registerUser() {
    char username[50], password[50];

    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        perror(RED "File error" RESET);
        return;
    }
    printf(CYAN "\nEnter Username: " RESET);
    scanf("%49s", username);

    printf(CYAN "Enter Password: " RESET);
    scanf("%49s", password);

    fprintf(fp, "%s %s\n", username, password);
    fflush(fp);
    fclose(fp);

    printf(GREEN "\nRegistration Successful!\n" RESET);
    printf(GREEN "Saved to users.txt (same folder as this program's .exe).\n" RESET);
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

    printf(CYAN "\nEnter Username: " RESET);
    scanf("%49s", username);

    printf(CYAN "Enter Password: " RESET);
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

// ---------- TEAM DIALOGUES ----------
void teamDialogue(int stage) {
    printf(PURPLE "\n--- Girls Team Dialogue ---\n" RESET);
    if (stage == 1) {
        printf(PINK "Blossom: " RESET "Girls! Townsville needs us. Let's stick together!\n");
        printf(BLUE "Bubbles: " RESET "I brought Octi for good luck!\n");
        printf(GREEN "Buttercup: " RESET "Enough talking, let's smash some villains!\n");
    } else if (stage == 2) {
        printf(PINK "Blossom: " RESET "Awesome fight! Let's take a break at the Save Point.\n");
        printf(BLUE "Bubbles: " RESET "Yay! Rest time! My health is fully back now!\n");
        printf(GREEN "Buttercup: " RESET "And we consumed enemy powers too! Next target is gonna pay!\n");
    } else if (stage == 3) {
        printf(PINK "Blossom: " RESET "Final Boss is right ahead. Stay sharp!\n");
        printf(BLUE "Bubbles: " RESET "We can do this team!\n");
        printf(GREEN "Buttercup: " RESET "Let's finish this!\n");
    }
    printf(PURPLE "---------------------------\n" RESET);
}

// ---------- REST AREA / SAVE POINT ----------
void restArea(int *hp, int maxHP) {
    printf(CYAN "\n=========================================\n" RESET);
    printf(CYAN "       REST AREA / SAVE POINT           \n" RESET);
    printf(CYAN "=========================================\n" RESET);

    // Play team conversation
    teamDialogue(2);

    // Heal to max
    *hp = maxHP;
    printf(GREEN "\nAll Powerpuff Girls rested! HP fully restored to %d!\n" RESET, maxHP);
    printf(YELLOW "Skills Unlocked So Far: %d Skills (Boosted Attack!)\n" RESET, unlockedSkillsCount);
    printf(CYAN "Press Enter to continue..." RESET);
    getchar(); getchar();
}

// ---------- GAME CORE ----------
void startPowerPuff_Quest() {
    int hp, maxHP, attack, choice;

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

    char *absorbedSkills[5] = {
        "Freeze Ray",
        "Sonic Scream",
        "Laser Eye",
        "Thunder Clap",
        "Ultimate Power"
    };

    printf(PINK "\nChoose Your Powerpuff Girl\n" RESET);
    printf(PINK "1. Blossom\n" RESET);
    printf(BLUE "2. Bubbles\n" RESET);
    printf(GREEN "3. Buttercup\n" RESET);
    printf(CYAN "Choice: " RESET);
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
            printf(RED "Invalid Choice!\n" RESET);
            return;
    }

    maxHP = hp; // Save initial base max HP
    unlockedSkillsCount = 0;

    // Intro Dialogue
    teamDialogue(1);

    for (int i = 0; i < 5; i++) {

        // --- SAVE POINT EVERY 2 FIGHTS (After Level 2 and Level 4) ---
        if (i > 0 && i % 2 == 0) {
            restArea(&hp, maxHP);
        }

        printf("\n%sLEVEL %d%s\n", monsterColor[i], i + 1, RESET);
        printf("%sMonster: %s%s\n", monsterColor[i], monsters[i], RESET);

        while (hp > 0 && monsterHP[i] > 0) {

            printf("\nYour HP: %d | Attack: %d\n", hp, attack);
            printf("Monster HP: %d\n", monsterHP[i]);

            printf(YELLOW "1. Attack\n" RESET);
            printf(YELLOW "2. Heal (+10 HP)\n" RESET);
            printf(CYAN "Choice: " RESET);
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    monsterHP[i] -= attack;
                    printf("You attacked!\n");
                    break;

                case 2:
                    hp += 10;
                    if (hp > maxHP) hp = maxHP; // Prevent over-healing
                    printf("You healed!\n");
                    break;

                default:
                    printf(RED "Invalid move!\n" RESET);
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

        printf(GREEN "\nLevel %d Complete!\n" RESET, i + 1);

        // --- SKILL CONSUMPTION FEATURE ---
        attack += 5; // Permanent attack boost per skill absorbed
        unlockedSkillsCount++;
        printf(CYAN "SKILL CONSUMED: You absorbed '%s' from %s! (+5 Attack Power)\n" RESET,
               absorbedSkills[i], monsters[i]);

        hp += 15;
        if (hp > maxHP) hp = maxHP;
    }

    // Final Victory Dialogue
    teamDialogue(3);
    printf(PINK "\nYOU WIN! All villains defeated and Townsville is saved!\n" RESET);
}

// ---------- MAIN MENU ----------
int main() {
    int choice;
    int isRegistered = 0;   // becomes 1 right after a successful registration
    int isLoggedIn = 0;     // becomes 1 right after a successful login

    while (1) {
        printf(PINK "\n===== PowerPuff Quest =====\n" RESET);

        if (!isRegistered) {
            printf(YELLOW "1. Register\n" RESET);
        } else if (!isLoggedIn) {
            printf(YELLOW "1. Login\n" RESET);
        } else {
            printf(YELLOW "1. Start Game\n" RESET);
        }
        printf(YELLOW "2. Exit\n" RESET);
        printf(CYAN "Choice: " RESET);
        scanf("%d", &choice);

        if (choice == 1) {

            if (!isRegistered) {
                registerUser();
                isRegistered = 1;
            }
            else if (!isLoggedIn) {
                if (loginUser()) {
                    isLoggedIn = 1;
                }
            }
            else {
                startPowerPuff_Quest();
            }

        } else if (choice == 2) {
            printf(GREEN "Goodbye!\n" RESET);
            return 0;
        } else {
            printf(RED "Invalid Choice!\n" RESET);
        }
    }
}
