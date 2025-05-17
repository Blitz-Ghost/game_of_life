#pragma once

class BoardAccessor;
class Boundary;


class Neighborhood {
public:
	virtual int countAliveNeighbors(Boundary* boundary, BoardAccessor& board, size_t r, size_t c) const = 0;;
	virtual ~Neighborhood() = default;
};

class MooreNeighborhood : public Neighborhood {
public:
	int countAliveNeighbors(Boundary* boundary, BoardAccessor& board, size_t r, size_t c) const override;
};

class VonNeumannNeighborhood : public Neighborhood {
public:
	int countAliveNeighbors(Boundary* boundary, BoardAccessor& board, size_t r, size_t c) const override;
};