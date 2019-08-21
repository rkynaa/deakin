#include "splashkit.h"
#include <string.h>
#include <ctype.h>

#define pi 3.14

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
    write_line(result);
    return result;
}