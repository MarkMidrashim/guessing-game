// Libs
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

// Defines
#define CHANCE_LENGTH 1

// Global's properties
float average;
int attempts = 0, win = 0, lose = 0, guesses = 0;
char newChance[CHANCE_LENGTH];

void header() {
    printf("*****************\n");
    printf("* Guessing Game *\n");
    printf("*****************\n");
}

bool game(int secretNumber) {
    // Local's properties
    int attemptsForGame = 3, bid;
    
    do {
        // Title
        if (attemptsForGame == 3) {
            header();
        }
        
        printf("\n| Attempts: %d |\n", attemptsForGame);
        printf("What is your guess? ");
        scanf("%d", &bid);
        guesses++;
        
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
                // Clear console
                system("clear");
                
                if (attemptsForGame < 3) {
                    header();
                }
                
                printf("You missed! ");
                
                // Tips
                if (bid > secretNumber) {
                    printf("%c[3mYour guess is greater than secret value.\n%c[0m", 27, 27);
                }
                
                if (bid < secretNumber) {
                    printf("%c[3mYour guess is smaller than secret value.\n%c[0m", 27, 27);
                }
            }
        }
    } while (attemptsForGame > 0);
}

void analytics() {
    // Clear console
    system("clear");
    
    // Calculation
    int total = win + lose;
    double percentWin = ((double)win / (double)total) * 100;
    double percentLose = ((double)lose / (double)total) * 100;
    
    printf("****************\n");
    printf("* Game Results *\n");
    printf("****************\n");
    printf("Total Games: %d\n", total);
    printf("Guesses: %d\n", guesses);
    printf("Lose: %d\n", lose);
    printf("Win: %d\n", win);
    printf("--- Percents ---\n");
    printf("Win: %.2f%%\n", percentWin);
    printf("Lose: %.2f%%\n", percentLose);
}

int main() {
    // Start game's logical
    do {
        // Generate random number
        srand(time(NULL));
        int secretNumber = rand() % 10;
        
        bool result = game(secretNumber);
        
        if (attempts == 0) {
            printf("\n%s.", (result ? "Congratulations! You Win" : "Sorry! You Lose"));
            printf("\n\n");
        }
        
        printf("Do you want a new chance? (y/n) ");
        scanf("%s", &newChance[0]);
        
        if (strcmp("n", newChance) == 0) {
            break;
        }
        else {
            system("clear");
        }
    } while (true);
    
    // Analytics
    analytics();
}
