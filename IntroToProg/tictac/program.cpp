#include "splashkit.h"
using namespace std;
#include <stdio.h>
#define N 8
#define sizeMini 200

string numberBox[10] = {"o", "1","2","3","4","5","6","7","8","9"};

void createBoard(string prompt, string prompt2){
    clear_screen(COLOR_WHITE);
    fill_rectangle(COLOR_BLACK, 80, 80, 640, 640);
    int index[3] = {90, 300, 510};
    string bitmaps[10] = {"test", "number-1", "number-2", "number-3", "number-4", "number-5", "number-6", "number-7", "number-8", "number-9"};
    int x = 1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            fill_rectangle(COLOR_WHITE, index[i], index[j], sizeMini, sizeMini);
            if (numberBox[x] == "X"){
                draw_bitmap("cross", index[i] + 30, index[j] + 30, option_to_screen());
            } else if (numberBox[x] == "O"){
                draw_bitmap("dash", index[i] + 30, index[j] + 30, option_to_screen());
            } else {
                draw_bitmap(bitmaps[x], index[i] + 30, index[j] + 30, option_to_screen());
            }
            x++;
        }
    }
    draw_text(prompt, COLOR_BLACK, 80, 740, option_to_screen());
    if (prompt2 == "Invalid Move") {
        draw_text(prompt2, COLOR_RED, 80, 760, option_to_screen());
    }
    refresh_screen(60);
}

int ifWin()
{
    if (numberBox[1] == numberBox[2] && numberBox[2] == numberBox[3])

        return 1;
    else if (numberBox[4] == numberBox[5] && numberBox[5] == numberBox[6])

        return 1;
    else if (numberBox[7] == numberBox[8] && numberBox[8] == numberBox[9])

        return 1;
    else if (numberBox[1] == numberBox[4] && numberBox[4] == numberBox[7])

        return 1;
    else if (numberBox[2] == numberBox[5] && numberBox[5] == numberBox[8])

        return 1;
    else if (numberBox[3] == numberBox[6] && numberBox[6] == numberBox[9])

        return 1;
    else if (numberBox[1] == numberBox[5] && numberBox[5] == numberBox[9])

        return 1;
    else if (numberBox[3] == numberBox[5] && numberBox[5] == numberBox[7])

        return 1;
    else if (numberBox[1] != "1" && numberBox[2] != "2" && numberBox[3] != "3" 
                    && numberBox[4] != "4" && numberBox[5] != "5" && numberBox[6] != "6" 
                  && numberBox[7] != "7" && numberBox[8] != "8" && numberBox[9] != "9")

        return 0;
    else
        return -1;
}

int main()
{
    open_window("Tic Tac Toe", 800, 800);
    load_bitmap("number-1", "Number-1-icon.png");
    load_bitmap("number-2", "Number-2-icon.png");
    load_bitmap("number-3", "Number-3-icon.png");
    load_bitmap("number-4", "Number-4-icon.png");
    load_bitmap("number-5", "Number-5-icon.png");
    load_bitmap("number-6", "Number-6-icon.png");
    load_bitmap("number-7", "Number-7-icon.png");
    load_bitmap("number-8", "Number-8-icon.png");
    load_bitmap("number-9", "Number-9-icon.png");
    load_bitmap("cross", "Button-Close-icon.png");
    load_bitmap("dash", "Button-delete-icon.png");
	int currPlayer = 1,i,typed;
    string temp, sign, prompt, prompt2;
    while (not quit_requested())
    {
        process_events();
        currPlayer=(currPlayer%2)?1:2;
        sign=(currPlayer == 1) ? "X" : "O";
        typed = 0;

        prompt = "Player "+ to_string(currPlayer) +", Enter a number: ";
        prompt2 = "";
        if (key_typed(NUM_1_KEY) && numberBox[1] == "1"){
            numberBox[1] = sign;
            typed = 1;
        } else if (key_typed(NUM_1_KEY) && numberBox[1] != "1"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_2_KEY) && numberBox[2] == "2"){
            numberBox[2] = sign;
            typed = 1;
        } else if (key_typed(NUM_2_KEY) && numberBox[2] != "2"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_3_KEY) && numberBox[3] == "3"){
            numberBox[3] = sign;
            typed = 1;
        } else if (key_typed(NUM_3_KEY) && numberBox[3] != "3"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_4_KEY) && numberBox[4] == "4"){
            numberBox[4] = sign;
            typed = 1;
        } else if (key_typed(NUM_4_KEY) && numberBox[4] != "4"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_5_KEY) && numberBox[5] == "5"){
            numberBox[5] = sign;
            typed = 1;
        } else if (key_typed(NUM_5_KEY) && numberBox[5] != "5"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_6_KEY) && numberBox[6] == "6"){
            numberBox[6] = sign;
            typed = 1;
        } else if (key_typed(NUM_6_KEY) && numberBox[6] != "6"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_7_KEY) && numberBox[7] == "7"){
            numberBox[7] = sign;
            typed = 1;
        } else if (key_typed(NUM_7_KEY) && numberBox[7] != "7"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_8_KEY) && numberBox[8] == "8"){
            numberBox[8] = sign;
            typed = 1;
        } else if (key_typed(NUM_8_KEY) && numberBox[8] != "8"){
            prompt2 = "Invalid Move";
        } if (key_typed(NUM_9_KEY) && numberBox[9] == "9"){
            numberBox[9] = sign;
            typed = 1;
        } else if (key_typed(NUM_9_KEY) && numberBox[9] != "9"){
            prompt2 = "Invalid Move";
        }
        createBoard(prompt, prompt2);
        if (typed == 1) {
            currPlayer++;
        }
        i = ifWin();
        if (i != -1) {
            break;
        }
    }
    if (i == 1) {
        draw_text("Player " + to_string(--currPlayer) + " is the winner!", COLOR_RED, 80, 780, option_to_screen());
    } else {
        draw_text("DRAW", COLOR_RED, 200, 200, option_to_screen());
    }
    refresh_screen();
    delay(5000);
    return 0;
}