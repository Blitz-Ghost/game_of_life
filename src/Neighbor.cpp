#include "Neighbor.h"
#include "GameBoard.h"
#include "Boundary.h"


int MooreNeighborhood::countAliveNeighbors(Boundary* boundary, BoardAccessor& board, size_t r, size_t c) const {
    int counter = 0;
    

    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr != 0 || dc != 0)
                if (boundary->AliveAt(board, r + dr, c + dc))
                    counter++;
    return counter;
}

int VonNeumannNeighborhood::countAliveNeighbors(Boundary* boundary, BoardAccessor& board, size_t r, size_t c) const {
    int counter = 0;
    

    int directions[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    for (auto& [dr, dc] : directions)
        if (boundary->AliveAt(board, r + dr, c + dc))
            counter++;
    return counter;
}
