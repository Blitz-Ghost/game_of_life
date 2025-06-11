#pragma once
#include <vector>
#include <cstdlib>
#include "Cell.h"
#include "LiveRules.h"
#include "Boundary.h"
#include "Neighbor.h"
#include <memory>



using namespace std;

class BufferBoard {
private:
	vector<Cell> Board;
	size_t columns;
	size_t records;

public:
	BufferBoard(size_t cols, size_t rows) : columns(cols), records(rows), Board(cols* rows) {}

	Cell& at(size_t r, size_t c);

	const Cell& at(size_t r, size_t c) const;

};

class BoardAccessor {
public:
	virtual const Cell& at(size_t row, size_t col) const = 0;
	virtual size_t GetRecords() const = 0;
	virtual size_t GetColumns() const = 0;

	virtual ~BoardAccessor() = default;
};
// Not sure this BoardAccessor abstraction makes sense in this project. It seems to break the KISS rule
class GameBoard : public BoardAccessor {
private:
	vector <Cell> Board;
	size_t columns;
	size_t records;
	
	unique_ptr<Neighborhood> neighborhood;
	unique_ptr<Boundary> boundary;
	unique_ptr<LiveRules> rules;
	
	
public:
	explicit GameBoard(size_t cols, size_t rows, unique_ptr<Neighborhood> init_neighborhood, unique_ptr<Boundary> init_boundary, unique_ptr<LiveRules> init_rules);
    GameBoard(size_t cols, size_t rows);


	Cell& at(size_t r, size_t c);

	const Cell& at(size_t r, size_t c) const override;

	size_t GetColumns() const override;

	size_t GetRecords() const override;

	void ChangeCellStatus(size_t r, size_t c);

	void RewriteFrom(const BufferBoard& copy);

	void checkBoard(BufferBoard& temp);

	void randomGen();

	void reset();

	void setBoundary(unique_ptr<Boundary> newBoundary);

	void setNeighborhood(unique_ptr<Neighborhood> newNeighborhood);

	void setLiveRules(unique_ptr<LiveRules> newRules);

};




