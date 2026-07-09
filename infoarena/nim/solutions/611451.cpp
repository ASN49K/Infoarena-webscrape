#include <iostream>

using namespace std;

int main()
{
    freopen ("nim.in", "r", stdin);
    freopen ("nim.out", "w", stdout);
    int T;
    scanf ("%d", &T);
    for (; T>0; --T)
    {
        int N, Xor=0;
        scanf ("%d", &N);
        for (int i=1; i<=N; ++i)
        {
            int X;
            scanf ("%d", &X);
            Xor^=X;
        }
        if (Xor!=0)
        {
            printf ("DA\n");
        }
        else
        {
            printf ("NU\n");
        }
    }
    return 0;
}
