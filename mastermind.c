/* 
#######################################################################################################################################
AUTHOR'S NOTE

Mastermind Game!
Based on the original Mastermind board game, now converted into a first year C Programming project.
Of all the languages to implement this, we choose to use a boomer language like C.

Honest confession from author:
- I did this project and wrote the code (alone, albeit it being a pair programming thing. I guess this is true pair programming LOL).
- This project was done back in 2017. It's 2021 now.

This is my attempt to recreate the project. Some things I hope to achieve from this:
--> Refresh my C Programming (I am Electrical & Electronic Engineering in background after all)
--> Add more C Language projects into my GitHub (*cough github.com/Shahidan101 *cough)
--> Hopefully pull this off better than 2017, after numerous years of programming in different languages (I hope this won't come
    back to bite me).

Wish me luck. May the odds ever be in my favour.

Sincerely,
Shahidan
#######################################################################################################################################
*/

// Declaring necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int getRandom(int lower, int upper);
void playerInfo(char* str);
void startGame();

int getRandom(int lower, int upper) {
	int num;
	
	num = (rand() % (upper - lower + 1)) + lower;

	return num;
}

void playerInfo(char* str) {
	char name[50];

	printf("Hi there, welcome to Mastermind!\n");
	printf("\nHOW THE GAME WORKS:\n");
	printf("- Select the difficulty\n");
	printf("- Guess the random number generated\n");
	printf("- We'll tell you if you're FAR, CLOSE, or CORRECT\n\n");

	printf("#########################################\n");
	printf("Before we start, we want to get to know you better~!\n\n");
	printf("Name: ");
	scanf("%s", name);

	strcpy(str, name);
}

void startGame() {
	const int LOWER = 1;
	const int UPPER = 10;

	int answer, chances, i, guess, difficultySelect, countguesses;

	difficultySelect = 0;
	countguesses = 0;
	// Use curent time as seed for random number generator
	srand(time(0));

	answer = getRandom(1, 10);

	while ((difficultySelect < 1) || (difficultySelect > 3)) {
		printf("Select your difficulty : \n");
		printf("1. BEGINNER [5 guesses]\n");
		printf("2. INTERMEDIATE [3 guesses]\n");
		printf("3. ADVANCED [1 guess]\n");
		printf("\nEnter the number to select [1, 2, or 3]: ");
		scanf("%d", &difficultySelect);	
	}

	switch (difficultySelect) {
		case 1: 
			chances = 5;
			break;
		case 2:
			chances = 3;
			break;
		case 3:
			chances = 1;
			break;
	}

	printf("\n\n");

	for (i = 0; i < chances; i++) {
		countguesses += 1;
		printf("Guess the number: ");
		scanf("%d", &guess);
		if ((answer - guess == 1) || (guess - answer == 1))
			printf("You are CLOSE!\n");
		else if (answer == guess) {
			printf("You are CORRECT!\n");
			break;
		}
		else
			printf("You are FAR...\n");
	}

	printf("\nAnswer is %d\n", answer);
}


int main(void) {
	char reply;
	char playerName[50];
	int countgame = -1;

	reply = 'Y';

	system("clear");

	playerInfo(playerName);

	while ((reply == 'Y') || (reply == 'y')) {
		system("clear");
		countgame += 1;
		startGame();	
		while (1) {
			printf("Want to play again, %s? [Y/N]\n", playerName);
			scanf(" %c", &reply);
			if ((reply == 'Y') || (reply == 'N') || (reply == 'y') || (reply == 'n'))
				break;
		}

		switch(reply) {
			case 'N':
			case 'n':
				printf("\nThank you for playing, %s!\n", playerName);
				break;
		}
	}
	
	return 0;
}