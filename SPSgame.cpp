//This project done 24.09.2025 and this is my code and abouhadhoud code 


#include <iostream>
#include <cmath>
#include<string>
#include <cstdlib> 
#include <ctime>   
#include "myLibrary.h";
using namespace std;

int GetRoundsNumber(int &Rounds) {

	Rounds = myLibrary::ReadPositiveNumberInRange("How many rounds(1 to 10):",1,10);

	return Rounds;
}

enum Options {
	stone=1,paper=2,scissors=3
};
int ReadUserChoice() {
	int Choice;
	Choice= myLibrary::ReadPositiveNumberInRange("Your Choice : [1]:Stone, [2]:Paper, [3]:scissors:", 1, 3);
	return Choice;
}
int  ReadComputerChoice() {
	int ComputerChoose = myLibrary::GetRandomNumberInRange(1, 3);
	return ComputerChoose;
}
Options ConverNumberChooseToOption(int Choose) {
	switch (Choose) {
	case(1):
		return Options::stone;
	case(2):
	return 	Options::paper;
	case(3):
		return Options::scissors;
	}
}

void PrintUserChoice(int Choice) {
	switch (ConverNumberChooseToOption(Choice)) {
	case(Options::stone):
		cout << "Player1 Choice: Stone";
		break;
	case(Options::paper):
		cout << "Player1 Choice: Paper";
		break;
	case(Options::scissors):
		cout << "Player1 Choice: Scissors";
		break;
	}
}
void PrintComputerChoice(int Choice) {
	switch (ConverNumberChooseToOption(Choice)) {
	case(Options::stone):
		cout << "Computer Choice: Stone";
		break;
	case(Options::paper):
		cout << "Computer Choice: Paper";
		break;
	case(Options::scissors):
		cout << "Computer Choice: Scissors";
		break;
	}
}
enum Status {
	WinUser=1,WinComputer=3,Draw=2
};

struct WinTimes {
	int UserWin=0;
	int ComputerWin=0;
	int Draw=0;
};
Status WhoWin(int UserChoose,int ComputerChoose) {
	if (ConverNumberChooseToOption(UserChoose)==Options::stone&&
		ConverNumberChooseToOption(ComputerChoose)==Options::scissors) {
		return Status::WinUser;
	}
	else if (ConverNumberChooseToOption(UserChoose) == Options::scissors && 
		ConverNumberChooseToOption(ComputerChoose) == Options::paper) {
		return Status::WinUser;
	}
	else if (ConverNumberChooseToOption(UserChoose) == Options::paper && 
		 ConverNumberChooseToOption(ComputerChoose) == Options::scissors) {
		return Status::WinComputer;
	}
	else if (ConverNumberChooseToOption(UserChoose) == Options::scissors &&
		ConverNumberChooseToOption(ComputerChoose) == Options::stone) {
		return Status::WinComputer;
	}
	else if (ConverNumberChooseToOption(UserChoose) == ConverNumberChooseToOption(ComputerChoose) ) {
		return Status::Draw;
	}
}
void WinTimesCounter(WinTimes &ExampleOne, int UserChoose, int ComputerChoose) {
	switch (WhoWin(UserChoose, ComputerChoose)) {
	case(Status::WinUser):
		ExampleOne.UserWin++;
		break;
	case(Status::WinComputer):
		ExampleOne.ComputerWin++;
		break;
	case(Status::Draw):
		ExampleOne.Draw++;
		break;
	}


}
void PrintWinLose(int UserChoose, int ComputerChoose) {
	switch (WhoWin( UserChoose,ComputerChoose)) {
	case(Status::WinUser):
		cout << "Round Winner : [Player1]";
		system("color 2F");
		break;
	case(Status::WinComputer):
		cout << "Round Winner : [Computer]";
		system("color 4F");
		break;
	case(Status::Draw):
		cout << "Round Winner : [No Winner]";
		system("color 6F");
		break;
	}
}
void PrintRoundScreen (int &Round,int &UserChoose,int &ComputerChoose,WinTimes &exampleone) {
	for (int i = 1; i <= Round;i++) {
		cout << "\n\n\n";
		cout << "Round [" << i << "] begins :" << endl;
		UserChoose=ReadUserChoice();
		ComputerChoose = ReadComputerChoice();
		cout << endl;
		cout << "---------- Round [" << i << "] ---------------"<<endl;
		PrintUserChoice(UserChoose);
		cout << endl;
		PrintComputerChoice(ComputerChoose);
		cout << endl;
		PrintWinLose(UserChoose, ComputerChoose);
		cout << "\n\n";
		cout << "---------------------------------------------------"<<endl;
		WinTimesCounter(exampleone, UserChoose, ComputerChoose);
	}
}
string ReturnWinner(int UserResult,int ComputerResult,int DrawResult) {
	if (UserResult> ComputerResult) {
		return "Player1";
	}
	else if (ComputerResult> UserResult) {
		return "Computer";
	}
	else {
		return "No Winner";
	}
}

void PrintGameEnd(int Round,int userchoose,int computerchoose,WinTimes WinTime) {
	
	cout << "                                  ----------------------------------------"<<endl;
	cout << "                                               +++ Game over +++          "<<endl;
	cout << "                                  ----------------------------------------" << endl;
	cout << "                                  --------------[Game Results]--------------" << endl;
	cout << "                                     Game Rounds:       " << Round<<endl;
	cout << "                                     Player1 won times: "<<WinTime.UserWin<<endl;
	cout << "                                     Computer won times:" << WinTime.ComputerWin<<endl;
	cout << "                                     Draw times:        " << WinTime.Draw<<endl;
	cout << "                                     Final Winner:      "
		<< ReturnWinner(WinTime.UserWin, WinTime.ComputerWin, WinTime.Draw)<<endl;
	cout << "                                  -------------------------------------------" << endl;

}
void StartGame() {
	int Rounds, userchoose, computerchoose;
 
 
	WinTimes WinCounter;
	do {
		system("cls");
		system("color 0F");
		GetRoundsNumber(Rounds);
		PrintRoundScreen(Rounds, userchoose, computerchoose, WinCounter);
		PrintGameEnd(Rounds, userchoose, computerchoose, WinCounter);
	} while (myLibrary::AskToPlayAgain());
}

int main() {
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}

//EDITEDCODE
//#include <iostream>
//#include <cmath>
//#include<string>
//#include <cstdlib> 
//#include <ctime>   
//#include "myLibrary.h";
//using namespace std;
//
//
//enum Options {
//	stone = 1, paper = 2, scissors = 3
//};
//enum Winner {
//	WinUser = 1, WinComputer = 2, Draw = 3
//};
//
//struct RoundInfo {
//	short Rounds = 1;
//	Options Player1Choose = Options::paper;
//	Options Computer1Choose = Options::paper;
//	Winner RoundWinner = Winner::Draw;
//	string WinnerName = "";
//};
//struct GameResult {
//	short UserWin = 0;
//	short ComputerWin = 0;
//	short Draw = 0;
//	short Rounds = 1;
//	Winner GameWinner= Winner::Draw;
//	string WinnerName = "";
//
//};
//short ReadPositiveNumberInRange(string message, int from, int to) {
//	short number;
//	do {
//		cout << message;
//		cin >> number;
//	} while (number<from || number>to);
//
//
//	return number;
//}
//
//string PrintWinnerName(Winner winnername) {
//	string WinnerName[3] = { "Player1","Computer","Draw" };
//	return WinnerName[winnername - 1];
//}
//string PrintChoiceName(Options choose) {
//	string options[3] = { "Stone","Paper","Scissors" };
//	return options[choose - 1];
//}
//
//Winner WhoWonTheRound(RoundInfo RoundInfo)
//{
//	// If both choices are the same, it's a draw.
//	if (RoundInfo.Player1Choose == RoundInfo.Computer1Choose)
//		return Winner::Draw;
//
//	// Determine the winner based on game rules.
//	switch (RoundInfo.Player1Choose)
//	{
//	case (Options::stone):
//		return (RoundInfo.Computer1Choose == Options::paper) ? Winner::WinComputer : Winner::WinUser;
//	case (Options::paper):
//		return (RoundInfo.Computer1Choose == Options::scissors) ? Winner::WinComputer : Winner::WinUser;
//	case (Options::scissors):
//		return (RoundInfo.Computer1Choose == Options::stone) ? Winner::WinComputer : Winner::WinUser;
//	}
//	return Winner::Draw;
//}
//
//
//
//short GetRoundsNumber() {
//
//	return ReadPositiveNumberInRange("How many rounds(1 to 10): ", 1, 10);
//}
//
//Winner WhoWonTheGame(short playerwintime, short Computerwintime) {
//	if (playerwintime > Computerwintime)return Winner::WinUser;
//	else if (Computerwintime > playerwintime)return Winner::WinComputer;
//	else return Winner::Draw;
//
//}
//
//GameResult FillGameResult(short round, short winuser, short wincomputer, short draw) {
//	GameResult gameresult;
//	gameresult.Rounds = round;
//	gameresult.UserWin = winuser;
//	gameresult.ComputerWin = wincomputer;
//	gameresult.Draw = draw;
//	gameresult.GameWinner = WhoWonTheGame(gameresult.UserWin, gameresult.ComputerWin);
//	gameresult.WinnerName = PrintWinnerName(gameresult.GameWinner);
//
//	return gameresult;
//}
//
//Options ReadUserChoice() {
//
//	return (Options)ReadPositiveNumberInRange("Your Choice : [1]:Stone, [2]:Paper, [3]:scissors:", 1, 3);
//}
//Options  ReadComputerChoice() {
//	return (Options)myLibrary::GetRandomNumberInRange(1, 3);
//}
//void PrintRoundInfo(RoundInfo roundinfo) {
//	cout << "\n---------------------Round [" << roundinfo.Rounds << "]------------------\n\n";
//	cout << "Player1 choose:" << PrintChoiceName(roundinfo.Player1Choose) << endl;
//	cout << "computer choose:" << PrintChoiceName(roundinfo.Computer1Choose) << endl;
//	cout << "Round winner:[" << roundinfo.WinnerName << "]\n";
//	cout << "\n---------------------------------------------------\n\n";
//}
//
//GameResult FillRoundScreen(short Rounds) {
//	RoundInfo roundinfo;
//	short userwin = 0;
//	short computerwin = 0;
//	short draw = 0;
//
//	for (short i = 1; i <= Rounds; i++) {
//
//		cout << "\n\n\n";
//		cout << "Round [" << i << "] begins :" << endl;
//		roundinfo.Computer1Choose = ReadComputerChoice();
//		roundinfo.Player1Choose = ReadUserChoice();
//		roundinfo.RoundWinner = WhoWonTheRound(roundinfo);
//		roundinfo.WinnerName = PrintWinnerName(roundinfo.RoundWinner);
//
//
//		if (roundinfo.RoundWinner == Winner::WinComputer) {
//			system("color 4F");
//			computerwin++;
//		}
//		else if (roundinfo.RoundWinner == Winner::WinUser) {
//			system("color 2F");
//			userwin++; 
//		}
//		else { 
//			system("color 6F");
//			draw++; 
//		}
//		PrintRoundInfo(roundinfo);
//
//	}
//
//	return FillGameResult(Rounds, userwin, computerwin, draw);
//
//}
//
//void GameOver() {
//	cout << "                                  ----------------------------------------" << endl;
//	cout << "                                               +++ Game over +++          " << endl;
//	cout << "                                  ----------------------------------------" << endl;
//}
//
//void PrintGameEnd(GameResult gameresult) {
//
//	cout << "                                  --------------[Game Results]--------------" << endl;
//	cout << "                                     Game Rounds:       " << gameresult.Rounds << endl;
//	cout << "                                     Player1 won times: " << gameresult.UserWin << endl;
//	cout << "                                     Computer won times:" << gameresult.ComputerWin << endl;
//	cout << "                                     Draw times:        " << gameresult.Draw << endl;
//	cout << "                                     Final Winner:      " << gameresult.WinnerName << endl;
//	cout << "                                  -------------------------------------------" << endl;
//
//}
//
//
//
//
//bool AskToPlayAgain() {
//	char YesNo = 'y';
//	cout << "                                    Do you want to play again ?Y/N:";
//	cin >> YesNo;
//	if (YesNo == 'y' || YesNo == 'Y') {
//		return 1;
//	}
//	return 0;
//}
//
//void StartGame() {
//	do {
//		system("cls");
//		system("color 0F");
//		GameResult gameresult = FillRoundScreen(GetRoundsNumber());
//		GameOver();
//		PrintGameEnd(gameresult);
//	} while (AskToPlayAgain());
//}
//
//int main(){
//
//	srand((unsigned)time(NULL));
//
//	StartGame();
//
//	return 0;
//}