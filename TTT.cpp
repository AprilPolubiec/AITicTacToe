//============================================================================
// Name        : TTT.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<ctime>

const int ROW_SIZE = 3, COL_SIZE = 3;

void startGame(std::string &playerValue);
void displayBoard(std::string boardValues[ROW_SIZE][COL_SIZE]);
void playersTurn(std::string boardValues[ROW_SIZE][COL_SIZE], std::string playerValue);
void AITurn(std::string boardValues[ROW_SIZE][COL_SIZE], std::string playerValue);
std::string checkForWinner(std::string boardValues[ROW_SIZE][COL_SIZE]);



int main() {
	srand(time(0));
	std::string boardValues[ROW_SIZE][COL_SIZE] = {{ " ", " ", " "},
													{" ", " ", " "},
													{" ", " ", " "}};
	std::string playerValue = " ";

	startGame(playerValue);

	do{
	playersTurn(boardValues, playerValue);
	AITurn(boardValues, playerValue);
	}while (checkForWinner(boardValues)!="");

	return 0;
}

void startGame(std::string &playerValue){
	std::cout << "Welcome to the unbeatable Tic Tac Toe." << std::endl
			<< "The TTT board will be set up like a grid with coordinates." << std::endl
			<< "On your turn, you will be prompted to enter the coordinates of the" << std::endl
			<< "space you'd like to play on. Simply enter the x and y coordinate separated" << std::endl
			<< "by a space (eg. 0 1)." << std::endl
			<< "Good luck... you'll need it!" << std::endl << std::endl
			<< "Would you like to be X or O?";
	std::cin >> playerValue;
}

void displayBoard(std::string boardValues[ROW_SIZE][COL_SIZE]){
	std::cout << "  0   1   2 "<< std::endl
			<< "0  " + boardValues[0][0] + " | " + boardValues[0][1] + " | " + boardValues[0][2] + " " << std::endl
			<<   "  -----------" << std::endl
			<< "1  " + boardValues[1][0] + " | " + boardValues[1][1] + " | " + boardValues[1][2] + " " << std::endl
			<<	 "  -----------"<< std::endl
			<< "2  " + boardValues[2][0] + " | " + boardValues[2][1] + " | " + boardValues[2][2] + " " << std::endl;
}

void playersTurn(std::string boardValues[ROW_SIZE][COL_SIZE], std::string playerValue){
	int row, col;
	displayBoard(boardValues);
	std::cout << "Where would you like to play?";
	std::cin >> row >> col;

	boardValues[row][col] = playerValue;

	std::cout << "Your move: " << std::endl;
	displayBoard(boardValues);

}


void AITurn(std::string boardValues[ROW_SIZE][COL_SIZE], std::string playerValue){
	std::string AIValue = "x";
	int randRow = rand()%ROW_SIZE + 1;
	int randCol = rand()%COL_SIZE + 1;
	if (playerValue == "x")
			AIValue = "o";
	//need to account for spaces already taken!
	if (boardValues[randRow][randCol] == "")
		boardValues[randRow][randCol] = AIValue;


	std::cout << "AI's move:" << std::endl;

}

std::string checkForWinner(std::string boardValues[ROW_SIZE][COL_SIZE]){
	std::string winner = "";

	//check for three same values in each row - need to work more on this loop
	for (int i=0;i<COL_SIZE;++i){
		if ((boardValues[i][0] == boardValues[i][1]) && (boardValues[i][1] == boardValues[i][2])){
			winner = boardValues[i][0];
		}
	};

	//check for three same values in each column - need to work more on this loop
	for (int i=0;i<ROW_SIZE;++i){
			if ((boardValues[0][i] == boardValues[0][i]) && (boardValues[0][i] == boardValues[0][i])){
				winner = boardValues[0][i];
			}
		};

	//check the diagonals
	if ((boardValues[1][1] == boardValues[0][1]) && (boardValues[1][1] == boardValues[2][2]))
			winner = boardValues[1][1];
	if ((boardValues[1][1] == boardValues[0][2]) && (boardValues[1][1] == boardValues[2][0]))
		winner = boardValues[1][1];

	return winner;
}
