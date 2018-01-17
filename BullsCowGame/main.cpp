/**
* main.cpp
* Tutorial01
* Created by DONGWON KIM on 1/11/18.
* Copyright 2018 DONGWON KIM. All rights reserved.
*
* @author Dongwon Kim
* @version 1.0 1/11/18
*/

#include <iostream>
#include "main.h"
#include "FBullCowGame.h"


FBullCowGame BCGame;

// Controls operation of the program.
int main(int32 argc, const char * argv[]) {

	do {
		PrintIntro();
		PlayGame();

	} while (AskToPlayAgain());

	return 0;
}


void PrintIntro() {

	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl << std::endl;

	return;
}

void PlayGame() {

	BCGame.Reset();

	//    std::cout << BCGame.GetMaxTries() << std::endl;
	int32 MaxTries = (int32)BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses while the game is not won
	// and there are still tries remaining
	while (!(BCGame.IsGameWon()) && (BCGame.GetCurrnetTry() <= MaxTries)) {

		FText Guess = GetValidGuess();

		// submit Valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		// print of number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO add a game summary
	PrintGameSummary();

	return;
}


// loop continuously until user give valid guess
FText GetValidGuess() { // TODO change to get valid guess

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do {
		std::cout << "Try " << BCGame.GetCurrnetTry() << " of " << BCGame
			.GetMaxTries() << ". Enter your guess: ";

		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidty(Guess);
		switch (Status) {
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;

		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a \"" << BCGame.GetHiddenWordLength() << "\" letter word.\n\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a word with lowercase.\n\n";
			break;

		default: // assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until get valid error

	return Guess;
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "You won congrats\n" << std::endl;
	}
	else {

		std::cout << "Bad Luck\n" << std::endl;
	}

	return;
}


bool AskToPlayAgain() {

	std::cout << "Do you want to play again? with the same word? ";
	FText response = "";

	getline(std::cin, response);

	std::cout << std::endl;
	return (response[0] == 'y' || response[0] == 'Y');
}
