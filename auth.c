#include <stdio.h>
#include <string.h>
#include "powerpuff.h"

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
