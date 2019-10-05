#include "splashkit.h"

string read_string ( string prompt )
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

int read_integer ( string prompt )
{
    string line;
    int result;

    line = read_string(prompt);
    result = convert_to_integer(line);

    return result;
}

int main()
{
    string names[3];

    names[0] = "Bryan";
    names[1] = "Mario";
    names[2] = "Nicky";

    write_line(names[0]);
    write_line(names[1]);
    write_line(names[2]);

    return 0;
}