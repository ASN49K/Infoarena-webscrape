#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    freopen("grader_test10.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int a, b, t;
    scanf("%d", &t);
    for (; t; --t)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", euclid(a, b));
    }
    return 0;
}
