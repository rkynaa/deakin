#include "splashkit.h"
#include "teminal"
#include <string.h>
#include <ctype.h>

string trim_str(string input){
    int len_inp = input.length();
    char inpArrChar[len_inp];
    string result;
    strcpy(inpArrChar,input.c_str());
    for (int i = 0; i < len_inp; i++){
        if (!isspace(inpArrChar[i])){
            result += std::string(1,inpArrChar[i]);
        }
    }
    return result;
}

bool read_boolean() {
    string input = to_lowercase(read_line());
    input = trim_str(input);
    if (input == "yes" || input == "y") {
        return true;
    } else {
        return false;
    }
}

double read_double(){
    string input = read_line();
    double pass;
    if (is_double(input)){
        pass = convert_to_double(input);
    } else {
        pass = 345.9657;
    }
    return pass;
}

void read_double_range(){
    double min, max, mid;
    bool minInd = true, maxInd = true, midInd = true, counter;
    while (minInd){
        write("Enter your minimum: ");
        min = read_double();
        if (min != 345.9657) {
            while (maxInd) {
                write("Enter your maximum: ");
                max = read_double();
                if (max != 345.9657) {
                    if (max <= min) {
                        write("Are you sure that is your maximum? ");
                        counter = read_boolean();
                        if (!counter){
                            write("Okay! ");
                        } else {
                            if (max < min){
                                write_line("Your maximum is less than your minimum");
                            } else {
                                write_line("Your maximum is equal to your minimum");
                            }
                            maxInd = false;
                        }
                    } else {
                        while (midInd){
                            write("Enter a number between " + std::to_string(min) + " and " + std::to_string(max) + " : ");
                            mid = read_double();
                            if (mid != 345.9657) {
                                write("You entered " + std::to_string(mid));
                                if (mid > min && mid < max){
                                    write_line(", which is between " + std::to_string(min) + " and " + std::to_string(max));
                                } else {
                                    write_line(", which is not between " + std::to_string(min) + " and " + std::to_string(max));
                                }
                                midInd = false;
                                maxInd = false;
                                minInd = false;
                            } else {
                                write("Are you sure that is your input? ");
                                counter = read_boolean();
                                if (!counter){
                                    write("Okay! ");
                                } else {
                                    write_line("You didn't enter a number!");
                                    midInd = false;
                                }
                            }
                        }
                        midInd = true;
                    }
                } else {
                    write("Are you sure that is your maximum? ");
                    counter = read_boolean();
                    if (!counter){
                        write("Okay! ");
                    } else {
                        write_line("You didn't enter a number!");
                        maxInd = false;
                    }
                }
            }
            maxInd = true;
        } else {
            write("Are you sure that is your minimum? ");
            counter = read_boolean();
            if (!counter){
                write("Okay! ");
            } else {
                write_line("You didn't enter a number!");
                minInd = false;
            }
        }
    }
    minInd = true;
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