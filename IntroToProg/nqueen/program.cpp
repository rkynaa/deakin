#include "splashkit.h"
using namespace std;
#include <stdbool.h> 
#include <stdio.h> 
#define N 8

#define sizeMini 200

void createBoard(){
    clear_screen(COLOR_WHITE);
    fill_rectangle(COLOR_BLACK, 80, 80, 640, 640);
    int index[3] = {90, 300, 510};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            fill_rectangle(COLOR_WHITE, index[i], index[j], sizeMini, sizeMini);
        }
        draw_text("Choose your box: ", COLOR_BLACK, 80, 740, option_to_screen());
    }
    refresh_screen(60);
}

int main()
{
    open_window("Circle Moving", 800, 800);
    while (not quit_requested())
    {
        process_events();
        createBoard();
    }
    return 0;
}

// #include <iostream>
// using namespace std;

// char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

// int checkwin();
// void board();

// int main()
// {
// 	int player = 1,i,choice;
//     string temp;
//     char mark;
//     do
//     {
//         board();
//         player=(player%2)?1:2;

//         write("Player "+ player +", Enter a number: ");
//         temp = read_line;
//         choice = convert_to_integer(temp);

//         mark=(player == 1) ? 'X' : 'O';

//         if (choice == 1 && square[1] == '1')

//             square[1] = mark;
//         else if (choice == 2 && square[2] == '2')

//             square[2] = mark;
//         else if (choice == 3 && square[3] == '3')

//             square[3] = mark;
//         else if (choice == 4 && square[4] == '4')

//             square[4] = mark;
//         else if (choice == 5 && square[5] == '5')

//             square[5] = mark;
//         else if (choice == 6 && square[6] == '6')

//             square[6] = mark;
//         else if (choice == 7 && square[7] == '7')

//             square[7] = mark;
//         else if (choice == 8 && square[8] == '8')

//             square[8] = mark;
//         else if (choice == 9 && square[9] == '9')

//             square[9] = mark;
//         else
//         {
//             write("Invalid move ");

//             player--;
//             cin.ignore();
//             cin.get();
//         }
//         i=checkwin();

//         player++;
//     } while(i==-1);
//     board();
//     if(i==1)

//         cout<<"==>\aPlayer "<<--player<<" win ";
//     else
//         cout<<"==>\aGame draw";

//     cin.ignore();
//     cin.get();
//     return 0;
// }

// /*********************************************
//     FUNCTION TO RETURN GAME STATUS
//     1 FOR GAME IS OVER WITH RESULT
//     -1 FOR GAME IS IN PROGRESS
//     O GAME IS OVER AND NO RESULT
// **********************************************/

// int checkwin()
// {
//     if (square[1] == square[2] && square[2] == square[3])

//         return 1;
//     else if (square[4] == square[5] && square[5] == square[6])

//         return 1;
//     else if (square[7] == square[8] && square[8] == square[9])

//         return 1;
//     else if (square[1] == square[4] && square[4] == square[7])

//         return 1;
//     else if (square[2] == square[5] && square[5] == square[8])

//         return 1;
//     else if (square[3] == square[6] && square[6] == square[9])

//         return 1;
//     else if (square[1] == square[5] && square[5] == square[9])

//         return 1;
//     else if (square[3] == square[5] && square[5] == square[7])

//         return 1;
//     else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
//                     && square[4] != '4' && square[5] != '5' && square[6] != '6' 
//                   && square[7] != '7' && square[8] != '8' && square[9] != '9')

//         return 0;
//     else
//         return -1;
// }


// /*******************************************************************
//      FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
// ********************************************************************/


// void board()
// {
//     system("cls");
//     cout << "\n\n\tTic Tac Toe\n\n";

//     cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
//     cout << endl;

//     cout << "     |     |     " << endl;
//     cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

//     cout << "_____|_____|_____" << endl;
//     cout << "     |     |     " << endl;

//     cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

//     cout << "_____|_____|_____" << endl;
//     cout << "     |     |     " << endl;

//     cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

//     cout << "     |     |     " << endl << endl;
// }

/*******************************************************************
                END OF PROJECT
********************************************************************/