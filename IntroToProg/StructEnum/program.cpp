#include "splashkit.h"

struct knight_data {
    string name;
    int age;
};

knight_data read_knight(){
    knight_data sample;
    bool indicator1 = true, indicator2 = true;
    string inp_name, inp_age;
    int age;
    while (indicator1){
        write("Enter your name: ");
        inp_name = read_line();
        if (inp_name != NULL || !is_number(inp_name)){
            while (indicator2){
                write("Enter your age: ");
                inp_age = read_line();
                if (is_integer(inp_age)){
                    age = convert_to_integer(inp_age);
                    indicator2 = false;
                } else {
                    write_line("Try again!");
                }
            }
            indicator1 = false; 
        } else {
            write_line("try again!");
        }
    }
    sample.name = inp_name;
    sample.age = age;
    return sample;
}

void write_knight(knight_data knight){
    write_line("The knight's name is: " + knight.name);
    write_line("The knight is " + std::to_string(knight.age) + " years old");
}

void update_knight(knight_data &knight) {
    bool indicator1 = true, indicator2 = true;
    string inp_name, inp_age;
    int age;
    while (indicator1)
        write("Enter a new name: ");
        inp_name = read_line();
        if (inp_name != NULL || !is_number(inp_name)){
            while (indicator2){
                write("Enter a new age: ");
                inp_age = read_line();
                if (is_integer(inp_age)){
                    age = convert_to_integer(inp_age);
                    indicator2 = false;
                } else {
                    write_line("Try again!");
                }
            }
            indicator1 = false; 
        } else {
            write_line("try again!");
        }
    }
    knight.name = inp_name;
    knight.age = age;
    return sample;
}

int main()
{
    knight_data knight1 = read_knight();
    write_knight(knight1);
    update_knight(knight1);
    return 0;
}