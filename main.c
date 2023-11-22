#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 256 // You can adjust the maximum length of the name

int colictscore;


struct Entry {
    char YourFullName[MAX_LENGTH];
    int points;
};

// Function prototypes
void Save_name();
void titel_game();
void titel_Score();
int compareEntries(const void *a, const void *b);

int main() {
    // Start menu //
    int farstwant;
    printf(" 1: Start\n 2: top Score\n 3: Exit\n");
    printf("Select the number 1 or 2 or 3 : ");
    scanf("%d", &farstwant);
    printf("\n");

    // if you select Start or top Score or Exit//
    if (farstwant == 2) {
        titel_Score();
         printf("\n\n");

        int menu ;
        printf("do you want Return to the start menu ?\n1: Return\n2: Exit\n-Select 1 or 2: ");
        scanf("%d", &menu );
        printf("\n");
        if (menu  == 1) { // Play again
            getchar();
            system("cls");
            main();

        } else {
        return 0;
        }
        return 0;
    } else if (farstwant == 3) {
        return 0;
    }

    //  the number 1 or 2 or 3 : //
    int NumDigits;
    printf("Select the number\n 1: 3\n 2: 5\n 3: 7\n");
    printf("Select the number 1 or 2 or 3 : ");
    scanf("%d", &NumDigits);
    printf("\n");

    // Repeat if the number is not required //
    while (NumDigits < 1 || NumDigits > 3) {
        printf("Select the number 1 or 2 or 3 : ");
        scanf("%d", &NumDigits);
        printf("\n");
    }
    int maxAttempts; // Set the maximum number of attempts //
    printf("how much attempts you want : ");
    scanf("%d", &maxAttempts);
    printf("\n");

    // Attempts Score
    int AttemptsScore = maxAttempts/2;

    //  same location or Not in the same location.
    int testo;
    printf("- Select what do you want -\n 1: same location.\n 2: Not in the same location.\n\n");
    printf("- Select the number 1 or 2 : ");
    scanf("%d", &testo);
    printf("\n");

    int sameAttempts;
        if (sameAttempts == 1) {
        colictscore = colictscore *2;
    }
    while (testo < 1 || testo > 2) {
        printf("- Select the number 1 or 2 : ");
        scanf("%d", &testo);
        printf("\n");
    }

    // Delete all of the above //
    getchar();
    system("cls");
    titel_game();
    printf("\n\n");

    // Convert the number to "*" etc. //
    if (NumDigits == 1) {
        NumDigits = 3;
        colictscore = 100;
    } else if (NumDigits == 2) {
        NumDigits = 5;
        colictscore = 300;
    } else {
        colictscore = 500;
        NumDigits = 7;
    }
    // random number //
    srand(time(NULL));
    int randomNum[7]; // maximum number of random numbers is 7 //

    printf("Random numbers : ");
    for (int i = 0; i < NumDigits; ++i) {
        int newRandom;
        int isDuplicate;

        do {
            isDuplicate = 0;
            newRandom = rand() % 20 + 1;

            // Check if the new number is already in the array //
            for (int j = 0; j < i; ++j) {
                if (newRandom == randomNum[j]) {
                    isDuplicate = 1;
                    break;
                }
            }

        } while (isDuplicate);

        randomNum[i] = newRandom;
        printf("* ");
    }
    printf("\n");

    // Check whether the entry is valid or no //
    int corrGuess = 0;
    int guessedNum[7] = {0}; // guessed numbers array //

    if (testo == 1) {
        printf("-you Select :same location.\n");
    } else if (testo == 2) {
        printf("-you Select :Not in the same location.\n");
    }

    printf("Write %d numbers in each attempt - \n", NumDigits);
    for (int attempt = 1; attempt <= maxAttempts && corrGuess < NumDigits; ++attempt) {
        // Enter a guess // Array //
        printf("Attempt %d - Guess the numbers: ", attempt);
        // Array userGuess //
        int userGuess[7];
        for (int i = 0; i < NumDigits; ++i) {
            scanf("%d", &userGuess[i]);
        }

        // Check if the guessed number matches any of the random numbers //
        if (testo == 1) { // Check for same location
            for (int i = 0; i < NumDigits; ++i) {
                if (userGuess[i] == randomNum[i] && guessedNum[i] == 0) {
                    guessedNum[i] = userGuess[i];
                    corrGuess++;
                }
            }
        } else if (testo == 2) { // Check for not in the same location
            for (int i = 0; i < NumDigits; ++i) {
                for (int j = 0; j < NumDigits; ++j) {
                    if (userGuess[i] == randomNum[j] && guessedNum[j] == 0) {
                        guessedNum[j] = userGuess[i];
                        corrGuess++;
                        break;
                    }
                }
            }
        }
        // Print the current state of guessed numbers
        for (int k = 0; k < NumDigits; ++k) {
            if (guessedNum[k] != 0) {
                printf("%d ", guessedNum[k]);
            } else {
                printf("* ");
            }
        }


        if (attempt <= AttemptsScore) {
            colictscore = colictscore * 3;
        } else {
            colictscore = colictscore * 1.5;
        }

        printf("\n");
    }


    // You won or not //
    if (corrGuess < NumDigits) {
        printf("\n");
        printf("Sorry, you couldn't guess all the numbers in %d attempts. You lost.\n", maxAttempts);
    } else {
        printf("\n");
        printf("Congrats! You guessed all the numbers.\n -You won 5$ million \n\n\n");
        printf("Your score is : %d",colictscore);
        printf("\n\n");
        int saveTest;
        printf("Do you want to save your score?\n1: Yes\n2: No\nSelect 1 or 2: ");
        scanf("%d", &saveTest);
        printf("\n");

    if (saveTest == 1) { // save
        Save_name();
        printf("Data saved to file successfully.\n");
    } else {
        return 0;
    }
    }

        int reaptegame;
        printf("Do you want Play again?\n1: Yes\n2: No\nSelect 1 or 2: ");
        scanf("%d", &reaptegame);
        printf("\n");
        if (reaptegame == 1) { // Play again
            getchar();
            system("cls");
            main();

        } else {
        return 0;
        }

    return 0;
}

void titel_game() {
    printf("===========================================================================\n");
    printf("=================    Start guessing random numbers     ====================\n");
    printf("===========================================================================\n");
}

void titel_Score() {
    printf("======================================================\n");
    printf("=================    Top Score    ====================\n");
    printf("======================================================\n");

    FILE *file = fopen("output.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    struct Entry entries[100];  // Assuming a maximum of 100 entries, adjust as needed

    // Read entries from the file
    int i = 0;
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file) != NULL && i < 100) {
        // Use sscanf to extract name and points from the line
        if (sscanf(line, "Full Name: %s Points: %d", entries[i].YourFullName, &entries[i].points) == 2) {
            i++;
        }
    }

    fclose(file);

    // Sort entries by points in descending order
    qsort(entries, i, sizeof(struct Entry), compareEntries);

    // Display the top 10 names and points
    printf("\n");
    int displayCount = i < 10 ? i : 10;
    for (int j = 0; j < displayCount; j++) {
        printf("Top %d: %s - Points: %d\n", j + 1, entries[j].YourFullName, entries[j].points);
    }
    printf("\n");
    printf("======================================================\n");
    printf("======================================================\n");
    printf("======================================================\n");
}

void Save_name() {
    char YourFullName[MAX_LENGTH];

    // Prompt user for name
    printf("Enter your full name: ");
    scanf("%s", YourFullName);

    FILE *file = fopen("output.txt", "a");

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return;
    }

    // Write the name and points to the file
    fprintf(file, "Full Name: %s Points: %d\n", YourFullName, colictscore);

    fclose(file);
}


// Comparator function for qsort
int compareEntries(const void *a, const void *b) {
    return ((struct Entry *)b)->points - ((struct Entry *)a)->points;
}
