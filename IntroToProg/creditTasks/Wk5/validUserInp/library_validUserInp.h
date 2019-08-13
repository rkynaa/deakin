#include "splashkit.h"

#define pi 3.14

bool read_boolean() {
    string input = to_lowercase(read_line());
    if (input == "yes" || input == "y") {
        return true;
    } else {
        return false;
    }
}

bool read_double(double pass){
    string input = read_line();
    if (is_double(input)){
        pass = convert_to_double(input)
        return true;
    } else {
        return false;
    }
}

void decideMinMax (){
    double min = 0, max = 0, indicator = 0, guess = 0;
    bool minIndicator, maxIndicator;
    while (min){
        write("Enter a minimum number: ");
        minIndicator = read_double(min);
        if (min) {
            write_line("You entered " + std::to_string(min));
            while (max == 0) {
                write ("Enter a maximum number: ");
                maxIndicator = read_double(max);
                if (max != 0) {
                    write_line("You entered " + std::to_string(max));
                    // indicator = read_double_range(min, max, guess)
                    if (indicator == -1) {
                        write_line("Wrong input! try again!");
                        min = 0;
                    } else {
                        write("You entered " + std::to_string(guess))
                        if (indicator == 0) {
                            write_line(", which is not between your minimum and maximum");
                            break;
                        } else {
                            write_line(", which is between your minimum and maximum");
                            break;
                        }
                    }
                } else {
                    write("Are you sure? ");
                    bool counter = read_boolean();
                    if (counter) {
                        write_line("You entered 0");
                        break;
                    } else {
                        write("Okay! ");
                    }
                }
            }
            max = 0;
        } else {
            write("Are you sure? ");
            bool counter = read_boolean();
            if (counter) {
                write_line("You entered 0");
                break;
            } else {
                write("Okay! ");
            }
        }

    }
}

double read_double_range(double min, double max, duble guess){
    double input = read_double();
    if (input == 0){
        return -1;
    } else {
        if (input)
    }
}

void enter_name(string name){
    while (name == "default") {
        write("Enter your name: ");
        name = read_line();
        if (name != "default"){
           write_line("Welcome, "+name);
        } else {
            write_line("Enter a valid name!");
        }
    }
}

void enter_age(int age){
    while (age == 0){
        write("Enter your age: ");
        string input;
        input = read_line();
        if (is_integer(input)){
            age = convert_to_integer(input);
            write_line("You are "+ std::to_string(age) + " years old");
        } else {
            write_line("Try again!");
            age = 0;
        }
    }
}

void enter_radius(double radius){
    bool inpIndicator = false;
    while (radius == 0) {
        write("Enter a number as a radius: ");
        radius = read_double();
        if (radius == 0) {
            write("Are you sure? ");
            bool counter = read_boolean();
            if (counter) {
                write_line("You entered 0");
                break;
            } else {
                write("Okay! ");
            }
        } else {
            double area = pi * radius * radius, perimeter = 2 * pi * radius;
            write_line("The radius is: " + std::to_string(radius));
            write_line("The area of the circle is: " + std::to_string(area));
            write_line("The perimeter of the circle is: " + std::to_string(perimeter));
        }
    }
}