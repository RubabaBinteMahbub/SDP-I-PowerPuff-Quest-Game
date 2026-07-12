#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define PINK "\033[1;35m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

void registerUser() {
    char username[50], password[50];

    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf(RED "File error!\n" RESET);
        return;
    }

    printf(CYAN"\nEnter Username: "RESET);
    scanf("%49s", username);

    printf(CYAN"Enter Password: "RESET);
    scanf("%49s", password);

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf(GREEN "\nRegistration Successful!\n" RESET);
    printf(GREEN "Now, please login to play the game!\n" RESET);
}

int loginUser() {
    char username[50], password[50];
    char fileUser[50], filePass[50];

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf(RED "\nNo users found! Please register first.\n" RESET);
        return 0;
    }

    printf(CYAN"\nEnter Username: "RESET);
    scanf("%49s", username);

    printf(CYAN"Enter Password: "RESET);
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

int main(){
    int choice;
     int isLoggedIn = 0;
    while(1){
        printf(PINK"\n=====PowerPuff Quest=====\n"RESET);
        printf(YELLOW"1. Register\n"RESET);
        printf(YELLOW"2. Login\n"RESET);
        printf(YELLOW"3. Start PowerPuff Quest\n"RESET);

        printf(CYAN"Choice: "RESET);
        scanf("%d",&choice);

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
                    //startPowerPuff_Quest();
                    printf(WHITE"Now the game will start. Function is not made yet."RESET);
               }
              else{
                    printf(RED "\nPlease login first!\n" RESET);
               }
               break;
          }
    }

    return 0;
}
