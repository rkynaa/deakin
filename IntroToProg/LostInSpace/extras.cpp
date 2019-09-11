#include "extras.h"
#include "splashkit.h"

using namespace std;

void dist_player_planet(player_data &player, vector<planet_data> &planets, vector<float> &distPlanets){
    for (int i = 0; i < (int) planets.size(); i++){
        point_2d distPlayer = center_point(player.player_sprite), distPlanet = center_point(planets.at(i).planet_sprite);
        float temp = point_point_distance(distPlanet, distPlayer);
        distPlanets.push_back(temp);
    }
}