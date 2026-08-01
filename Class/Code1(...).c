#include <stdio.h>
#include <string.h>
// Console text formatting-er color code
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PINK "\033[1;35m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

// ---------- REGISTER FUNCTION ----------
void registerUser() {
    char username[50], password[50];
    // File append mode-e open korchi
    FILE *fp = fopen("users.txt", "a");
    if (!fp) return;

    printf(CYAN "\nEnter Username: " RESET);
    scanf("%49s", username);

    printf(CYAN "Enter Password: " RESET);
    scanf("%49s", password);

    // Users.txt file-e username ar password save kora
    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf(GREEN "Registration Successful!\n" RESET);
}

// ---------- LOGIN FUNCTION ----------
int loginUser() {
    char username[50], password[50];
    char fileUsername[50], filePassword[50];

    // File read mode-e open kora
    FILE *fp = fopen("users.txt", "r");
    if (!fp) {
        printf(RED "No users found! Register first.\n" RESET);
        return 0;
    }

    printf(CYAN "\nEnter Username: " RESET);
    scanf("%49s", username);

    printf(CYAN "Enter Password: " RESET);
    scanf("%49s", password);

    // File theke ekta ekta kore line read kore match kora
    while (fscanf(fp, "%49s %49s", fileUsername, filePassword) == 2) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            fclose(fp);
            printf(GREEN "Login Successful!\n" RESET);
            return 1; // Match hole 1 return korbe
        }
    }

    fclose(fp);
    printf(RED "Invalid credentials!\n" RESET);
    return 0; // Match na hole 0
}

// ---------- GAME CORE ----------
void startPowerPuff_Quest() {
    int hp = 100, maxHP = 100, attack = 15, choice;
    // Monsters ar skills list
    char *monsters[5] = {"Fuzzy Lumpkins", "Mojo Jojo", "Sedusa", "Gangreen Gang", "HIM"};
    int monsterHP[5] = {50, 60, 70, 80, 100};
    int monsterAttack[5] = {10, 12, 14, 16, 20};
    char *absorbedSkills[5] = {"Freeze Ray", "Sonic Scream", "Laser Eye", "Thunder Clap", "Ultimate Power"};
     // Short Team Dialogue
    printf(PURPLE "\n[Blossom]: Girls, Townsville needs us!\n" RESET);
    printf(PURPLE "[Bubbles]: Let's do this!\n" RESET);
    printf(PURPLE "[Buttercup]: Time to smash villains!\n" RESET);
    // Hero Selection
    printf(PINK "\nChoose Character (1. Blossom  2. Bubbles  3. Buttercup): " RESET);
    scanf("%d", &choice);
    if (choice == 1) {
        hp = maxHP = 120; attack = 20;
    } else if (choice == 3) {
        hp = maxHP = 110; attack = 25;
    }
    // Main 5 Levels Loop
    for (int i = 0; i < 5; i++) {
        printf(YELLOW "\n--- LEVEL %d: %s ---\n" RESET, i + 1, monsters[i]);

        // Fight Loop (Jotokhon dono jon er HP 0 er upore thakbe)
        while (hp > 0 && monsterHP[i] > 0) {
            printf("\nYour HP: %d | Monster HP: %d\n", hp, monsterHP[i]);
            printf("1. Attack  2. Heal (+10 HP)\nChoice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                monsterHP[i] -= attack; // Attack hit
            } else if (choice == 2) {
                hp = (hp + 10 > maxHP) ? maxHP : hp + 10; // Heal (Max HP-er beshi hobe na)
            } else {
                continue;
            }
            // Boss defeated hole loop break
            if (monsterHP[i] <= 0) break;
            // Monster attack hit
            hp -= monsterAttack[i];
            printf(RED "%s hit you for %d damage!\n" RESET, monsters[i], monsterAttack[i]);
        }
        // Player maro gele Game Over
        if (hp <= 0) {
            printf(RED "\nGAME OVER!\n" RESET);
            return;
        }
       // Level Clear Rewards
        attack += 5; // Skill absorb hoye permanent Attack boost hobe
        hp = (hp + 20 > maxHP) ? maxHP : hp + 20; // Auto heal bonus
        printf(GREEN "Level Clear! Absorbed Skill: '%s' (+5 Attack Power)\n" RESET, absorbedSkills[i]);
    }

    printf(PINK "\nYOU WIN! All villains defeated and Townsville is saved!\n" RESET);
}
// ---------- MAIN MENU ----------
int main() {
    int choice;
    int isRegistered = 0;
    int isLoggedIn = 0;
    while (1) {
        printf(PINK "\n===== PowerPuff Quest =====\n" RESET);
        // Stage onujayi Menu text change hobe
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
            } else if (!isLoggedIn) {
                if (loginUser()) {
                    isLoggedIn = 1;
                }
            } else {
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
