#include "splashkit.h"
#include <limits>

using namespace std;

int read_integer(string prompt)
{
    string temp;
    unsigned int value = 0;

    write(prompt);
    temp = read_line();
    value = convert_to_integer(temp);

    return value;
}

int main()
{
    // initialise variables with 0 value
    unsigned int input = 0;
    unsigned short result = 0;

    input = read_integer("Please enter a large number: ");
    if (input > numeric_limits<unsigned short>::max()) {
        write_line("Input too large");
        return 0;
    } else {
        result = input;
    }

    write_line("The value stored in the int is: " + std::to_string(input) );
    write_line("The value stored in the short is: " + std::to_string(result) );

    return 0;
}