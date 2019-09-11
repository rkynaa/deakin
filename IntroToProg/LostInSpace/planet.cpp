#include "planet.h"
#include "splashkit.h"

using namespace std;

double get_random(double min, double max) {
    return (max - min) * ( (double)rand() / (double)RAND_MAX ) + min;
}

/**
 * Different options for the kind of ship.
 * Adjusts the image used.
 */
bitmap planet_bitmap(planet_kind kind)
{
    switch (kind)
    {
    case EARTH:
        return bitmap_named("earth");
    case JUPITER:
        return bitmap_named("jupiter");
    case MARS:
        return bitmap_named("mars");
    case MERCURY:
        return bitmap_named("mercury"); 
    case NEPTUNE:
        return bitmap_named("neptune");
    case PLUTO:
        return bitmap_named("pluto");
    case SATURN:
        return bitmap_named("saturn");
    case URANUS:
        return bitmap_named("uranus");
    default:
        return bitmap_named("venus");
    }
}

/**
 * Creates a new planet in the centre of the screen with the default ship.
 * 
 * @returns     The new planet data
 */
planet_data new_planet(double x, double y) {
    planet_data result;

    result.kind = static_cast<planet_kind>(rnd(9));

    convert_to_bitmap(result);

    // Position in the centre of the initial screen
    sprite_set_x(result.planet_sprite, (float) y);
    sprite_set_y(result.planet_sprite, (float) x);

    float dx = sprite_dx(result.planet_sprite);
    float dy = sprite_dx(result.planet_sprite);

    double speed = 0;
    while (speed == 0){
        speed = get_random(-0.5, 0.5);
    }

    sprite_set_dx(result.planet_sprite, dx + speed);
    sprite_set_dy(result.planet_sprite, dy + speed);

    return result;
}

/**
 * Draws the planet to the screen. 
 * 
 * @param planet_to_draw    The planet to draw to the screen
 */
void draw_planet(const planet_data &planet_to_draw){
    draw_sprite(planet_to_draw.planet_sprite);
}

/**
 * Actions a step update of the planet - moving them.
 * 
 * @param planet_to_update      The planet being updated
 */
void update_planet(planet_data &planet_to_update){
    update_sprite(planet_to_update.planet_sprite);
}

/**
 * Read user input and update the planet based on this interaction.
 * 
 * @param planet    The planet to update
 */
void handle_input(planet_data &planet);

void convert_to_bitmap(planet_data &curr) {
    // Create the sprite with 3 layers - we can turn on and off based
    // on the ship kind selected
    planet_kind arr[9] = {EARTH, JUPITER, MARS, MERCURY, NEPTUNE, PLUTO, SATURN, URANUS, VENUS};

    for (int i = 0; i <= 9; i++)
    {
        if (curr.kind == arr[i]) {
            curr.planet_sprite = create_sprite(planet_bitmap(arr[i]));
        }
    }
    
}


planet_data new_plan_funct(){
    planet_data new_plan;
    double y = get_random(0, screen_height());
    double x = get_random(0, screen_width());
    new_plan = new_planet(x, y);
    return new_plan;
}

void make_planets(vector<planet_data> &planets, vector<planet_kind> &listPlanets, vector<int> &indexes){
    int clearInd = 0;
    bool ind1 = true;
    
    while (ind1) {
        if (planets.empty() == true && listPlanets.empty() == true) {
            for (int i = 0;i < 9; i++){
                planet_data new_plan = new_plan_funct();
                planets.push_back(new_plan);
                listPlanets.push_back(new_plan.kind);
            }
        } else {
            for (int i = ((int) planets.size()); i < 9; i++){
                planet_data new_plan = new_plan_funct();
                planets.push_back(new_plan);
                listPlanets.push_back(new_plan.kind);
            }
        }
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (planets.at(i).kind == listPlanets.at(j) && i != 0 && i != j){
                    indexes.push_back(i);
                    break; 
                }
            }
        }
        for (int i = 0; i < (int) indexes.size(); i++){
            planets.erase(planets.begin() + (indexes.at(i) - i));
            listPlanets.erase(listPlanets.begin() + (indexes.at(i) - i));
            clearInd++;
        }
        indexes.clear();
        if (clearInd == 0) {
            ind1 = false;
        } else {
            clearInd = 0;
        }
    }
}

string disp_planet_name(planet_data &curr) {
    string currTemp = to_string(curr.kind);
    switch (convert_to_integer(currTemp))
    {
        case 0:
            return "EARTH";
        case 1:
            return "JUPITER";
        case 2:
            return "MARS";
        case 3:
            return "MERCURY";
        case 4:
            return "NEPTUNE";
        case 5:
            return "PLUTO";
        case 6:
            return "SATURN";
        case 7:
            return "URANUS";
        default:
            return "VENUS";
    }
}