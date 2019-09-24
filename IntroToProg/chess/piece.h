#include "splashkit.h"
#include <vector>
#include "back.h"

enum pieceKind {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
};

enum status {
    ALIVE,
    DEAD
};

enum direction {
    HORIZONTAL,
    VERTICAL,
    DIAGONAL
};

struct pieceData {
    int num;
    pieceKind currPiece;
    vector<direction> directions;
    vector<int> amountDirection;
    status currStatus;
    locations currLoc;
}

void 