#pragma once
class GameBoard;


class Neighborhood {
public:
	virtual int countAliveNeighbors(GameBoard& board, size_t r, size_t c) const = 0;;
	virtual ~Neighborhood() = default;
};

class MooreNeighborhood : public Neighborhood {
public:
	int countAliveNeighbors(GameBoard& board, size_t r, size_t c) const override;
};

class VonNeumannNeighborhood : public Neighborhood {
public:
	int countAliveNeighbors(GameBoard& board, size_t r, size_t c) const override;
};