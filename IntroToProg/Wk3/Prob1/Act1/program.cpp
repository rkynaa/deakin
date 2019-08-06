#include "splashkit.h"

int main()
{
    string name; // Initialization of the 'name' variable
    write_line("Please enter your name: "); // it will print "Pleaase enter your name: " and a newline
    name = read_line(); // it will read any value that you entered
    write_line("Nice to meet you, " + name); // it will print "Nice to meet you ", the 'name' variable's value and a newline

    return 0; // it will return 0
}
