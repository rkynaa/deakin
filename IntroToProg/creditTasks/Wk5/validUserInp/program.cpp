#include "splashkit.h"
#include "library_validUserInp.h"

#define pi 3.14

// double read_double_range(int min, int max){
//     string input = read_line();
//     double conv_inp = convert_to_integer(input);
//     if (is_double(input) && conv_inp > min && conv_inp < max){
//         return conv_inp;
//     } else {
//         conv_inp;
//     }
// }

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