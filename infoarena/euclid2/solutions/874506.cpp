#include <iostream>
#include <cstdio>

using namespace std;

int solve (int a , int b)
{
    int r;

    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    if (a)
        return a;

    return 1;
}

int main()
{
    freopen ("euclid2.in" , "r" , stdin);
    freopen ("euclid2.out" , "w" , stdout);

    int T , A , B;

    scanf ("%d" , &T);

    while (T --)
    {
        scanf ("%d %d" , &A , &B);

        int sol = solve (A , B);

        printf ("%d\n" , sol);
    }

    return 0;
}
