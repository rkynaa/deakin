#include "splashkit.h"
#include <vector>
#include "player.h"
#include "planet.h"
#include <graphics.h>

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

        fill_rectangle(COLOR_GRAY, 0, 0, 300, 30, option_to_screen());

        fill_triangle(COLOR_GOLD, 300, 0, 320, 0, 300, 30, option_to_screen());
        fill_triangle(COLOR_GOLD, 0, 30, 100, 30, 50, 50, option_to_screen());
        fill_triangle(COLOR_GOLD, 100, 30, 200, 30, 150, 50, option_to_screen());
        fill_triangle(COLOR_GOLD, 200, 30, 300, 30, 250, 50, option_to_screen());

        draw_text("SCORE: ", COLOR_GOLD, , 0, 0, option_to_screen());
        draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 0, 10, option_to_screen());

        // as well as the player who can move
        for (int i = 0; i < (int) planets.size(); i++){
            draw_planet(planets.at(i));
        }
        draw_player(player);

        refresh_screen(60);
    }

    return 0;
}