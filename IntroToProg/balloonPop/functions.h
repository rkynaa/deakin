#include "splashkit.h"


void load_resources() {
    load_bitmap("balloon", "Balloon.png");
    load_bitmap("baloon_pop", "baloon_pop.png");
    load_sound_effect("pop", "popBalloon.wav");
    load_sound_effect("scoregain", "scoregain.wav");
    load_sound_effect("background_sound", "background.wav");
}

void initialize_game() {
    open_window("Balloon pop!", 800, 800);
    clear_screen(COLOR_SKY_BLUE);
    // play_sound_effect("background_sound");
}