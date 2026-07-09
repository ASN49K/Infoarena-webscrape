//#include <iostream>
#include <fstream>

using namespace std;

int n, m;
int A[100], B[100];

void DP ()
{
    int c[100][100];
    for (int i=1; i<=n; i++)
        c[i][0]=0;
    for (int i=1; i<=m; i++)
        c[0][i]=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (A[i]==B[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                if (c[i][j-1]>=c[i-1][j])
            {
                c[i][j]=c[i][j-1];
            }
                else
                {
                    c[i][j]=c[i-1][j];
                }
        }
    int sol[n];
    int y=0;
    for (int i=n, j=m; i; ) //afisarea celui mai lung subsir comun
    {
        if (c[i-1][j]>c[i-1][j-1])
            i--;
        else
            if (c[i][j-1]>c[i-1][j-1])
                j--;
            else
            {
                sol[++y]=A[i];
                i--;
                j--;
            }
    }
    y--;
    ofstream g("cmlsc.out");
    g<<y<<"\n";
    for ( ; y; y--)
        g<<sol[y]<<" ";
    g<<"\n";
    g.close();
}

int main()
{
    ifstream f("cmlsc.in");
    f>>n>>m;
    for (int i=1; i<=n; i++)
        f>>A[i];
    for (int i=1; i<=m; i++)
        f>>B[i];
    f.close();
    DP();
    return 0;
}
