

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include<cmath>
#include <cstdlib>
#include <windows.h> 

using namespace std;


enum Enumoptions { rock=1, paper=2, scissors=3 };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

int comChoice() {
	int comNum = 0;
	comNum = RandomNumber(1, 3);
	return comNum;

}

string thePick(int choice) {

	switch (choice) {
	case 1: return "Rock";
		break;
	case 2: return "Paper";
		break;
	case 3: return "Scissors";
	}
}

int result(int choice1, int choice2) {


	if (choice1 == rock && choice2 == paper) { return 2; }
	if (choice1 == paper && choice2 == scissors) { return 2; }
	if (choice1 == scissors && choice2 == rock) {  return 2; }

	if (choice1 == rock && choice2 == scissors) {  return 1; }
	if (choice1 == paper && choice2 == rock) { return 1; }
	if (choice1 == scissors && choice2 == paper) {  return 1; }
	
	if (choice1 == choice2) { return -1; }





}

void theRounds(int choice, int& rounds, int& wonRounds, int& lostRounds, int& drawRounds) {
	wonRounds = 0;
	lostRounds = 0;
	drawRounds = 0;
	cout << "How many rounds 1 to 10 ? : ";  cin >> rounds; cout << endl;
	
	for (int i = 1; i <= rounds; i++) {
		cout << "Round " << i << " has begun :\n\n";

		cout << "Enter your choice [1] = Rock  [2] = Paper  [3] = Scissors : "; cin >> choice; cout << endl;

		int com = comChoice();
		cout << "-------------------- Round " << i << " --------------------\n";
		cout << "Player's choice : " << thePick(choice) << endl;
		cout << "Computer's choice : " << thePick(com) << endl;
		cout << "Round's result : ";
	
		switch (result(choice, com)) {
		case 1:cout << "YOU WON!"; system("Color A0"); wonRounds++; break;
		case 2:cout << "THE COMPUTER WON!\a"; system("Color C0"); lostRounds++; break;
		case -1:cout << "ITS A DRAW!"; system("Color E0"); drawRounds++; break;
		}
		cout << "\n-------------------------------------------------\n\n";
	}

}

bool Again(char answer){

	if (answer == 'Y' ||answer=='y') { return true; }
	else if (answer == 'N' ||answer=='n') { return false; }

}

void gameOver(int &rounds, int &wonRounds, int &lostRounds, int &drawRounds) {

	string winner;
	if (wonRounds > lostRounds) { winner = "The Player"; }
	else if (wonRounds == lostRounds) { winner = "Its A Draw"; }
	else { winner = "The Computer"; }

	cout << "\n\t\t\t-------------------------------------------------------------------";
	cout << "\n\t\t\t\t\t\t   +++ GAME OVER +++   ";
	cout << "\n\t\t\t-------------------------------------------------------------------\n\n";
	cout << "\t\t\t-------------------------- [ GAME RESULTS ] -----------------------\n\n";
	cout << "\t\t\tGame Rounds \t\t\t: " << rounds <<"\n";
	cout << "\t\t\tTimes Of Winning For Player \t: " << wonRounds << "\n";
	cout << "\t\t\tTime Of winning For Computer \t: " << lostRounds << "\n";
	cout << "\t\t\tDraw Times \t\t\t: " << drawRounds << "\n";
	cout << "\t\t\tFinal Winner \t\t\t: " <<winner<< "\n";
	cout << "\t\t\t-------------------------------------------------------------------\n\n";


}




int main()
{

	srand((unsigned)time(NULL));

	int choice = 0;
	int rounds = 0;
	char answer = 0;
	int wonRounds = 0;
	int lostRounds = 0;
	int drawRounds = 0;


	theRounds(choice, rounds,wonRounds,lostRounds,drawRounds);
	gameOver(rounds,wonRounds,lostRounds,drawRounds);
	cout << "\t\t\tDo you want to play again ? (Y/N) : "; cin >> answer; cout << endl;

	Again(answer);

	if (Again(answer)) {
		while (answer != 0) {
			theRounds(choice, rounds, wonRounds, lostRounds, drawRounds);
			gameOver(rounds, wonRounds, lostRounds, drawRounds);
			cout << "\t\t\tDo you want to play again ? (Y/N) : "; cin >> answer; cout << endl;

			if (Again(answer) == 0) { break; }
		}
	}

}


