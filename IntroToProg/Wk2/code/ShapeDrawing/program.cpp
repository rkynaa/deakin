#include "splashkit.h"

void draw_house_scene()
{
    clear_screen(COLOR_WHITE);
    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);
    refresh_screen();
}

int main()
{
    open_window("House Drawing", 800, 600);
    draw_house_scene();
    delay(5000);

    // Draw the second scene here... hint: start by clearing the screen!
    clear_screen(COLOR_BLACK);
    fill_ellipse(COLOR_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_WHITE, 300, 300, 200, 200);
    fill_triangle(COLOR_BLUE, 250, 300, 400, 150, 550, 300);
    refresh_screen();
    delay(5000);

    draw_house_scene();
    delay(5000);

    return 0;
}
