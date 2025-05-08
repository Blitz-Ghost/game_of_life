#include "GameBoard.h"
#include <cstdlib>


GameBoard::GameBoard(size_t cols, size_t rows, Neighborhood* neighborhood, Boundary* boundary, LiveRules* rules)
    : columns(cols), records(rows), Board(cols* rows), neighborhood(neighborhood), boundary(boundary), rules(rules) {}

Cell& GameBoard::at(size_t r, size_t c) {
    return Board[r * columns + c];
}

size_t GameBoard::GetColumns() {
    return columns;
}

size_t GameBoard::GetRecords() {
    return records;
}

void GameBoard::ChangeCellStatus(size_t r, size_t c) {
    bool current = at(r, c).getStatus();
    at(r, c).setStatus(!current);
}


void GameBoard::RewriteFrom(const GameBoard& copy) {
    this->Board = copy.Board;
}

void GameBoard::checkBoard(GameBoard& temp) {
    for (size_t i = 0; i < records; i++) {
        for (size_t j = 0; j < columns; j++) {
            
            bool alive = at(i, j).getStatus();
            int live_neighbors = neighborhood->countAliveNeighbors(*this, i, j);
            bool newStatus = rules->changeedStatus(alive, live_neighbors);
            temp.at(i, j).setStatus(newStatus);
        }
    }

    RewriteFrom(temp);
}

void GameBoard::randomGen() {
    for (size_t i = 0; i < records; i++) 
        for (size_t j = 0; j < columns; j++) {
            if (rand() % 7 == 1)
                at(i, j).setStatus(true);
            else
                at(i, j).setStatus(false);
        }
}

void GameBoard::setNeighborhood(const Neighborhood* n)
{
    neighborhood = n;
}

void GameBoard::setBoundary(const Boundary* b)
{
    boundary = b;
}

void GameBoard::setLiveRules(const LiveRules* lr)
{
    rules = lr;
}

const Neighborhood* GameBoard::getNeighborhood()
{
    return neighborhood;
}

const Boundary* GameBoard::getBoundary()
{
    return boundary;
}

const LiveRules* GameBoard::getRules()
{
    return rules;
}



