#include "splashkit.h"

void display_menu() {
    for (int i = 1; i <= 3; i++){
        write(std::to_string(i) + ": ");
        if (i == 1) {
            write_line("Pounds to Kilograms");
        } else if (i == 2) {
            write_line("Kilograms to Pounds");
        } else {
            write_line("Quit");
        }
    }
}

void kilograms_to_pounds() {
    string input;
    double res;
    write("Enter your number: ");
    input = read_line();
    if (is_number(input)){
        write_line("You entered " + input + " pounds");
        res = convert_to_double(input) * 0.45359237;
        write_line("It has been converted into " + std::to_string(res) + " kilograms");
    } else {
        write_line("You did not enter a number!");
    }
}
void pounds_to_kilogram() {
    string input;
    double res;
    write("Enter your number: ");
    input = read_line();
    if (is_number(input)){
        write_line("You entered " + input + " kilograms");
        res = convert_to_double(input) / 0.45359237;
        write_line("It has been converted into " + std::to_string(res) + " pounds");
    } else {
        write_line("You did not enter a number!");
    }
}

void select_menu(){
    string input;
    int inpOpt = 0;
    while (inpOpt != 3) {
        write("Select your option: ");
        input = read_line();
        if (is_number(input)){
            inpOpt = convert_to_integer(input);
            write("You choose the ");
            if (inpOpt == 1){
                write_line("'Pounds to Kilograms' option");
                pounds_to_kilogram();
            } else if (inpOpt == 2){
                write_line("'Kilograms to Pounds' option");
                kilograms_to_pounds();
            } else if (inpOpt == 3){
                write_line("'Quit' option");
            } else {
                write_line("Please enter available option!");
            }
        } else {
            write_line("Your input is not a number!");
        }
    }
}

int main()
{
    display_menu();
    select_menu();
    return 0;
}