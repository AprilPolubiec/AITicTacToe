/*
 * Board.cpp
 *
 *  Created on: Jul 26, 2019
 *      Author: AprilPolubiec
 */

#include "Board.h"

Board::Board()
{
}

Board::~Board(){
	//do I need this?
}

void Board::display() const{
	std::cout << "  0   1   2 "<< std::endl
				<< "0  " + values[0][0] + " | " + values[0][1] + " | " + values[0][2] + " " << std::endl
				<<   "  -----------" << std::endl
				<< "1  " + values[1][0] + " | " + values[1][1] + " | " + values[1][2] + " " << std::endl
				<<	 "  -----------"<< std::endl
				<< "2  " + values[2][0] + " | " + values[2][1] + " | " + values[2][2] + " " << std::endl;
}

void Board::setValue(std::string letter, int row, int col){
	values[row][col] = letter;
}

std::string Board::getValue(int row, int col) const{
	return values[row][col];
}

std::string Board::getUserValue() const{
	return userValue;
}

void Board::setUserValue(std::string letter){
	userValue = letter;
}

std::string Board::getAIValue() const{
	return AIValue;
}

void Board::setAIValue(std::string letter){
	AIValue = letter;
}

std::string Board::somebodyWon() const{
	std::string winner;

	//check for three same values in each row
	for (int i=0;i<COL_SIZE;++i){
		if ((values[i][0] == values[i][1])
				&& (values[i][1] == values[i][2])
				&& (values[i][1] != " ")){
			winner = values[i][0];
		}
	};

	//check for three same values in each column
	for (int i=0;i<ROW_SIZE;++i){
			if ((values[0][i] == values[1][i])
					&& (values[1][i] == values[2][i])
					&& (values[0][i] != " ")){
				winner = values[0][i];
			}
		};

	//check the diagonals
	if ((values[1][1] == values[0][1])
			&& (values[1][1] == values[2][2])
			&& (values[1][1] != " ")){
				winner = values[1][1];
	};
	if ((values[1][1] == values[0][2])
			&& (values[1][1] == values[2][0])
			&& values[1][1] != " "){
				winner = values[1][1];
	};

	return winner;
}

bool Board::boardFull() const
{
	bool isFull = true;

	for (int i = 0; i<COL_SIZE; ++i){
		for (int j = 0; j < ROW_SIZE; ++j){
			if (values[i][j] == " ")
				isFull = false;
		}
	}

	return isFull;

}
