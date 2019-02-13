// Libs
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

// Defines
#define CHANCE_LENGTH 1
#define GUESSING_NUMBER 3

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Global's properties
float average;
int attempts = 0, win = 0, lose = 0, guesses = 0;
char newChance[CHANCE_LENGTH];

void asciiArt(int type) {
    switch(type) {
        // Header game
        case 0:
            printf(ANSI_COLOR_GREEN "         __          " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "       _|  |_        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "     _|      |_      " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "    |  _    _  |     " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "    | |_|  |_| |     " ANSI_COLOR_RESET "    Guessing\n");
            printf(ANSI_COLOR_GREEN " _  |  _    _  |  _  " ANSI_COLOR_RESET "        Game\n");
            printf(ANSI_COLOR_GREEN "|_|_|_| |__| |_|_|_| " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "  |_|_        _|_|   " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "    |_|      |_|     " ANSI_COLOR_RESET "\n");
            break;
        // Win game
        case 1:
            printf(ANSI_COLOR_YELLOW "  ___________        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "  \\___===___/       " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW " .-\\:      /-.      " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "( (|:.     |) )      " ANSI_COLOR_RESET "Congratulations!\n");
            printf(ANSI_COLOR_YELLOW " '-|:.     |-'       " ANSI_COLOR_RESET "   You Win!\n");
            printf(ANSI_COLOR_YELLOW "   \\::.    /        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "    '::. .'          " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "      ) (            " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "    _.'_'._          " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "    \"\"\"\"\"\"\"   " ANSI_COLOR_RESET "\n");
            break;
        // Lose game
        case 2:
            printf(ANSI_COLOR_RED "          _.--""--._        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "         / _    _ \\        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "     _  ( (_\\  /_) )  _    " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "    {  \\._\\  /\\  /_./  } " ANSI_COLOR_RESET "     Sorry\n");
            printf(ANSI_COLOR_RED "    /_'=-.}______{.-='_\\   " ANSI_COLOR_RESET " You Lose!\n");
            printf(ANSI_COLOR_RED "     _  _.=('''')=._  _     " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "    (_''_.-''~~''-._''_)    " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "     {_'            '_}     " ANSI_COLOR_RESET "\n");
            break;
    }
}

void header() {
    system("clear");
    asciiArt(0);
}

bool game(int secretNumber) {
    // Local's properties
    int attemptsForGame = GUESSING_NUMBER, bid;
    
    do {
        // Title
        if (attemptsForGame == GUESSING_NUMBER) {
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
                system("clear");
                
                if (attemptsForGame < GUESSING_NUMBER) {
                    header();
                }
                
                // Tips
                printf("You missed! %c[3mYour guess is %s than secret value.\n%c[3m", 27, bid > secretNumber ? "greater" : "smaller", 27);
            }
        }
    } while (attemptsForGame > 0);
}

void analytics() {
    system("clear");
    
    // Calculation
    int total = win + lose;
    double percentWin = ((double)win / (double)total) * 100;
    double percentLose = ((double)lose / (double)total) * 100;
    
    printf(ANSI_COLOR_MAGENTA "      _____           " ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "    /_____/\\         " ANSI_COLOR_RESET " Game Results\n");
    printf(ANSI_COLOR_MAGENTA "   /_____\\\\ \\      " ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "  /_____\\ \\\\ /     " ANSI_COLOR_RESET "   Total Games: %d\n", total);
    printf(ANSI_COLOR_MAGENTA " /_____/ \\/ / /      " ANSI_COLOR_RESET " Guesses: %d\n", guesses);
    printf(ANSI_COLOR_MAGENTA "/_____/ /   \\//\\    " ANSI_COLOR_RESET "  Lose: %d\n", lose);
    printf(ANSI_COLOR_MAGENTA "\\_____\\//\\   / /   " ANSI_COLOR_RESET "   Win: %d\n", win);
    printf(ANSI_COLOR_MAGENTA " \\_____/ / /\\ /     " ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "  \\_____/ \\\\ \\    " ANSI_COLOR_RESET "    Lose Percent: %.2f%%\n", percentLose);
    printf(ANSI_COLOR_MAGENTA "   \\_____\\ \\\\     " ANSI_COLOR_RESET "    Win Percent: %.2f%%\n", percentWin);
    printf(ANSI_COLOR_MAGENTA "    \\_____\\/        " ANSI_COLOR_RESET "\n");
}

int main() {
    // Start game's logical
    do {
        // Generate random number
        srand(time(NULL));
        int secretNumber = rand() % 10;
        
        // Start game
        bool result = game(secretNumber);
        
        if (attempts == 0) {
            printf("\n");
            asciiArt((result ? 1 : 2));
            printf("\n");
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
