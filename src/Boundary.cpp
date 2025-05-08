#include "Boundary.h"
#include "GameBoard.h"

bool DeadOutside::AliveAt(GameBoard& board, size_t r, size_t c) const {
	if (r < 0 || c < 0 || r >= board.GetRecords() || c >= board.GetColumns())
		return false;
	return board.at(r, c).getStatus();
}

bool Looped::AliveAt(GameBoard& board, size_t r, size_t c) const {
	size_t rows = board.GetRecords();
	size_t cols = board.GetColumns();
	size_t loopedR = (r + rows) % rows;
	size_t loopedC = (c + cols) % cols;
	return board.at(loopedR, loopedC).getStatus();
}
