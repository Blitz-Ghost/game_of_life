#pragma once
#include <vector>
#include <cstdlib>
#include "Cell.h"
#include "LiveRules.h"
#include "Boundary.h"
#include "Neighbor.h"



using namespace std;

class GameBoard {
private:
	vector <Cell> Board;
	size_t columns;
	size_t records;
	
	const Neighborhood* neighborhood = nullptr;
	const Boundary* boundary = nullptr;
	const LiveRules* rules = nullptr;
	
public:
	GameBoard(size_t cols, size_t rows, Neighborhood* neighborhood, Boundary* boundary, LiveRules* rules);


	Cell& at(size_t r, size_t c);

	size_t GetColumns();

	size_t GetRecords();

	void ChangeCellStatus(size_t r, size_t c);

	void RewriteFrom(const GameBoard& copy);

	void checkBoard(GameBoard& temp);

	void randomGen();

	void setNeighborhood(const Neighborhood* n);

	void setBoundary(const Boundary* b);

	void setLiveRules(const LiveRules* lr);

	const Neighborhood* getNeighborhood();

	const Boundary* getBoundary();

	const LiveRules* getRules();
};


