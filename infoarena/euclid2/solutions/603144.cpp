#include <iostream>

using namespace std;

int CMMDC (int a, int b)
{
    int r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    int T;
    scanf ("%d", &T);
    for (; T>0; --T)
    {
        int A, B;
        scanf ("%d %d", &A, &B);
        printf ("%d\n", CMMDC (A, B));
    }
    return 0;
}
