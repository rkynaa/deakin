#ifndef LOST_IN_SPACE_PLANET
#define LOST_IN_SPACE_PLANET

#include "splashkit.h"
#include <vector>

using namespace std;

/**
 * Different options for the kind of ship.
 * Adjusts the image used.
 */
enum planet_kind
{
    EARTH,
    JUPITER,
    MARS,
    MERCURY,
    NEPTUNE,
    PLUTO,
    SATURN,
    URANUS,
    VENUS
};

/**
 * The planet data keeps track of all of the information related to the planet.
 * 
 * @field   planet_sprite   The planet's sprite - used to track position and movement
 * @field   kind            Current kind of planet ship
 */
struct planet_data
{
    sprite      planet_sprite;
    planet_kind   kind;
};

/**
 * Creates a new planet in the centre of the screen with the default ship.
 * 
 * @returns     The new planet data
 */
planet_data new_planet(double x, double y);

/**
 * Draws the planet to the screen. 
 * 
 * @param planet_to_draw    The planet to draw to the screen
 */
void draw_planet(const planet_data &planet_to_draw);

/**
 * Actions a step update of the planet - moving them and adjusting the camera.
 * 
 * @param planet_to_update      The planet being updated
 */
void update_planet(planet_data &planet_to_update);

/**
 * Read user input and update the planet based on this interaction.
 * 
 * @param planet    The planet to update
 */
void handle_input(planet_data &planet);

void convert_to_bitmap(planet_data &curr);

double get_random(double min, double max);

planet_data new_plan_funct();

void make_planets(vector<planet_data> &planets, vector<planet_kind> &listPlanets, vector<int> &indexes);

#endif 