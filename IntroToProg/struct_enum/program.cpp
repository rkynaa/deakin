#include "splashkit.h"
#include "termi"
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
    WRITE_KNIGHT,
    UPDATE_KNIGHT,
    READ_QUEST,
    WRITE_QUEST,
    UPDATE_QUEST,
    QUIT,
    DEFAULT
};

string read_string(string prompt){
    string temp;
    write(prompt);
    temp = read_line();
    return temp;
}

int read_integer(string prompt){
    string tempStr;
    int tempInt;
    tempStr = read_string(prompt);
    if (is_number(tempStr)){
        tempInt = convert_to_integer(tempStr);
        return tempInt;
    } else {
        write_line("Wrong data type! Try again!");
    }
    return -1;
};

knight read_knight(){
    struct knight curr;
    bool ind = true;
    int temp;
    while (ind){
        curr.name_knight = read_string("Enter a name: ");
        temp = read_integer("Enter age: ");
        if (temp != -1){
            curr.age = temp;
            curr.valid = true;
            write_knight(curr);
            ind = false;
        }
    }
    return curr;
}

void write_knight(knight &curr){
    if (curr.valid){
        write_line("Your current knight's name is: " + curr.name_knight);
        write_line("And the knight's age is: " + to_string(curr.age));
    } else {
        write_line("Your knight does not have a name and/or age");
    }
}

void update_knight(knight &curr){
    if (curr.valid) {
        int tempOpt, tempAge;
        bool ind1 = true, ind2 = true;
        while (ind1) {
            string options[2] = {"Update name", "Update age"};
            for (int i = 0; i < (sizeof(options)/sizeof(string)); i++){
                write_line(to_string(i+1) + ". " + options[i]);
            }
            tempOpt = read_integer("Select your option: ");
            if (tempOpt != -1) {
                if (tempOpt >= 1 && tempOpt <= 2) {
                    if (tempOpt == 1) {
                        curr.name_knight = read_string("Enter new knight's name: ");
                    } else {
                        while (ind2) {
                            tempAge = read_integer("Enter new age: ");
                            if (tempAge != -1) {
                                ind2 = false;
                            }
                        }
                    }
                    write_knight(curr);
                    ind1 = false;
                } else {
                    write_line("Option not available! Try again!");
                }
            }
        }
    } else {
        write_line("Your knight does not have any name and/or age");
    }
}

void read_quest (knight &curr) {
    if (!curr.valid) {
        bool ind = true;
        string input;
        while (ind){
            curr.quest = read_string("Enter quest: ");
        }
    } else {
        write_line("Your knight already have quest!");
    }
}

void write_quest (knight &curr) {
    if (curr.validQuest) {
        write_line("Your knight's current quest is to " + curr.quest);
    } else {
        write_line("Your knight is in idle.");
    }
}

void update_quest(knight &curr){
    if (curr.valid) {
        int tempOpt, tempAge;
        bool ind1 = true, ind2 = true;
        while (ind1) {
            curr.quest = read_string("Enter new quest: ");
            ind1 = false;
        }
    } else {
        write_line("Your knight does not have anything to do!");
    }
}

knight_update_options selectopt(knight &currknight) {
    string input;
    int tempInp, inp;
    string options[7] = {"Write Knight", "Read Knight", "Update Knight", "Write Quest", "Read Quest", "Update Quest", "Quit"};
    bool ind = true;
    int size = (sizeof(options)/sizeof(string));
    while (ind) {
        for (int i = 0; i < size; i++){
            write_line(to_string(i+1) + ". " + options[i]);
        }
        tempInp = read_integer("Enter your option: ");
        if (tempInp != -1){
            if (tempInp >= 1 && tempInp <= size) {
                write_line("You choose the '" + options[tempInp - 1] + "' Option");
                if (tempInp == 1) {
                    write_knight(currknight);
                    return WRITE_KNIGHT;
                } else if (tempInp == 2) {
                    currknight = read_knight();
                    return READ_KNIGHT;
                } else if (tempInp == 3) {
                    update_knight(currknight);
                    return UPDATE_KNIGHT;
                } else if (tempInp == 4) { 
                    write_quest(currknight);
                    return WRITE_QUEST;
                } else if (tempInp == 5) {
                    read_quest(currknight);
                    return READ_QUEST;
                } else if (tempInp == 6) {
                    update_quest(currknight);
                    return UPDATE_QUEST;
                } else {
                    write_line("You choose to quit! See you!");
                    return QUIT;
                }
            } else {
                write_line("Option not available! Try again!");
            }
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