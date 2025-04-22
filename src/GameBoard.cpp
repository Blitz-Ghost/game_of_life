#include "GameBoard.h"
#include <cstdlib>


GameBoard::GameBoard(size_t columns, size_t records)
    : Board(columns* records), columns(columns), records(records) {}

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

int GameBoard::CountNeighborAlive(size_t r, size_t c) {
    int counter = 0;

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;

            int nr = static_cast<int>(r) + dr;
            int nc = static_cast<int>(c) + dc;

            if (nr >= 0 && nc >= 0 && nr < static_cast<int>(records) && nc < static_cast<int>(columns)) {
                if (at(nr, nc).getStatus()) counter++;
            }
        }
    }

    return counter;
}

void GameBoard::RewriteFrom(const GameBoard& copy) {
    this->Board = copy.Board;
}

void GameBoard::checkBoard(GameBoard& temp) {
    for (size_t i = 0; i < records; i++) {
        for (size_t j = 0; j < columns; j++) {
            int live_neighbors = CountNeighborAlive(i, j);
            bool alive = at(i, j).getStatus();
            bool newStatus = false;

            if (alive) {
                newStatus = (live_neighbors == 2 || live_neighbors == 3);
            }
            else {
                newStatus = (live_neighbors == 3);
            }

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