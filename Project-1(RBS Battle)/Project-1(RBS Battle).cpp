
#include <iostream>
using namespace std;

enum result { winner = 1, loser = 0, draw = 2 };

enum Choice { Rock = 1, paper = 2, secissors = 3 };

int StartRounds() {
	cout << "=====================================\n";
	cout << "\n\tWelcome to RBS Battle!\n";
	cout << "\n=====================================\n";
	cout << "How many Rounds you want? ";
	int rounds;

	cin >> rounds;
	if (rounds < 0) {
		cout << "\nOk";
		rounds = rounds * -1;
	}
	return rounds;
}

int RandomNumbers(int from, int to) {
	int randnum = rand() % (to - from + 1) + from;
	return randnum;
}

int GetRsult(int Hchoice, int PcChoice) {
	switch (Hchoice) {
	case (Choice::Rock):
		if (PcChoice == 2) {
			cout << "Your Choice : Rock\n";
			cout << "Pc   Choice : paper\n";
			cout << "You lose :(\n";
			cout << "\a";
			system("color 4E");
			return -1;
		}
		else if (PcChoice == 1) {
			cout << "Your Choice : Rock\n";
			cout << "Pc   Choice : Rock\n";
			cout << "Draw!\n";
			system("color 6E");
			return 2;
		}
		else {
			cout << "Your Choice : Rock\n";
			cout << "Pc   Choice : Secissors\n";
			cout << "You Won :)\n";
			system("color 2E");
			return 1;
		}
		break;


	case (Choice::paper):
		if (PcChoice == 3) {
			cout << "Your Choice : Paper\n";
			cout << "Pc   Choice : secissors\n";
			cout << "You lose :(\n";
			cout << "\a";
			system("color 4E");
			return -1;
		}
		else if (PcChoice == 2) {
			cout << "Your Choice : Paper\n";
			cout << "Pc   Choice : Paper\n";
			cout << "Draw!\n";
			system("color 6E");
			return 2;
		}
		else {
			cout << "Your Choice : Paper\n";
			cout << "Pc   Choice : Rock\n";
			cout << "You Won :)\n";
			system("color 2E");
			return 1;
		}
		break;


	case (Choice::secissors):
		if (PcChoice == 2) {
			cout << "Your Choice : secissors\n";
			cout << "Pc   Choice : Paper\n";
			cout << "You won :)\n";
			system("color 2E");
			return 1;
		}
		else if (PcChoice == 3) {
			cout << "Your Choice : secissors\n";
			cout << "Pc   Choice : secissors\n";
			cout << "Draw!\n";
			system("color 6E");
			return 2;
		}
		else {
			cout << "Your Choice : secissors\n";
			cout << "Pc   Choice : Rock\n";
			cout << "You lose :(\n";
			cout << "\a";
			system("color 4E");
			return -1;
		}
		break;
	}

}

void RoundGame(int& win, int& lose, int& draw, int Howmanyrounds) {
	int choicennumber;
	int Thewinner;
	win = 0, lose = 0, draw = 0;
	for (int i = 1; i <= Howmanyrounds; i++) {
		cout << "\n-----------Round [" << i << "] Begins-----------\n";
		cout << "\nYour Choice : [1]Rock, [2]Paper, [3]Secissors : ";
		do {
			cin >> choicennumber;
			if (choicennumber <= 0 || choicennumber > 3) {
				cout << "Please enter a number between 0 and 4\n";
			}
		} while (choicennumber <= 0 || choicennumber > 3);

		if (choicennumber == 1) {
			choicennumber = Choice::Rock;
		}
		else if (choicennumber == 2) {
			choicennumber = Choice::paper;
		}
		else {
			choicennumber = Choice::secissors;
		}
		int PcChoice = RandomNumbers(1, 3);
		if (PcChoice == 1) {
			PcChoice = Choice::Rock;
		}
		else if (PcChoice == 2) {
			PcChoice = Choice::paper;
		}
		else {
			PcChoice = Choice::secissors;
		}
		Thewinner = GetRsult(choicennumber, PcChoice);
		if (Thewinner == 1) {
			win++;
		}
		else if (Thewinner == -1) {
			lose++;
		}
		else {
			draw++;
		}

	}
}

void PrintLastResult(int win, int lose, int draw) {
	cout << "\n\t\t=====================================\n";
	if (win > lose) {
		cout << "\t\tGame Over\n";
		cout << "\t\tYou are the Winner :)\n";
		system("color 2E");
		cout << "\t\t=====================================\n";
		cout << "\n\t\t\tGame Result\n";
		cout << "\n\t\t=====================================\n";
		cout << "\t\tTotal rounds       : " << lose + win + draw << endl;
		cout << "\t\tPlayer won times   : " << win << endl;
		cout << "\t\tComputer won times : " << lose << endl;
		cout << "\t\tDraw times         : " << draw << endl;
		cout << "\t\tWinner             : Player" << endl;
	}
	else if (lose > win) {
		cout << "\t\tGame Over\n";
		cout << "\t\tYour are the loser:(\n";
		cout << "\a";
		system("color 4E");
		cout << "\t\t=====================================\n";
		cout << "\n\t\t\tGame Result\n";
		cout << "\n\t\t=====================================\n";
		cout << "\t\tTotal rounds       : " << lose + win + draw << endl;
		cout << "\t\tPlayer won times   : " << win << endl;
		cout << "\t\tComputer won times : " << lose << endl;
		cout << "\t\tDraw times         : " << draw << endl;
		cout << "\t\tWinner             : Pc" << endl;
	}
	else {
		cout << "\t\tGame Over\n";
		cout << "\t\tDraw No Problem\n";
		system("color 6E");
		cout << "\t\t=====================================\n";
		cout << "\n\t\t\tGame Result\n";
		cout << "\n\t\t=====================================\n";
		cout << "\t\tTotal rounds       : " << lose + win + draw << endl;
		cout << "\t\tPlayer won times   : " << win << endl;
		cout << "\t\tComputer won times : " << lose << endl;
		cout << "\t\tDraw times         : " << draw << endl;
		cout << "\t\tWinner             : none" << endl;

	}


}

int main()
{
	srand((unsigned)time(NULL));
	int win, lose, draw;
	int Rounds;
	char YORN;
	do {
		Rounds = StartRounds();
		RoundGame(win, lose, draw, Rounds);
		PrintLastResult(win, lose, draw);
		cout << "Do you want to play again? y[yes], AnyElse[no] : ";
		cin >> YORN;
		system("color 0F");
		system("cls");
	} while (YORN == 'y' || YORN == 'Y');
	cout << "************* GOOD BAY *************";
	return 0;
}