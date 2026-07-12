#include <stdio.h>
#include "powerpuff.h"

int main() {

    int choice;
    int isLoggedIn = 0;

    while (1) {

        printf(PINK "\n===== POWERPUFF Quest =====\n" RESET);
        printf(YELLOW "1. Register\n" RESET);
        printf(YELLOW "2. Login\n" RESET);
        printf(YELLOW "3. Start PowerPuff Quest\n" RESET);
        printf(YELLOW "6. Exit\n" RESET);

        printf(CYAN "Choice: " RESET);
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            registerUser();
            break;

        case 2:
            if (loginUser())
                isLoggedIn = 1;
            break;

        case 3:
            if (isLoggedIn)
                startPowerPuff_Quest();
            else
                printf(RED "\nPlease login first!\n" RESET);
            break;

        case 6:
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
