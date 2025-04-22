#pragma once
#include <vector>
#include "Cell.h"

using namespace std;

class GameBoard {
private:
	vector <Cell> Board;
	size_t columns;
	size_t records;
public:
	GameBoard(size_t columns, size_t records);

	Cell& at(size_t r, size_t c);

	size_t GetColumns();

	size_t GetRecords();

	void ChangeCellStatus(size_t r, size_t c);

	int CountNeighborAlive(size_t r, size_t c);

	void RewriteFrom(const GameBoard& copy);

	void checkBoard(GameBoard& temp);

	void randomGen();

};


