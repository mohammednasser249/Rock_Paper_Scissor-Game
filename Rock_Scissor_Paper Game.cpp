#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;


enum enChoices { Rock = 1, Paper = 2, Scissor = 3 }; // three choices of the game 

int GetRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int ReadNumber(string msg)
{
	int Number;
	cout << msg << endl;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Invalid input Please enter input again :\n";
		cin >> Number;
	}

	while (Number < 0 || Number>10)
	{
		cout << "Input is out of range ( 1 - 10 ) : ";
		cin >> Number;
	}

	return Number;


}

struct stRound {

	enChoices UserChoice;
	enChoices ComputerChoice;
	string Winner = "";


};

struct stGameInfo {

	int RoundNumbers = 0;
	stRound NumberOfRounds[10];
	int Player1WonTimes = 0;
	int ComputerWonTimes = 0;
	int Drawtimes = 0;

};


enChoices GetUserChoice()
{
	enChoices Choice;
	short number;
	cin >> number;

	return (enChoices)number;


}

enChoices GetComputerChoice()
{

	return (enChoices)GetRandomNumber(1, 3);
}


string GetUserChoiceName(stGameInfo Game)
{

	switch (Game.NumberOfRounds[Game.RoundNumbers - 1].UserChoice)
	{

	case enChoices::Paper:
		return "Paper";
		break;

	case enChoices::Rock:
		return "Rock";
		break;

	case enChoices::Scissor:
		return "Scissior";
		break;
	default:
		break;
	}


}

string GetComputerChoiceName(stGameInfo Game)
{

	switch (Game.NumberOfRounds[Game.RoundNumbers - 1].ComputerChoice)
	{

	case enChoices::Paper:
		return "Paper";
		break;

	case enChoices::Rock:
		return "Rock";
		break;

	case enChoices::Scissor:
		return "Scissior";
		break;
	default:
		break;
	}

}

string GetRoundWinner(stGameInfo& Game)
{

	if (Game.NumberOfRounds[Game.RoundNumbers - 1].UserChoice == Game.NumberOfRounds[Game.RoundNumbers - 1].ComputerChoice)
	{
		system("color 1f");
		Game.Drawtimes++;
		Game.NumberOfRounds[Game.RoundNumbers - 1].Winner = "No winner";
		return "[No winner]";

	}

	if (Game.NumberOfRounds[Game.RoundNumbers - 1].UserChoice == enChoices::Paper && Game.NumberOfRounds[Game.RoundNumbers - 1].ComputerChoice == enChoices::Rock)
	{
		system("color 2f");
		Game.Player1WonTimes++;
		Game.NumberOfRounds[Game.RoundNumbers - 1].Winner = "Player 1";
		return "[Player 1]";
	}
	else if (Game.NumberOfRounds[Game.RoundNumbers - 1].UserChoice == enChoices::Scissor && Game.NumberOfRounds[Game.RoundNumbers - 1].ComputerChoice == enChoices::Paper)
	{
		system("color 2f");
		Game.Player1WonTimes++;
		Game.NumberOfRounds[Game.RoundNumbers - 1].Winner = "Player 1";
		return "[Player 1]";

	}
	else if (Game.NumberOfRounds[Game.RoundNumbers - 1].UserChoice == enChoices::Rock && Game.NumberOfRounds[Game.RoundNumbers - 1].ComputerChoice == enChoices::Scissor)
	{
		system("color 2f");
		Game.Player1WonTimes++;
		Game.NumberOfRounds[Game.RoundNumbers - 1].Winner = "Player 1";
		return "[Player 1]";

	}
	else
	{
		system("color 4f");
		Game.ComputerWonTimes++;
		Game.NumberOfRounds[Game.RoundNumbers - 1].Winner = "Computer";
		return "[Computer]";

	}
}

void PrintRoundInfo(stGameInfo& Game)
{
	Game.RoundNumbers++;
	cout << "\n-----------------------" << "Round [" << Game.RoundNumbers << "] ----------------------" << endl;
	cout << "Player 1 Choice : " << GetUserChoiceName(Game) << endl;
	cout << "Computer Choice : " << GetComputerChoiceName(Game) << endl;
	cout << "Round winner : " << GetRoundWinner(Game) << endl;
	cout << "-------------------------------------------------------" << endl;
}

void PlayRound(stGameInfo& Game, int RoundNumber)
{

	cout << "Your choice : [1]:Rock , [2] Paper , [3] Scissor ? ";
	Game.NumberOfRounds[RoundNumber].UserChoice = GetUserChoice();
	Game.NumberOfRounds[RoundNumber].ComputerChoice = GetComputerChoice();
	PrintRoundInfo(Game);
}

void PlayGame(stGameInfo& Game, int NumberOfRounds)
{

	for (int i = 0; i < NumberOfRounds; i++)
	{
		cout << "\nRound " << i + 1 << " begins :\n\n";
		PlayRound(Game, i);
	}

}


void ResetGame(stGameInfo& Game)
{
	Game.RoundNumbers = 0;
	system("color 0f");
	system("cls");
}


string PrintTaps(int number)
{
	string t = "";
	for (int i = 0; i < number; i++)
	{
		t += '\t';
	}

	return t;
}

string GetFinalWinner(stGameInfo Game)
{

	if (Game.Player1WonTimes > Game.ComputerWonTimes)
		return "Player 1";
	else if (Game.Player1WonTimes < Game.ComputerWonTimes)
		return "Computer";
	else
		return "Draw";


}

void PrintGameInfo(stGameInfo Game)
{
	cout << endl << endl << endl;
	cout << PrintTaps(3) << "------------------------------------------------" << endl;
	cout << PrintTaps(3) << "               + + + Game Over + + +            " << endl;
	cout << PrintTaps(3) << "------------------------------------------------" << endl;

	cout << PrintTaps(3) << "------------------[ Game Results ]--------------" << endl << endl;

	cout << PrintTaps(3) << "Game Rounds : " << Game.RoundNumbers << endl;
	cout << PrintTaps(3) << "Player 1 won times :" << Game.Player1WonTimes << endl;
	cout << PrintTaps(3) << "Computer won time :" << Game.ComputerWonTimes << endl;
	cout << PrintTaps(3) << "Draw Times : " << Game.Drawtimes << endl;
	cout << PrintTaps(3) << "Final winner :" << GetFinalWinner(Game) << endl;
	cout << PrintTaps(3) << "-----------------------------------------------\n";



}


void PrintEachWinnerForEachRound(stGameInfo& Game)
{

	cout << "\n\n";
	cout << PrintTaps(3) << "Winners in each round : \n";

	for (int i = 0; i < Game.RoundNumbers; i++)
	{
		cout << endl << PrintTaps(3) << "Round [" << i + 1 << "] Winner : " << Game.NumberOfRounds[i].Winner << endl;
	}



}

void StartGame()
{
	stGameInfo Game;
	short NumberOfRounds = ReadNumber("How many rounds 1 to 10 ?");
	char PlayAgain = 'Y';

	do {

		PlayGame(Game, NumberOfRounds);
		PrintEachWinnerForEachRound(Game);
		PrintGameInfo(Game);
		cout << endl;
		cout << PrintTaps(3) << "Do you want to play again Y/N  ? ";
		cin >> PlayAgain;
		cout << endl;

		while (PlayAgain != 'y' && PlayAgain != 'Y' && PlayAgain != 'n' && PlayAgain != 'N')
		{
			cout << "Invalid choice please enter either Y Or N : ";
			cin >> PlayAgain;
		}
		if (PlayAgain == 'y' || PlayAgain == 'Y')
		{
			ResetGame(Game);
			NumberOfRounds = ReadNumber("How many rounds 1 to 10 ?");
		}



	} while (PlayAgain == 'y' || PlayAgain == 'Y');
	ResetGame(Game);



}




int main()
{

	srand(time(0));

	StartGame();

	return 0;
}