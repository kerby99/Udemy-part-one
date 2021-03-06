/*This the console executable, that makes use of the bullcow class.
This axts as the view in the MVC pattern, and is responsible for all 
user interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCgame; //instantiate a new game

//the entry point for our application
int main(){
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0; //exit the app
}

void PrintIntro() {
	//introduce the game
	std::cout << "Welcome to Bulls and Cows!" << std::endl;
	std::cout << "Can you guess the " << BCgame.GetHiddenWordLength();
	std::cout << " letters isogram I'm thinking of?\n" << std::endl;
	return;
}

void PlayGame()
{
	BCgame.Reset();
	int32 MaxTries = BCgame.GetMaxTries();

	//loop for guesses while the game is NOT won
	// until there a still tries remaining
	
	while (!BCgame.IsGameWon() && BCgame.GetCurrentTry() <= MaxTries)
	{ 
		Ftext guess = GetValidGuess(); 

		//Submit values guess to the game
		FBullCowcount BullCowCount =  BCgame.SubmitValidGuess(guess);
		//Print numbers of bull and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
		std::cout << "You enter : " << guess << "\n\n";
	}
	PrintGameSummary();
	return;
}

// loop continually until the user gives a valid guess
Ftext GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	Ftext guess = "";
	do {
		//Get a guess from the player
		int32 CurrnetTries = BCgame.GetCurrentTry();
		std::cout << "Try : " << CurrnetTries << " of " << BCgame.GetMaxTries(); 
		std::cout << "\nEnter your guess : ";
		std::getline(std::cin, guess);

		// check status and give feedback
		Status = BCgame.CheckGuessValidity(guess);
		switch (Status)
		{
		case EGuessStatus::Wromg_lenght:
			std::cout << "Please enter a " << BCgame.GetHiddenWordLength() << " letter word. \n\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)";
	Ftext Reponse = "";
	std::getline(std::cin, Reponse);
	return (Reponse[0] == 'y') || (Reponse[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCgame.IsGameWon()) 
	{
		std::cout << "GG You win!!!\n";
	}
	else 
	{
		std::cout << "That's sad :( Better luck next time...\n";
	}
}