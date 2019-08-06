#include "splashkit.h"
#include "string.h"

string nameValid(string inputName) {
    string student[7] = {"Rakyan", "Jonathan", "Kevin", "Nicky", "Mario", "Fadhil"};
    int count = 0;
    while (count < int(sizeof(student)/sizeof(*student))){
        if (inputName == student[count]){
            return "Hey, "+inputName;
        } else {
            if (inputName == "Amit") {
                return "Hello, sir!";
            } else {
                return "I don't know who you are, but let's continue, shall we?";
            }
        }
    }
}

int main()
{
    string name;
    write("Enter your name: ");
    name = read_line();
    write_line(nameValid(name));

    int menu, guesser = 0;
    do
    {
        write_line("Start the game?");
        write_line("(Enter '1' to start and '0' to exit)");
        write("input: ");
        menu = convert_to_integer(read_line());
        switch (menu)
        {
        case 1:
            write("Enter your number: ");
            guesser = convert_to_integer(read_line());
            if (guesser == 9){
                write_line("You're correct!");
            } else {
                write_line("Oops! Try again!");
            }
            break;
        case 0:
            write_line("Thank you!");
            break;
        default:
            write_line("Wrong input! Try again!");
            break;
        }
    } while (menu != 0);

    return 0;
}
