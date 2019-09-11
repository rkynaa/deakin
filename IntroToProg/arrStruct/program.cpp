#include "splashkit.h"
//#include "structs.h"
//#include "functs.h"
#include "basic.h"
#include <vector>

using namespace std;

struct knight{
    string name_knight;
    int age;
};

struct kingdom {
    string name;
    vector<knight> knights;
};

enum options {
    ADD_KNIGHT,
    
}

void print_point(string &test) {
    write_line(test);
}

void add_knight(kingdom curr){
    knight newKnight;
    bool ind = true;
    while (ind){
        write("Enter knight's name: ");
        string inpName = trim_str(read_line());
        newKnight.name_knight = inpName;
        write_line("You entered: " + newKnight.name_knight);
        write("Enter knight's age: ");
        string inpAge = read_line();
        if (is_number(inpAge)) {
            newKnight.age = convert_to_integer(inpAge);
            write_line("You entered " + to_string(newKnight.age));
            curr.knights.push_back(newKnight);
            ind = false; 
        } else {
            write_line("Wrong data type! Try again!");
        }
    }
}

void set_kingdom(kingdom curr){
    write("Enter kingdom's name: ");
    string inp = read_line();
    curr.name = inp;
}

int main()
{   
    kingdom mainKingdom;
    int opt1;
    set_kingdom(mainKingdom);

    // add_knight(mainKingdom);
    return 0;
}