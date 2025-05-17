#include "GameBoard.h"
#include <cstdlib>
#include <stdexcept>

GameBoard::GameBoard(size_t cols, size_t rows, unique_ptr<Neighborhood> init_neighborhood, unique_ptr<Boundary> init_boundary, unique_ptr<LiveRules> init_rules)
    :columns(cols), records(rows), neighborhood(move(init_neighborhood)), boundary(move(init_boundary)), rules(move(init_rules)) {
    Board.resize(columns * records);
}

Cell& GameBoard::at(size_t r, size_t c) {
    if (r >= records || c >= columns) {
        throw std::out_of_range("Index out of range");
    }
    return Board[r * columns + c];
}

const Cell& GameBoard::at(size_t r, size_t c) const {
    if (r >= records || c >= columns) {
        throw std::out_of_range("Index out of range");
    }
    return Board[r * columns + c];
}

size_t GameBoard::GetColumns() const {
    return columns;
}

size_t GameBoard::GetRecords() const {
    return records;
}

void GameBoard::ChangeCellStatus(size_t r, size_t c) {
    bool current = at(r, c).getStatus();
    at(r, c).setStatus(!current);
}


void GameBoard::RewriteFrom(const BufferBoard& copy) {
    for (size_t i = 0; i < records; i++) {
        for (size_t j = 0; j < columns; j++) {
            this->at(i, j).setStatus(copy.at(i, j).getStatus());
        }
    }
}

void GameBoard::checkBoard(BufferBoard& temp) {
    for (size_t i = 0; i < records; i++) {
        for (size_t j = 0; j < columns; j++) {
            
            bool alive = at(i, j).getStatus();
            int live_neighbors = neighborhood->countAliveNeighbors(boundary.get(), *this, i, j);
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

void GameBoard::reset() {
    for (auto& cell : Board) cell.setStatus(false);
}

void GameBoard::setBoundary(unique_ptr<Boundary> newBoundary) {
    boundary = move(newBoundary);
}

void GameBoard::setNeighborhood(unique_ptr<Neighborhood> newNeighborhood) {
    neighborhood = move(newNeighborhood);
}

void GameBoard::setLiveRules(unique_ptr<LiveRules> newRules) {
    rules = move(newRules);
}


Cell& BufferBoard::at(size_t r, size_t c) {
    if (r >= records || c >= columns) {
        throw std::out_of_range("Index out of range");
    }
    return Board[r * columns + c];
}

const Cell& BufferBoard::at(size_t r, size_t c) const {
    if (r >= records || c >= columns) {
        throw std::out_of_range("Index out of range");
    }
    return Board[r * columns + c];
}




