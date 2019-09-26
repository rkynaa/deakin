#include "splashkit.h"

void draw_house_scene()
{
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen();
}

// My own procedure AND draw (Iron Man's Arc Reactor)
void draw_arc_reactor(){
    clear_screen(COLOR_BLACK);
    fill_circle(COLOR_GRAY, 400, 300, 200);
    fill_circle(COLOR_BLUE, 400, 300, 160);
    fill_triangle(COLOR_GRAY, 250, 200, 400, 475, 550, 200);
    fill_triangle(COLOR_BLUE, 270, 210, 400, 440, 530, 210);
    refresh_screen();
}

int main()
{
    open_window("House Drawing", 800, 600);
    // draw_house_scene();
    // delay(5000);

    // Draw the second scene here... hint: start by clearing the screen!
    draw_arc_reactor();
    delay(5000);

    // draw_house_scene();
    // delay(5000);

    return 0;
}
