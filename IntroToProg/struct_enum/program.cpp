#include "splashkit.h"
//#include "structs.h"
//#include "functs.h"
#include "basic.h"
#include <vector>

using namespace std;

struct knight{
    bool valid;
    bool validQuest;
    string name_knight;
    int age;
    string quest;
};

enum knight_update_options {
    READ_KNIGHT,
    WRITE_KINGHT,
    UPDATE_KNIGHT,
    READ_QUEST,
    WRITE_QUEST,
    UPDATE_QUEST,
    QUIT,
    DEFAULT
};

void read_knight(knight &curr){
    if (curr.valid){
        write_line("Your current knight's name is: " + curr.name_knight);
        write_line("And the knight's age is: " + to_string(curr.age));
    } else {
        write_line("Your knight does not have a name and/or age");
    }
}

void write_knight(knight &curr){
    if (!curr.valid) {
        bool ind = true;
        string input;
        while (ind){
            write("Enter a name: ");
            curr.name_knight = read_line();
            write("Enter age: ");
            input = read_line();
            if (is_number(input)){
                curr.age = convert_to_integer(input);
                curr.valid = true;
                read_knight(curr);
                ind = false;
            } else {
                write_line("Wrong data type! Try again!");
            }
        }
    } else {
        write_line("Your knight is already have name and/or age!");
    }
}

void update_knight(knight &curr){
    if (curr.valid) {
        string input;
        bool ind1 = true, ind2 = true;
        while (ind1) {
            string options[2] = {"Update name", "Update age"};
            for (int i = 0; i < (sizeof(options)/sizeof(string)); i++){
                write_line(to_string(i+1) + ". " + options[i]);
            }
            write("Select your option: ");
            input = read_line();
            if (is_number(input)) {
                int inp = convert_to_integer(input);
                if (inp >= 1 && inp <= 2) {
                    if (inp == 1) {
                        write("Enter new knight's name: ");
                        input = read_line();
                        curr.name_knight = input;
                    } else {
                        while (ind2) {
                            write("Enter age: ");
                            input = read_line();
                            if (is_number(input)) {
                                inp = convert_to_integer(input);
                                ind2 = false;
                            } else {
                                write_line("Wrong data type! Try again!");
                            }
                        }
                    }
                    read_knight(curr);
                    ind1 = false;
                } else {
                    write_line("Option not available! Try again!");
                }
            } else {
                write_line("Wrong data type! Try again!");
            }
        }
    } else {
        write_line("Your knight does not have any name and/or age");
    }
}

void read_quest (knight &curr) {
    if (curr.validQuest) {
        write_line("Your knight's current quest is to " + curr.quest);
    } else {
        write_line("Your knight is in idle.");
    }
}

void write_quest (knight &curr) {
    if (curr.valid) {
        
    } else {
        write_line("Your knight does not have an age and/or age");
    }
}

knight_update_options selectopt(knight &currknight) {
    string input;
    int inp;
    string options[4] = {"Write Knight", "Read Knight", "Update Knight", "Quit"};
    bool ind = true;
    int size = (sizeof(options)/sizeof(string));
    while (ind) {
        for (int i = 0; i < size; i++){
            write_line(to_string(i+1) + ". " + options[i]);
        }
        write("Choose your option: ");
        input = read_line();
        if (is_number(input)){
            inp = convert_to_integer(input);
            if (inp >= 1 && inp <= size) {
                write_line("You choose the '" + options[inp - 1] + "' Option");
                if (inp == 1) {
                    write_knight(currknight);
                    return WRITE_KINGHT;
                } else if (inp == 2) {
                    read_knight(currknight);
                    return READ_KNIGHT;
                } else if (inp == 3) {
                    update_knight(currknight);
                    return UPDATE_KNIGHT;
                } else {
                    write_line("You choose to quit! See you!");
                    return QUIT;
                }
            } else {
                write_line("Option not available! Try again!");
            }
        } else {
            write_line("Wrong data type! Try again!");
        }
    }
    return DEFAULT;
}

int main()
{
    knight mainKnight;
    mainKnight.valid = false;
    mainKnight.validQuest = false;
    // add_knight(mainKingdom);
    knight_update_options mainOpt = DEFAULT;
    while (mainOpt != QUIT) {
        mainOpt = selectopt(mainKnight);
    }
    return 0;
}