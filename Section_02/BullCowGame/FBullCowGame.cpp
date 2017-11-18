#include "FBullCowGame.h"

using int32 = int;


void FBullCowGame::Reset() 
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) 
{
	return false;
}

BullCowcount FBullCowGame::SubmitGuess(FString)
{
	//Increment the turn number
	MyCurrentTry++;

	//setup a return variable
	BullCowcount Bullcowcount;

	//loop through all letters in the guess
		//compare letters against the hidden word

	return Bullcowcount;
}

