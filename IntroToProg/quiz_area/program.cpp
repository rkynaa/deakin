#include "splashkit.h"

double read_double(string prompt){
    string input = "empty";
    write(prompt);
    input = read_line();
    return convert_to_double(input);
}

int main(){
    double pi = 3.14159;
    double radius = 0;
    double area = 0;
    radius = read_double ("Please give me a radius: ");
    area = pi * (radius * radius);
    write_line("The area of the circle is: " + std::to_string(area) );
    return 0;
}
