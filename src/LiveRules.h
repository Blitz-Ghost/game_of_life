#pragma once

class LiveRules{
public:
	virtual bool changeedStatus(bool isAlive, int aliveNeighbors) const = 0;
	~LiveRules() = default;;
};

class StanrdardConway : public LiveRules {
public:
	bool changeedStatus(bool isAlive, int aliveNeighbors) const override;
};

class LabyrinthRules : public LiveRules {
public:
	bool changeedStatus(bool isAlive, int aliveNeighbors) const override;
};
