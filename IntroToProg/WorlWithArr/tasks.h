#include "splashkit.h"
#include <string.h>

int index_of(string value, string data[], int size){
    for (int i = 0; i < size; i++){
        if (value == data[i]){
            return i;
        }
    }
    return -1;
}

void print_summary(string data[], int size){
    int index = -1;
    for (int i = 0; i < size; i++){
        write_line("Name: " + data[i]);
        write_line("Total length: " + std::to_string(data[i].length()) +"\n");
    }
    for (int i = 0; i < size; i++){
        if ("Rakyan" == data[i]){
            index = i;
            break;
        }
    }
    write_line("The index of your name is " + std::to_string(index));
}