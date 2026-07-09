#include <cstdio>

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

int T, a, b;

    int ggt (int a, int b)
    {
        if (!a || !b) return a + b;
        
        if (!(a & 1) && !(b & 1)) return 2 * ggt (a >> 1, b >> 1);
        if (!(a & 1) && (b & 1)) return ggt (a >> 1, b);
        if ((a & 1) && !(b & 1)) return ggt (a, b >> 1);
        if ((a & 1) && (b & 1))
           if (a > b) return ggt (a - b, b);
                 else return ggt (a, b - a); 
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
              
