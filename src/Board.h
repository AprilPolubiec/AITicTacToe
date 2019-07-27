/*
 * Board.h
 *
 *  Created on: Jul 26, 2019
 *      Author: AprilPolubiec
 */

#ifndef BOARD_H_
#define BOARD_H_

#include<iostream>
#include<string>

const int ROW_SIZE = 3, COL_SIZE = 3;

class Board {
public:
	Board();
	~Board();
	void display() const;
	void setValue(std::string letter, int row, int col);
	std::string getValue(int row, int col) const;

	std::string getUserValue() const;
	void setUserValue(std::string letter);

	std::string getAIValue() const;
	void setAIValue(std::string letter);

	std::string somebodyWon() const;
	bool boardFull() const;
private:
	std::string values[ROW_SIZE][COL_SIZE] = {{ " ", " ", " "},
			{" ", " ", " "},
			{" ", " ", " "}};
	std::string userValue;
	std::string AIValue;
};

#endif /* BOARD_H_ */
