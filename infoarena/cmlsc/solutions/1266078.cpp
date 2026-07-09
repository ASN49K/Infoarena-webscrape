#include <fstream>

using namespace std;

#define fileIn "cmlsc.in"
#define fileOut "cmlsc.out"

#define maxN 1026
#define maxM 1026

short a[maxM], b[maxN];

int pd[maxM][maxN];

int sol[maxM];

int main()
{
    ifstream sIn( fileIn );
    ofstream sOut( fileOut );

    int i, m, n, y;

    sIn >> m >> n;

    for ( i = 1; i <= m; ++i )
    {
        sIn >> a[i];
    }

    for ( i = 1; i <= n; ++i )
    {
        sIn >> b[i];
    }

    for ( i = 1; i <= m; ++i )
    {
        for ( y = 1; y <= n; ++y )
        {
            if ( a[i] == b[y] )
            {
                pd[i][y] = pd[i-1][y-1] + 1;
            }
            else
            {
                if ( pd[i][y-1] > pd[i-1][y] )
                    pd[i][y] = pd[i][y-1];
                else
                    pd[i][y] = pd[i-1][y];
            }
        }
    }

    int c = 0;
    for ( i = m, y = n; i; )
    {
        if ( a[i] == b[y] )
        {
            sol[++c] = a[i];
            --i;
            --y;
        }
        else
        {
            if ( pd[i-1][y] < pd[i][y-1])
                --y;
            else
                --i;
        }
    }

    sOut << c << '\n';

    for ( i = c; i; --i )
    {
        sOut << sol[i] << ' ';
    }

    sOut << '\n';


    return 0;
}
