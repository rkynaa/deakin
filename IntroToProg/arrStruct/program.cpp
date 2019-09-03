#include "splashkit.h"
//#include "structs.h"
//#include "functs.h"

void print_point(string &test) {
    write_line(test);
}

int main()
{   
    // select_menu(): a function to display all available options and it will let the user
    //                choose which program to be executed based on the input
    kingdom kingdom_main = new kingdom;
    kingdom_main.name == "Rakyan's kingdom";
    select_menu();

    
    string *test = (string*)malloc(sizeof(string));
    write("Enter something: ");
    string inp = read_line();
    *test = inp;
    print_point(*test);
    return 0;
}