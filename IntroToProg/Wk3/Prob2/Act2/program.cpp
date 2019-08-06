#include "splashkit.h"

double read_str_dou();

int main()
{
    double length, width, area; // Initializing 'length', 'width' and 'area' variables

    length = read_str_dou(); // it will run the 'read_str_dou' function for assigning the value
    write_line("Length: " + std::to_string(length)); // It will print "Length: ", the value of 'length' and a newline

    width = read_str_dou(); // it will run the 'read_str_dou' function for assigning the value
    write_line("Width: " + std::to_string(width)); // It will print "Width: ", the value of 'width' and a newline

    area = length * width; // it will assign the 'area' variable with the result of multiplication between 'length' and 'width'
    write("The area is : " + std::to_string(area)); // it will print 'The area is : ' with the value of 'area' at the end.
    return 0; // it will return the value of 0
}

double read_str_dou() {
    write("Enter your value: "); // it will write "Enter your value: "
    double var = convert_to_double(read_line()); // it will read any value that you type and convert it at the same time into double
    return var; // it will return the 'var' variable
}
