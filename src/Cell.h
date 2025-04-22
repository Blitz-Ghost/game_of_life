#pragma once

class Cell {
private:
	bool IsAlive;

public:
	Cell();

	bool getStatus();

	void setStatus(bool Status);

};