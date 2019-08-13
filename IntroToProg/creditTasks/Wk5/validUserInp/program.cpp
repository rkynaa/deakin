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
    string name = "default";
    int age = 0;
    double radius = 0;
    bool counter = true;

    while (counter){
        enter_name(name);
        enter_age(age);
        enter_radius(radius);
        decideMinMax();
        write("Continue? ");
        counter = read_boolean();
    }
    return 0;
}