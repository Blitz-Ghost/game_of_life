#include "Cell.h"

Cell::Cell() :IsAlive(false) {}

bool Cell::getStatus() {
		return IsAlive;
	}

void Cell::setStatus(bool Status) {
		IsAlive = Status;
	}

