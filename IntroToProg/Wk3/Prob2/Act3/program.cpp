#include "splashkit.h"

double read_str_dou();

int main()
{
    double length, width, area;

    length = read_str_dou();

    if (length == -1) {
        write_line("Not a number!");
        return 0;
    } else {
        write_line("Length: " + std::to_string(length));
    }

    width = read_str_dou();

    if (width == -1) {
        write_line("Not a number!");
        return 0;
    } else {
        write_line("Width: " + std::to_string(width));
    }
    area = length * width;
    write("The area is : " + std::to_string(area));
    return 0;
}

double read_str_dou() {
    string str_var;
    double d_var;

    write("Enter your value: ");
    str_var = read_line();
    if (!is_double(str_var)) {
        write_line("Incorrect input! Try again!");
        return -1;
    } else {
        d_var = convert_to_double(str_var);
    }
    return d_var;
}
