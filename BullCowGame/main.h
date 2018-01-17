//
//  main.h
//  Tutorial01
//
//  Created by DONGWON KIM on 1/12/18.
//  Copyright 2018 DONGWON KIM. All rights reserved.
//

#ifndef main_h
#define main_h

#include <iostream>
#include <string>

using FText = std::string;
using int32 = int;

/**
Prints Intro
*/
void PrintIntro();

/**
Starts play game
*/
void PlayGame();

/**
Returns the guess in string got by getline()

@return The string that what user put for guess.
*/
FText GetValidGuess();

/**
Prints the guess to cout

@param guess string a string input will be printed
*/
void PrintGuess(FText guess);


void PrintGameSummary();


/**
Ask play again and returns user's answer
@return bool
*/
bool AskToPlayAgain();




#endif /* main_h */