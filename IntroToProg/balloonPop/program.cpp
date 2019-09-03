#include "splashkit.h"
#include "functions.h"

int score;

enum stateBalloon {
    pop,
    nopop
};

struct location {
    double lat;
    double lng;
};

struct balloon {
    double speed;
    sprite balloon_sprite;
    location currLong;
    stateBalloon currState; 
};

int main()
{
    vector<balloon> balloons;

    // LOAD THE RESOURCES
    //load_resources();

    // INITALIZE THE GAME
    initialize_game();
    while (!mouse_clicked(LEFT_BUTTON)) {
    }
    // HANDLE THE USER INPUT

    return 0;
}