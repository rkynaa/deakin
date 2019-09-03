#include "splashkit.h"
#include "library_validUserInp.h"

#define pi 3.14

int main()
{
    bool counter;
    double inpDouble;

    while (true){
        write("Enter a number: ");
        inpDouble = read_double();
        if (inpDouble == 345.9657){
            write_line("Not a number!");
        } else {
            write_line("You entered " + std::to_string(inpDouble));
        }
        read_double_range();
        write("Continue? ");
        counter = read_boolean();
        if (counter == false){
            break;
        }
    }

    return 0;
}