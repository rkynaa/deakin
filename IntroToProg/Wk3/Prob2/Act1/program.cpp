#include "splashkit.h"

int main()
{
    double length, width, area; // initialization of 'length', 'width' and 'area' variables

    length = 100.51; // it assigns a value into the 'length' variable
    width = 50.5; // it assigns a value into the 'width' variable

    area = length * width; // it will assign the 'area' variable with the result of multiplication between 'length' and 'width'

    write("The area is : " + std::to_string(area)); // it will print "The area is : " with the value of the 'area' variable

    return 0;
}
