#include <cstdio>

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int T, a, b;

    int ggt (int a, int b)
    {
        if (!b) return a;
           else return ggt (b, a % b);
    }

    int main ()
    {
        freopen (FIN, "r", stdin);
        freopen (FOUT, "w", stdout);
        
        scanf ("%d", &T);
        while (T--)
        {
              scanf ("%d %d", &a, &b);
              printf ("%d\n", ggt (a, b));
        }
        
        return 0;
    }
