#include "splashkit.h"
#include <string>
using namespace std;

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

double read_double(string prompt){
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}