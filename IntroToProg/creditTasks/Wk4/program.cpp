#include "splashkit.h"

int main()
{
    open_window("Scene_maker", 800, 600);
    load_bitmap("spooky", "spooky.png");
    draw_bitmap_on_window("Scene_maker","spooky", 10, 75);
    delay (1000);
    return 0;
}
