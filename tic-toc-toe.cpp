#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class TicTocToe {
protected:
	char map[3][3];
	int xWins;
	int oWins;
	int ties;
	int game;
public:
	TicTocToe();
	virtual void play() = 0;
	void setGame(int );
	void printMap();
	void printResult();
	void change(int , int , int );
	bool avoid(int, int );
	bool tie();
	bool endGame(int );
	void clearMap();
};

TicTocToe::TicTocToe(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			map[i][j] = ' ';
	}
	xWins = 0;
	oWins = 0;
	ties = 0;
}

void TicTocToe::setGame(int g){
	game = g;
}

void TicTocToe::printMap(){
	cout << "   0     1     2\n\n"
		<< "      |     |\n"
		<< "0  " << map[0][0]
		<< "  |  " << map[0][1]
		<< "  |  " << map[0][2]
		<< "\n _____|_____|_____\n"
		<< "      |     |\n"
		<< "1  " << map[1][0]
		<< "  |  " << map[1][1]
		<< "  |  " << map[1][2]
		<< "\n _____|_____|_____\n"
		<< "      |     |\n"
		<< "2  " << map[2][0]
		<< "  |  " << map[2][1]
		<< "  |  " << map[2][2]
		<< "\n      |     |\n";
}

void TicTocToe::printResult(){
	cout << "           Player X     player O\n\n"
		<< "Wins:         " << xWins << "            " << oWins
		<< "\nLoses:        " << oWins << "            " << xWins
		<< "\nTies:         " << ties << "            " << ties << endl;
}

void TicTocToe::change(int i, int j, int turn){
	if(turn == 1)
		map[i][j] = 'X';
	else
		map[i][j] = 'O';
}

bool TicTocToe::avoid(int i, int j){
	if(map[i][j] == ' ')
		return true;
	else
		return false;
}

bool TicTocToe::tie(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(map[i][j] == ' ')
				return false;
		}
	}
	return true;
}

bool TicTocToe::endGame(int turn){
	if(turn == 1){
		for(int i = 0; i < 3; i++){
			if(map[i][0] == 'X' && map[i][1] == 'X' && map[i][2] == 'X')
				return true;
			if(map[0][i] == 'X' && map[1][i] == 'X' && map[2][i] == 'X')
				return true;
		}
		if(map[0][0] == 'X' && map[1][1] == 'X' && map[2][2] == 'X')
			return true;
		if(map[0][2] == 'X' && map[1][1] == 'X' && map[2][0] == 'X')
			return true;
	} else {
		for(int i = 0; i < 3; i++){
			if(map[i][0] == 'O' && map[i][1] == 'O' && map[i][2] == 'O')
				return true;
			if(map[0][i] == 'O' && map[1][i] == 'O' && map[2][i] == 'O')
				return true;
		}
		if(map[0][0] == 'O' && map[1][1] == 'O' && map[2][2] == 'O')
			return true;
		if(map[0][2] == 'O' && map[1][1] == 'O' && map[2][0] == 'O')
			return true;
	}
	return false;
}

void TicTocToe::clearMap(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			map[i][j] = ' ';
	}
}

class TicTocToePvP : public TicTocToe {
public:
	void play();
	
};

void TicTocToePvP::play(){
	bool done = true, turn = true;
	int i, j;
	printMap();
	while(done){
		if(turn){
			cout << "Player X enter move: ";
			cin >> i >> j;
			if(!avoid(i, j)){
				cout << "Choose again!\n";
				continue;
			}
			change(i, j, 1);
			system("cls");
			printMap();
			turn = !turn;
			if(endGame(1)){
				system("cls");
				cout << "Player X wins!\n\n";
				xWins++;
				done = !done;
				printResult();
				clearMap();
				continue;
			}
			if(tie()){
				done = !done;
				ties++;
				system("cls");
				printResult();
				clearMap();
				continue;
			}
		}
		if(!turn){
			cout << "Player O enter move: ";
			cin >> i >> j;
			if(!avoid(i, j)){
				cout << "Choose again!\n";
				continue;
			}
			change(i, j, 2);
			system("cls");
			printMap();
			turn = !turn;
			if(endGame(2)){
				system("cls");
				cout << "Player O wins!\n\n";
				oWins++;
				done = !done;
				printResult();
				clearMap();
				continue;
			}
			if(tie()){
				done = !done;
				ties++;
				system("cls");
				printResult();
				clearMap();
				continue;
			}
		}
	}
}

class TicTocToePvC : public TicTocToe {
public:
	void play();
};

void TicTocToePvC::play(){
	srand(time(0));
	bool done = true, turn = true;
	int i, j;
	if(game == 1){
		printMap();
		while(done){
			if(turn){
				cout << "Player X enter move: ";
				cin >> i >> j;
				if(!avoid(i, j)){
					cout << "Choose again!\n";
					continue;
				}
				change(i, j, 1);
				system("cls");
				printMap();
				turn = !turn;
				if(endGame(1)){
					system("cls");
					cout << "Player X wins!\n\n";
					xWins++;
					done = !done;
					printResult();
					clearMap();
					continue;
				}
				if(tie()){
					done = !done;
					ties++;
					system("cls");
					printResult();
					clearMap();
					continue;
				}
			}
			if(!turn){
				i = rand() % 3;
				j = rand() % 3;
				if(!avoid(i, j)){
					continue;
				}
				change(i, j, 2);
				system("cls");
				printMap();
				turn = !turn;
				if(endGame(2)){
					system("cls");
					cout << "Player O wins!\n\n";
					oWins++;
					done = !done;
					printResult();
					clearMap();
					continue;
				}
				if(tie()){
					done = !done;
					ties++;
					system("cls");
					printResult();
					clearMap();
					continue;
				}
			}
		}
	}
	else {
		while(done){
			if(turn){
				i = rand() % 3;
				j = rand() % 3;
				if(!avoid(i, j)){
					continue;
				}
				change(i, j, 1);
				system("cls");
				printMap();
				turn = !turn;
				if(endGame(1)){
					system("cls");
					cout << "Player X wins!\n\n";
					xWins++;
					done = !done;
					printResult();
					clearMap();
					continue;
				}
				if(tie()){
					done = !done;
					ties++;
					system("cls");
					printResult();
					clearMap();
					continue;
				}
			}
			if(!turn){
				cout << "Player O enter move: ";
			cin >> i >> j;
			if(!avoid(i, j)){
				cout << "Choose again!\n";
				continue;
			}
			change(i, j, 2);
			system("cls");
			printMap();
			turn = !turn;
			if(endGame(2)){
				system("cls");
				cout << "Player O wins!\n\n";
				oWins++;
				done = !done;
				printResult();
				clearMap();
				continue;
			}
			if(tie()){
				done = !done;
				ties++;
				system("cls");
				printResult();
				clearMap();
				continue;
			}
			}
		}
	}
}

int main(){
	TicTocToe *t;
	TicTocToePvP pvp;
	TicTocToePvC pvc;
	int game;
	cout << "   Welcome to Tic_Tac_Toe!\n"
		<< "     1. player vs. player\n"
		<< "    2. player vs. Computer\n";
	cin >> game;
	system("cls");
	if(game == 1){
		t = &pvp;
		while(true){
			t->play();
			cout << "    1. Retry\n"
				<< "    2. Exit\n";
			cin >> game;
			system("cls");
			if(game == 1)
				continue;
			else
				break;
		}
	}
	else {
		t = &pvc;
		cout << "    1. start with player\n"
			<< "    2. start with computer\n";
		cin >> game;
		system("cls");
		t->setGame(game);
		while(true){
			t->play();
			cout << "    1. Retry\n"
				<< "    2. Exit\n";
			cin >> game;
			system("cls");
			if(game == 1)
				continue;
			else
				break;
		}
	}	
	return 0;
}