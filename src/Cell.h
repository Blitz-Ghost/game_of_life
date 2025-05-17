#pragma once

class Cell {
private:
	bool IsAlive;

public:
	Cell();

	bool getStatus() const;

	void setStatus(bool Status);

};