#include "splashkit.h"

using namespace std;

// int select_knight(const kingdom_data &kingdom){
//     return 0;
// }

void show_menu(){
    for (int i = 1; i <= 3; i++){
        write(to_string(i) + ". ");
        if (i == 1){
            write_line("Add knight");
        } else if (i == 2){
            write_line("Delete knight");
        } else {
            write_line("Display details");
        }
    }
}

void add_knight(kingdom &kingdom_main){
}

// void update_knight(){
    
// }

// EXTRA CODES

int options(string options[], int size) {
    string input;
    int intInp;
    write("Choose one of the following options: ");
    input = read_line();
    if (is_number(input)){
        intInp = convert_to_integer(input);
        if (intInp >= 1 && intInp <= size) {
            write_line("You choose '" + options[intInp-1] + "'");
            write_line("");
            return intInp;
        } else {
            write_line("Oops! You exited the program!");
            write_line("");
            return -1;
        }
    } else {
        write_line("Your input is not a number!");
        write_line("");
    }
    return 0;
}

void display_funct(){
    string opt_dis[2] = {"Display kingdom", "Display knight"};
    int ind1;
    while (true){
        for(int i = 1; i <= 2; i++){
            write_line(to_string(i) + ". " + opt_dis[i-1]);
        }
        ind1 = options(opt_dis, 2);
        if (ind1 >= 1 && ind1 <= 2){
            write_line(opt_dis[ind1-1]);
        }
        break;
    }
}

void select_menu(kingdom &kingdom_main) {
    int ind;
    string opt_main[3] = {"Add knight", "Delete knight", "Display details"};
    while(true){
        show_menu();
        ind = options(opt_main, 3);
        if (ind >= 1 && ind <= 3){
            if (ind == 1){
                add_knight(kingdom_main);
            }
            if (ind == 3) {
                display_funct();
            }
        } else {
            if (ind == -1) {
                break;
            }
        }
    }
}