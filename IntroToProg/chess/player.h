#include "splashkit.h"
#include "piece.h"

enum playerKind {
    BLACK,
    WHITE
};

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
    WIN,
    LOSS
};

struct playerData {
    int moveNum;
    pieceKind currPiece;
    playerKind currPlayer;  
    status currStatus;
    pieceData currPiece;
};

playerData new_player();

void draw_player(const playerData &player_to_draw);

/**
 * Actions a step update of the player - moving them and adjusting the camera.
 * 
 * @param player_to_update      The player being updated
 */
void update_player(playerData &player_to_update);

/**
 * Read user input and update the player based on this interaction.
 * 
 * @param player    The player to update
 */
void handle_input(playerData &player);