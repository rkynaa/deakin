#include "splashkit.h"

int main()
{
    int a, b, c, d, e;

    a = 10;
    b = 20;
    c = 30;
    d = a;
    e = 50;

    b = a;
    a = a * b;
    c = b - c;
    d = a;
    e = e - (e - 1);

    return 0;
}
