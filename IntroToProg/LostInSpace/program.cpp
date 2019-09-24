#include "splashkit.h"
#include <vector>
#include "player.h"
#include "planet.h"

using namespace std;

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 800, 800);
    load_resources();

    vector<planet_data> planets;
    vector<planet_kind> listPlanets;
    vector<float> distPlanets;
    vector<int> indexes;

    make_planets(planets, listPlanets, indexes);

    player_data player;
    player = new_player();

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(player);

        // Perform movement and update the camera
        for (int i = 0; i < (int) planets.size(); i++){
            update_planet(planets.at(i));
        }
        update_player(player);

        // Redraw everything
        clear_screen(COLOR_BLACK);

        display_hud(player, planets, distPlanets);

        // as well as the player who can move
        for (int i = 0; i < (int) planets.size(); i++){
            draw_planet(planets.at(i));
        }
        draw_player(player);

        refresh_screen(60);
    }

    return 0;
}