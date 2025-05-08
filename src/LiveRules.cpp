#include "LiveRules.h"

bool StanrdardConway::changeedStatus(bool isAlive, int aliveNeighbors) const {
    if (isAlive)
        return aliveNeighbors == 2 || aliveNeighbors == 3;
    else
        return aliveNeighbors == 3;
}

bool LabyrinthRules::changeedStatus(bool isAlive, int aliveNeighbors) const {
    if (isAlive)
        if (aliveNeighbors >= 0 && aliveNeighbors <= 5) return true;
        else return false;
    else
        return aliveNeighbors == 3;
}

