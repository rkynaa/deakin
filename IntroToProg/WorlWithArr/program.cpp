#include "splashkit.h"
#include "tasks.h"

int main()
{
    string names[5] = {"Mario", "Jonathan", "Jason", "Rakyan", "Nicky"};
    int size = 5;

    int index_val = index_of("Nicky",names,size);
    write_line("The index of Nicky is " + std::to_string(index_val));

    print_summary(names,size);

    return 0;
}