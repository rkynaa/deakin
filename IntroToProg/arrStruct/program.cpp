#include "splashkit.h"
#include <vector>


struct knight{
    bool valid;
    bool validQuest;
    string name_knight;
    int age;
    string quest;
    vector<string> items;
};

struct kingdom {
    vector<knight> knights;
    bool valid;
    string name;
};

enum knight_update_options {
    READ_KNIGHT,
    WRITE_KNIGHT,
    UPDATE_KNIGHT,
    READ_QUEST,
    WRITE_QUEST,
    UPDATE_QUEST,
    QUIT_KNIGHT,
    DEF_KNIGHT
};

enum kingdom_update_options {
    READ_KINGDOM,
    WRITE_KINGDOM,
    ADD_KNIGHT,
    DELETE_KNIGHT,
    QUERY_KNIGHT,
    QUIT_KINGDOM,
    DEF_KINGDOM
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
        write_line("The knight's age is: " + std::to_string(curr.age));
        write_line("The knight already carry " + std::to_string(curr.items.size()));
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
                write_line(std::to_string(i+1) + ". " + options[i]);
            }
            tempOpt = read_integer("Select your option: ");
            if (tempOpt != -1) {
                if (tempOpt >= 1 && tempOpt <= 3) {
                    if (tempOpt == 1) {
                        curr.name_knight = read_string("Enter new knight's name: ");
                    } else if (tempOpt == 2){
                        while (ind2) {
                            tempAge = read_integer("Enter new age: ");
                            if (tempAge != -1) {
                                ind2 = false;
                            }
                        }
                    } else {
                        string item = read_string("Add an item: ");
                        curr.items.push_back(item);
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
            curr.validQuest = true;
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

void read_kingdom(kingdom &curr){
    if (!curr.valid){
        curr.name = read_string("Enter a kingdom name: ");
    } else {
        write_line("Your kingdom already have a name!");
    }
}

void write_kingdom(kingdom &curr){
    if (!curr.valid){
        write_line("Your kingdom name is " + curr.name);
        if (curr.knights.size() > 0) {
            write_line("Your kingdom have " + curr.knights.size());
            curr.valid = true;
        }
    } else {
        write_line("Your kingdom does not have any name!");
    }
}

void add_knight(kingdom &curr) {
    if (curr.valid){
        knight temp;
        write_knight(temp);
        curr.knights.push_back(temp);
    } else {
        write_line("Your kingdom does not have anything, even a name!");
    }
}

void delete_knight(kingdom &curr){
    if (curr.valid){
        if (curr.knights.size != 0) {
            string targetName = read_string("Enter the knight that you want to delete: ");
            for (int i = 0; i < curr.knights.size; i++){
                if (curr.knights[i].name_knight == targetName) {
                    curr.knights.erase(
                        std::remove_if(curr.knights.begin(), curr.knights.end(), [&](knight const &targetKnight) {
                            return targetKnight.name_knight == targetName;
                        }
                    ), curr.knights.end());
                }
            }
        } else {
            write_line("Your kingdom does not have any knight!");
        }
    } else {
        write_line("Your kingdom does not have anything, even a name!");
    }
}

void query_knight(kingdom &curr){
    string targetName = read_string("What's the knight's name: ");
    for (int i = 0; i < curr.knights.size; i++){
        if (curr.knights[i].name_knight == targetName){
            write_line("knight found!");
            write_knight(curr.knights[i]);
        }
    }
}

kingdom_update_options selectOpt_kingdom(kingdom &curr) {
    string input;
    int tempInp, inp;
    string options[6] = {"Write Kingdom", "Read Kingdom", "Add Knight", "Delete Knight", "Query Knight", "Quit"};
    bool ind = true;
    int size = (sizeof(options)/sizeof(string));
    while (ind) {
        for (int i = 0; i < size; i++){
            write_line(std::to_string(i+1) + ". " + options[i]);
        }
        tempInp = read_integer("Enter your option: ");
        if (tempInp != -1){
            if (tempInp >= 1 && tempInp <= size) {
                write_line("You choose the '" + options[tempInp - 1] + "' Option");
                if (tempInp == 1) {
                    write_kingdom(curr);
                    return WRITE_KINGDOM;
                } else if (tempInp == 2) {
                    read_kingdom(curr);
                    return READ_KINGDOM;
                } else if (tempInp == 3) {
                    add_knight(curr);
                    return ADD_KNIGHT;
                } else if (tempInp == 4) {
                    delete_knight(curr);
                    return DELETE_KNIGHT;
                } else if (tempInp == 5) {
                    query_knight(curr);
                    return QUERY_KNIGHT;
                } else {
                    write_line("You choose to quit! See you!");
                    return QUIT_KINGDOM;
                }
            } else {
                write_line("Option not available! Try again!");
            }
        }
    }
    return DEF_KINGDOM;
}

int main()
{
    kingdom mainKingdom;
    // add_knight(mainKingdom);
    kingdom_update_options mainOpt = DEF_KINGDOM;
    while (mainOpt != QUIT_KINGDOM) {
        mainOpt = selectOpt_kingdom(mainKingdom);
    }
    return 0;
}