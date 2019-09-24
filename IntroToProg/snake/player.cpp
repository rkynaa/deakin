#include "splashkit.h"
#include <vector>

using namespace std;

/**
 * Different options for the kind of ship.
 * Adjusts the image used.
 */

/**
 * The player data keeps track of all of the information related to the player.
 * 
 * @field   player_sprite   The player's sprite - used to track position and movement
 * @field   score           The current score for the player
 * @field   kind            Current kind of player ship
 */
struct player_data
{
    sprite      player_sprite;
    int         length;
    int         score;
};

/**
 * Creates a new player in the centre of the screen with the default ship.
 * 
 * @returns     The new player data
 */
player_data new_player() {
    player_data result;

    // Create the sprite with 3 layers - we can turn on and off based
    // on the ship kind selected

    // Default to layer 0 = Aquarii so hide other

    // Position in the centre of the initial screen

    return result;
}

/**
 * Draws the player to the screen. 
 * 
 * @param player_to_draw    The player to draw to the screen
 */
void draw_player(const player_data &player_to_draw) {
    draw_sprite(player_to_draw.player_sprite);
}
/**
 * Actions a step update of the player - moving them and adjusting the camera.
 * 
 * @param player_to_update      The player being updated
 */
void update_player(player_data &player_to_update){

    update_sprite(player_to_update.player_sprite);

    point_2d sprite_center = center_point(player_to_update.player_sprite);
}

/**
 * Read user input and update the player based on this interaction.
 * 
 * @param player    The player to update
 */
void handle_input(player_data &player){
    float dx = sprite_dx(player.player_sprite);

}