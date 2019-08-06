#include "splashkit.h"

#include <string>
using namespace std;

#define STROUHAL 0.33;

double air_speed(double freq, double amp){
    double result;
    result = freq * amp / STROUHAL;
    return result;
}

void output_air_speed(string name, double freq, double amp){
    write(name + ": ");
    write_line(air_speed(freq, amp));
}

string read_string(string prompt){
    string result;

    write(prompt);
    result = read_line();
    return result;
}

int read_integer(string prompt){
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

string read_random(string prompt){
    string input, output;
    int inp;
    bool counter = true;
    while(counter)
    {
        input = read_string(prompt);
        if (!is_integer(input))
        {
            output =  "Not a number! try again!";
        } else {
            inp = convert_to_integer(input);
            if (inp < 0) {
                output = "let me guess, your number is a negative one, right?";
            } else if (inp > 0){
                output = "Positive number, very positive!";
            } else {
                output = "Zero? That's a bit depressing...";
            }
            counter = false;
        }
    }
    return output;
}

int main()
{
    string name, random;
    int age;

    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");

    write_line(name);
    write("Age: ");
    write_line(age);

    output_air_speed("Africal Swallow", 15, 0.21);
    output_air_speed("European Swallow", 14, 0.22);
    output_air_speed("Downy Woodpecker", 14, 0.29);

    random = read_random("Pick a number: ");
    write_line(random);
    return 0;
}
