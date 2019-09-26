#include "splashkit.h"

int main()
{
    open_window("Make A Scene!", 800,800);
    load_bitmap("kingheart1", "King of Hearts-1.png");
    load_bitmap("kingheart2", "King of Hearts-2.png");
    load_bitmap("kingheart3", "King of Hearts-3.png");
    load_bitmap("kingheart4", "King of Hearts-4.png");
    load_sound_effect("laser", "laser.wav");
    int i = 0;
    while (i < 6){
        clear_screen(COLOR_BLACK);
        draw_bitmap("kingheart1", 100,100);
        play_sound_effect("laser");
        refresh_screen();
        delay(500);
        clear_screen(COLOR_BLACK);
        draw_bitmap("kingheart2", 100,100);
        play_sound_effect("laser");
        refresh_screen();
        delay(500);
        clear_screen(COLOR_BLACK);
        draw_bitmap("kingheart3", 100,100);
        play_sound_effect("laser");
        refresh_screen();
        delay(500);
        clear_screen(COLOR_BLACK);
        draw_bitmap("kingheart4", 100,100);
        play_sound_effect("laser");
        refresh_screen();
        delay(500);
        i++;
    }    
}