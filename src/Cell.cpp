#include "Cell.h"

Cell::Cell() :IsAlive(false) {}

bool Cell::getStatus() const{
		return IsAlive;
	}

void Cell::setStatus(bool Status) {
		IsAlive = Status;
	}

