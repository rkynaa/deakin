#include "splashkit.h"
#include "terminal_user_input.h"

int main()
{
    string name;
    int age;
    double random;

    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");

    write_line(name);
    write("Age: ");
    write_line(age);

    random = read_double("Enter a random number (in decimals, please?): ");

    write("You entered: ");
    write_line(random);

    return 0;
}
