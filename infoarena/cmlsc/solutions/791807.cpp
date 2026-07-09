#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[1050], b[1050], v[1050][1050];

void reconstruct( int, int);
int main()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)
    {
        f>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        f>>b[i];
    }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if( a[i] == b[j] )
            {
                v[i][j] = v[i-1][j-1] + 1;
            }
            else
            {
                v[i][j] = v[i-1][j-1];
                int aux = v[i-1][j] > v[i][j-1] ? v[i-1][j] : v[i][j-1];
                v[i][j] = v[i][j] > aux ? v[i][j] : aux;
            }
    g << v[m][n]<< '\n';
    reconstruct(m, n);
    return 0;
}

void reconstruct(int i, int j)
{
    if(v[i][j] > 0)
    {
        if(a[i] == b[j])
        {
            reconstruct(i-1, j-1);
            g << a[i] <<' ';
        }
        else
        {
            int iaux, jaux;
            if( v[i][j-1] > v[i-1][j] )
            {
                iaux = i; jaux = j - 1;
            }
            else
            {
                iaux = i -1; jaux = j;
            }
            if( v[i-1][j-1] > v[iaux][jaux] )
            {
                iaux = i - 1; jaux = j - 1;
            }
            reconstruct(iaux, jaux);
        }
    }
}
