/**
* FBullCowGame.cpp
* Tutorial01
* Created by DONGWON KIM on 1/12/18.
* Copyright 2018 DONGWON KIM. All rights reserved.
**/

#include "FBullCowGame.h"


FBullCowGame::FBullCowGame() { Reset(); }

// public () const
int32 FBullCowGame::GetMaxTries() const {
	
	// <WordLength, MaxTries>
	TMap<int32, int32> WordLengthToMaxTries{ {3, 5}, {4, 5}, {5, 5}, {6, 5} };

	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrnetTry() const { return  MyCurrentTries; }

int32 FBullCowGame::GetHiddenWordLength() const { return  (int32)MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidty(FString Guess) const {

	// TODO write function
	if (!IsIsogram(Guess)) { // if the guess isn't isogram
		return EGuessStatus::Not_Isogram; // return error
										  // TODO write function
	} else if (!IsLowerCase(Guess)) { // if the guess isn't all lower case

		return EGuessStatus::Not_Lowercase; // return error
	} else if (Guess.length() != GetHiddenWordLength()) { //if the guess length is worng
		return EGuessStatus::Wrong_Length; // return Error

	} else { // if everything is ok
		return EGuessStatus::OK;
	}

}

// public
void FBullCowGame::Reset() {

	const FString HIDDEN_WORD = "planet";

	constexpr int32 START_TRIES = 1;
	constexpr int32 MAX_TRIES = 8;

	MyCurrentTries = START_TRIES;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;

	return;
}


// receives a valid guess, increments current turn, and return counts
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {

	this->MyCurrentTries++;
	FBullCowCount BullCowCount;
	int32 WordLength = (int32)MyHiddenWord.length(); // assuming same length as guess

													 // loop through all letters in the Hiddenword
	for (int MHWChar = 0; MHWChar < WordLength; ++MHWChar) {
		// loop through all letter in the guess
		for (int GChar = 0; GChar < WordLength; ++GChar) {
			// if they match
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	// when its 0 will be true
	bGameIsWon = (MyHiddenWord.compare(Guess) == 0);

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {

	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;

	for (char Letter : Word) {
		Letter = tolower(Letter);

		if (LetterSeen[Letter] == true) {
			return false;
		} else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const {

	if(Word.length() != 0 && Word[0] != '\0')
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}

	return true;
}

/**  note
 *  Avoid Implicit dependencies
 *  Implicit: suggested though not directly expressed.
 *  Dependent: reliant on something else
 *  
 *  An implicit Dependency is when its not completely clear that
 *  one thing depends on another. For example the order of checks in
 *  CheckGuessValidity()
 */
