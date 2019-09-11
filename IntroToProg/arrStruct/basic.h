#include "splashkit.h"
#include <string.h>
#include <ctype.h>

using namespace std;

// int options(string opt[]){
//     string optionStr;
//     int sizeArr;
//     while (optionStr != "default") {
//         sizeArr = (int) sizeof(opt) / sizeof(opt[0]);
//         for (int i = 0; i < sizeArr; i++){
//             write_line(to_string(i) + ". " + opt[i]);        
//         }
//         write("Select your option: ");
//         optionStr = read_line();
//         if (is_number(optionStr)) {
//             int optionInt = convert_to_integer(optionStr);
//             write_line("You choose the '" + opt[optionInt] + "' options");
//             write_line("");
//             return optionInt;
//         } else {
//             write_line("Option not available");
//             write_line("");
//             optionStr = "default";
//         }

//     }
//     return -1;
// }

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