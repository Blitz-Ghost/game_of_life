#pragma once

class BoardAccessor;

class Boundary {
public:
	virtual bool AliveAt(BoardAccessor& board, size_t r, size_t c) const = 0;;
	virtual ~Boundary() = default;;
};

class DeadOutside : public Boundary {
public:
	virtual bool AliveAt(BoardAccessor& board, size_t r, size_t c) const override;
};

class Looped : public Boundary {
public:
	virtual bool AliveAt(BoardAccessor& board, size_t r, size_t c) const override;
};