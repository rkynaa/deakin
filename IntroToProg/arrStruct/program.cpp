#include "splashkit.h"

#include "terminal_user_input.h"
#include <string>
#include <vector>

using std::vector;
using namespace std;

struct knight_data {
    string name;
    int age;
    vector<string> items;
};

struct kingdom_data {
    string name;
    vector<knight_data> knights;
};

knight_data read_knight()
{
    knight_data result;

    result.name = read_string("Enter Name: ");
    result.age = read_integer("Enter Age: ");
    result.items.push_back(read_string("Enter Items: "));

    return result;
}

void write_knight(const kingdom_data &kingdom)
{
    for(int i = 0; i < kingdom.knights.size(); i++){
        write_line(to_string(i + 1) + " " + kingdom.knights[i].name + " Aged " + to_string(kingdom.knights[i].age) + " Carrying " + to_string(kingdom.knights[i].items.size()) + " Items ");
    }
}

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    ADD_ITEMS,
    DELETE_ITEMS,
    FINISH_UPDATE
};

enum main_menu_option
{
    ADD_KNIGHT,
    DELETE_KNIGHT,
    UPDATE_KNIGHT,
    DISPLAY_KINGDOM_DETAIL,
    QUERY_KNIGHT,
    EXIT,
};

main_menu_option read_main_menu_option()
{
    int result;
    write_line("1: Add Knight");
    write_line("2: Delete Knight");
    write_line("3: Update Knight");
    write_line("4: Display Kingdom Detail");
    write_line("5: Query Knight");
    write_line("6: Exit");
    result = read_integer("Select Option: ");
    return static_cast<main_menu_option>(result - 1);
}

knight_update_option read_knight_update_option()
{
    int result;
    write_line("1: Update Name");
    write_line("2: Update Age");
    write_line("3: Add Items");
    write_line("4: Delete Items");
    write_line("5: Finish Update");
    result = read_integer("Select Option: ");
    return static_cast<knight_update_option>(result - 1);
}

void delete_items(kingdom_data &kingdom, int index, int i)
{
    if(i >= 0 && i < kingdom.knights[index].items.size()) {
        int last_idx;
        last_idx = kingdom.knights[index].items.size() - 1;
        kingdom.knights[index].items[i] = kingdom.knights[index].items[last_idx];
        kingdom.knights[index].items.pop_back();
    }
}

void update_knight(kingdom_data &curr)
{
    knight_update_option option;
    int index;
    int i;
    write_line();
    write_line("----Update Knight----");
    index = read_integer("Which Knight: ") - 1;
    do {
        option = read_knight_update_option();
        switch(option)
        {
            case UPDATE_NAME:
                curr.knights[index].name = read_string("Enter new Name: ");
                break;
            case UPDATE_AGE:
                curr.knights[index].age = read_integer("Enter new Age: ");
                break;
            case ADD_ITEMS:
                curr.knights[index].items.push_back(read_string("Enter new Items: "));
                break;
            case DELETE_ITEMS:
                i = read_integer("Which Item: ");
                delete_items(curr, index, i - 1);
                break;
            case FINISH_UPDATE:
                break;
            default:
                write_line("Please select a valid Option!");
        }
    } while (option != FINISH_UPDATE);
}

void add_knight(kingdom_data &curr)
{
    knight_data new_knight;
    new_knight = read_knight();
    curr.knights.push_back(new_knight);
}

void write_kingdom(const kingdom_data &curr)
{
    write_line("================");
    write_line(curr.name);
    write_line("==== Knight ====");

    for(int i = 0; i != curr.knights.size(); i++) {
        write_knight(curr);
    }
    
    write_line("================");
}

void delete_knight(kingdom_data &curr, int index)
{
    if(index >= 0 && index < curr.knights.size()) {
        int last_idx;
        last_idx = curr.knights.size() - 1;
        curr.knights[index] = curr.knights[last_idx];
        curr.knights.pop_back();
    }
}



kingdom_data read_kingdom()
{
    kingdom_data result;
    result.name = read_string("Enter Kingdom Name: ");
    return result;
}

int select_knight(const kingdom_data &curr)
{
    int option;
    for(int i = 0; i < curr.knights.size(); i++) {
        write(curr.knights[i].name);
        write(" ");
        write_line(i + 1);
    }
    write_line();
    option = read_integer("Select your Knight: ");
    while(option > curr.knights.size() && option > -1) {
        write_line("Please insert a valid answer!");
        option = read_integer("Select your Knight: ");
    }
    return option - 1;
}

void query_knight(const kingdom_data &curr)
{
    int input;
    input = read_integer("Which Knight: ") - 1;
    write("Knight Name: ");
    write_line(curr.knights[input].name);
    write("Knight Age: ");
    write_line(curr.knights[input].age);
    write("Knight Items: ");
    for(int i = 0; i < curr.knights[input].items.size(); i++) {
        write(i + 1);
        write(" ");
        write(curr.knights[input].items[i]);
        write(", ");
    }
}

void main_menu(kingdom_data &curr)
{
    main_menu_option option;
    int index;
    do {
        write("---- ");
        write(curr.name);
        write_line(" ----");
        write_line();

        option = read_main_menu_option();
        write_line();

        switch(option)
        {
            case ADD_KNIGHT:
                add_knight(curr);
                write_line();
                break;
            case DELETE_KNIGHT:
                index = read_integer("Which Knight: ");
                delete_knight(curr, index - 1);
                write_line();
                break;
            case UPDATE_KNIGHT:
                update_knight(curr);
                write_line();
                break;
            case DISPLAY_KINGDOM_DETAIL:
                write_kingdom(curr);
                write_line();
                break;
            case QUERY_KNIGHT:
                query_knight(curr);
                write_line();
                break;
            case EXIT:
                break;
            default:
                write_line("Please select a valid Option!");
        }
    } while (option != EXIT);
}

int main()
{   
    kingdom_data new_kingdom = read_kingdom();
    main_menu(new_kingdom);
    return 0;
}