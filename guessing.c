// Libs
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// Defines
#define CHANCE_LENGTH 1

// Global's properties
float average;
int attempts = 0, win = 0, lose = 0;
char newChance[CHANCE_LENGTH];

bool game(int secretNumber) {
    // Local's properties
    int attemptsForGame = 3, bid;
    
    do {
        printf("| Number of guesses: %d |\n", attemptsForGame);
        printf("What is your guess? ");
        scanf("%d", &bid);
        
        if (bid == secretNumber) {
            win++;
            return true;
        }
        else {
            attemptsForGame--;
            
            if (attemptsForGame == 0) {
                lose++;
                return false;
            }
            else {
                printf("Fail!\n\n");
            }
        }
    } while (attemptsForGame > 0);
}

int main() {
    // Title
    printf("*****************\n");
    printf("* Guessing Game *\n");
    printf("*****************\n\n");
    
    // Generate random number
    srand(time(NULL));
    int secretNumber = rand() % 10;
    
    // Start game's logical
    do {
        bool result = game(secretNumber);
        
        if (attempts == 0) {
            printf("%s.", (result ? "Congratulations! You Win" : "Sorry! You Lose"));
            printf("\n\n");
        }
        
        printf("Do you want a new chance? (y/n) ");
        scanf("%s", &newChance);
            
        if (newChance == "y") {
            continue;
        }
        else {
            break;
        }
            
        // Clear variable value
        // newChance.ignore();
    } while (newChance == "n");
    
    // Analytics
    printf("\n\n");
    printf("**********************\n");
    printf("* Result's Analytics *\n");
    printf("**********************\n");
}
