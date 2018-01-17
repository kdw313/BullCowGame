//
//  FBullCowGame.h
//  Tutorial01
//
//  Created by DONGWON KIM on 1/12/18.
//  Copyright © 2018 DONGWON KIM. All rights reserved.
//

/*
With #ifndef guards, the compiler can safely read any file it isn't sure it has seen already; if it's wrong, it just has to do some extra work. ... #pragma once has no such safety net -- if the compiler is wrong about the identity of a header file, either way, the program will fail to compil
*/

#ifndef FBullCowGame_h 
#define FBullCowGame_h

#include <string>
#include <map>

// to make synatx unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

// using namespace is inappropriate in header


// all values initialized to zero
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

enum class EResetStatus {
	OK,
	No_Hidden_Word
};

class FBullCowGame {


public:

	FBullCowGame(); // default constructor

	// methods const
	int32 GetMaxTries() const;
	int32 GetCurrnetTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidty(FString Guess) const;

	// methods
	void Reset();

	// Provide a method for counting bull & cow, and increasing turn #
	FBullCowCount SubmitValidGuess(FString Guess);


private:
	
	// See Constructor for initialization
	int32 MyCurrentTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString Word) const;
	bool IsLowerCase(FString word) const;
};


#endif /* FBullCowGame_h */
