#include "splashkit.h"

int read_integer(string prompt)
{
    string line;
    write(prompt);

    line = read_line();
    return convert_to_integer(line);
}

int main()
{
// Demo #1 - create an array of ???
    // 1. Array of integers - DATATYPE: int     IDENTIFIER: data     SIZE:[5]
    int data[5];
    // 2. Array of doubles - DATATYPE: double     IDENTIFIER: grades     SIZE:[10]
    double grades[10];
    // 3. Arrary of strings - DATATYPE: string     IDENTIFIER: names     SIZE:[50]
    string names[50];
    string test[10];
// Note that our format for declaring an array remains the same: DATATYPE IDENTIFIER[SIZE]; 
// Note that the square brackets here are used to specify the size of the array




// Demo #2 - store values in our arrary
// Note: this demo uses the read_integer function declared above
    data[0] = read_integer("Enter a value: "); // store the value returned by read_integer() into the data array at the first position
    data[1] = read_integer("Enter a value: "); // store the value returned by read_integer() into the data array at the second position
    data[2] = read_integer("Enter a value: "); // store the value returned by read_integer() into the data array at the third position
    data[3] = read_integer("Enter a value: "); // store the value returned by read_integer() into the data array at the fourth position
    data[4] = read_integer("Enter a value: "); // store the value returned by read_integer() into the data array at the fifth position
//  data[5] = read_integer("Enter a value: "); // this statement would cause our program to crash - why?
    grades[2] = 34.5;
    names[49] = "Alan Smithee";
// Remember that arrays always start at an index value of 0 and end at an index value of (size of array - 1)
// Note that the square brackets here are used to access a position in the array - this is different to how they're used when creating the array




// Demo #3 - output values from array
    write_line("You entered: ");

    write_line(data[0]); // Retrieve the value stored in the first position in our array and write to the screen
    write_line(data[1]); // Retrieve the value stored in the second position in our array and write to the screen
    write_line(data[2]); // Retrieve the value stored in the third position in our array and write to the screen
    write_line(data[3]); // Retrieve the value stored in the fourth position in our array and write to the screen
    write_line(data[4]); // Retrieve the value stored in the fifth position in our array and write to the screen
//  The above five statements will ouput the values stored in the data array...what if we needed to display all the contents of the names array?
//      write_line(names[0]);
//      write_line(names[1]);
//      ...
//      write_line(names[48]);
//      write_line(names[49]);
//  This arrary would require 50 statemtns to be written! Now imagine if the arrary had a size of 2000, or 30000, or even higher. That's a lot of lines of code!!!
//  Good news: there's a better way to do this





// demo #4 - variable index and while loop
    write_line("Displaying results using a while loop:");    

    int i = 0; // create a variable to track our position in the array
    while (i < 5) // once i is equal to 5 (the first number outside the bounds of our array of 0-4) we need to stop looping
    {
        write_line(data[i]); // display the contents of the data array at the position matching the value of i
        i++; // increment i by 1 (i.e. i = i + 1;)
    }
// note the need to create a variable to track our position in the array (i) and the need to update this variable (i++) - these statements can be grouped together using a new kind of loop structure 





// demo #5 - variable index with for loop
    write_line("Displaying results using a for loop:");    

    for (int i = 0; i < 5; i++) // create the counter variable (int i = 0), set the loop condition (i < 5), and tell i how to update aftereach loop (i++) - all in the one structure
    {
        write_line(data[i]); // notice that this statement is the same as the statement in the while loop
    }
// general structure of the for loop: for(INITIALISE_COUNTER;   LOOPING_CONDITION;   UPDATE_COUNTER) {}
// a for loop is best used in situations like handling arrays as we know exactly how many times we need to loop (the size of the array). When we don't know how many times we need to loop we should use another method (while, do...while)


    int count = 10;
    while (count < 10){
        write_line(test[count]);
    }


// bonus demo - for each loop
// a different version of the for loop is the for each loop, which focuses on accessing data directly without using the index position of an array
    write_line("Displaying results using a for each loop: ");
    
    for(int val : data) // typically read this line as "for each variable in the data array" - each time we loop we retireve the next integer in the data array and store it in the val variable
    {
        write_line(val); // notice that this statement is DIFFERENT to the previous statements in our loops - this is because we don't store the position of the array anymore
    } 
// The main difference between a for and for each is that:
//  - a for loop requires us to track the index position of our data, but this allows us to skip over positions (e.g. the update to our counter could be i+=2 instead of i++ which would let us display every second number) 
//  - a for each loop lets us look at the data in each position of the array without having to track the index, but we can't change how the loop updates (so we always end up looping through the entire array)

    return 0;
}