#include "splashkit.h"
using namespace std;

#define CIRCLE_RADIUS 150

int main()
{
    double x, y;
    open_window("Circle Moving", 800, 600);
    x = 400;
    y = 300;
    while (not quit_requested())
    {
        process_events();
        if (key_down(LEFT_KEY) && (x - CIRCLE_RADIUS > 0)){
            x--;
        } if (key_down(RIGHT_KEY) && (x < screen_width() - CIRCLE_RADIUS)) {
            x++;
        } if (key_down(UP_KEY) && (y - CIRCLE_RADIUS > 0)){
            y--;
        } if (key_down(DOWN_KEY) && (y < screen_height() - CIRCLE_RADIUS)){
            y++;
        }
        clear_screen(COLOR_WHITE);
        fill_circle(COLOR_GREEN, x, y, CIRCLE_RADIUS);
        refresh_screen(60);
    }
    return 0;
}