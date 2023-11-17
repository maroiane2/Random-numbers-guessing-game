#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
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
    // Convert the number to "*" etc. //
    if (NumDigits == 1) {
        NumDigits = 3;
    } else if (NumDigits == 2) {
        NumDigits = 5;
    } else {
        NumDigits = 7;
    }

    // random number //
    srand(time(NULL));
    int randomNum[7]; // maximum number of random numbers is 7 //

    printf("Random numbers : ");
    for (int i = 0; i < NumDigits; ++i) {
        randomNum[i] = rand() % 20 + 1;
        printf("* ");
    }
    printf("\n");

    // Check whether the entry is valid or no //
    int corrGuess = 0;
    int guessedNum[7] = {0}; // guessed numbers array //

    printf("Write %d numbers in each attempt - \n",NumDigits);
    for (int attempt = 1; attempt <= maxAttempts && corrGuess < NumDigits; ++attempt) {
        // Enter a guess // Array //
        printf("Attempt %d - Guess the numbers: ", attempt);
        // Array userGuess //
        int userGuess[7];
        for (int i = 0; i < NumDigits; ++i) {
            scanf("%d", &userGuess[i]);
        }

        // Check if the guessed number matches any of the random numbers //
        for (int i = 0; i < NumDigits; ++i) {
            for (int j = 0; j < NumDigits; ++j) {
                if (userGuess[i] == randomNum[j] && guessedNum[j] == 0) {
                    guessedNum[j] = userGuess[i];
                    corrGuess++;

                    for (int k = 0; k < NumDigits; ++k) {
                        if (guessedNum[k] != 0) {
                            printf("%d ", guessedNum[k]);
                        } else {
                            printf("* ");
                        }
                    }// loop : k
                    printf("\n");
                }// if (userGuess[i] == randomNum[j] && guessedNum[j] == 0)
            }// loop : j
        }// loop : i
    }// attempt

    // You won or not //
    if (corrGuess < NumDigits) {
        printf("\n");
        printf("Sorry, you couldn't guess all the numbers in %d attempts. You lost.\n", maxAttempts);
    } else {
        printf("\n");
        printf("Congrats! You guessed all the numbers.\n -You won 5$ million \n\n\n");
    }

    getch();
    return 0;
}
