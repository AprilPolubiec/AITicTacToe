//============================================================================
// Name        : TTT.cpp
// Author      : April Polubiec
// Version     : 2
// Copyright   :
// Description : Tic Tac Toe game where AI makes random moves
//============================================================================

#include <iostream>
#include <ctime>
#include "Board.h"


void startGame(Board &gameBoard);
void playersTurn(Board &gameBoard);
void AITurn(Board &gameBoard);


int main() {
	srand(time(0));
	Board gameBoard;

	startGame(gameBoard);

do{
	playersTurn(gameBoard);
	AITurn(gameBoard);
}while(gameBoard.somebodyWon()=="");

	return 0;
}

void startGame(Board &gameBoard){
	std::string chosenValue;
	std::cout << "Welcome to the unbeatable Tic Tac Toe." << std::endl
			<< "The TTT board will be set up like a grid with coordinates." << std::endl
			<< "On your turn, you will be prompted to enter the coordinates of the" << std::endl
			<< "space you'd like to play on. Simply enter the x and y coordinate when" << std::endl
			<< "prompted." << std::endl
			<< "Good luck... you'll need it!" << std::endl << std::endl
			<< "Would you like to be X or O?";
	std::cin >> chosenValue;


	gameBoard.setUserValue(chosenValue);
	if (chosenValue == "x")
		gameBoard.setAIValue("o");
	else
		gameBoard.setAIValue("x");
	gameBoard.display();
}


void playersTurn(Board &gameBoard){
	if (gameBoard.somebodyWon() ==  "")
	{
	int row, col;

	std::cout << "Where would you like to play?" << std::endl
			<< "X-Coordinate: ";
	std::cin >> col;
	std::cout << "Y-Coordinate: ";
	std::cin >> row;


	if (gameBoard.getValue(row, col) == " ")
		gameBoard.setValue(gameBoard.getUserValue(), row, col);
	else{
		std::cout << "That spot is taken!";
		playersTurn(gameBoard);
	}

	std::cout << "Your move: " << std::endl;
	gameBoard.display();

	if (gameBoard.somebodyWon() == gameBoard.getUserValue()){
		std::cout << "YOU WON!" <<std::endl;
	} else if (gameBoard.boardFull()){
		std::cout << "ITS A DRAW!" << std::endl;
	}
	}

}


void AITurn(Board &gameBoard){
	if (gameBoard.somebodyWon() == "")
	{
		int randRow, randCol;
		do
		{
			randRow = rand()%ROW_SIZE;
			randCol = rand()%COL_SIZE;
		} while(gameBoard.getValue(randRow, randCol) != " ");

		gameBoard.setValue(gameBoard.getAIValue(), randRow, randCol);

		std::cout << "AI's move:" << std::endl;
		gameBoard.display();

		if (gameBoard.somebodyWon() == gameBoard.getAIValue()){
			std::cout << "YOU LOSE!" << std::endl;
		} else if (gameBoard.boardFull()){
			std::cout << "ITS A DRAW!" << std::endl;
		}
	}

}

