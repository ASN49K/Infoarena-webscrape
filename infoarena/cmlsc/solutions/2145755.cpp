#include <iostream>
#include <fstream>

using namespace std;

int n, m, a[1050], b[1050],x[1050][1050],t,sir[1050];


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void aranjare()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i]==b[j])
            {
               x[i][j]=x[i-1][j-1]+1;
            }
            else{
                if (x[i-1][j]<x[i][j-1])
                {
                    x[i][j]=x[i][j-1];
                }
                else
                    x[i][j]=x[i-1][j];
            }
        }
    }
}

void creeare()
{
    for (int i=n, j=m; j>0;)
    {
        if (a[i]==b[j])
        {
            sir[t++]=a[i];
            i--;
            j--;
        }
        else if (x[i-1][j]<x[i][j-1])
            j--;
        else
            i--;
    }
}

int main()
{
    f >> n >> m;
    for (int i=1; i<=n; i++)
        f >> a[i];
    for (int j=1; j<=m; j++)
        f >> b[j];
    aranjare();
    creeare();
    g << x[n][m] << endl;
    for (int i=t-1; i>=0; i--)
    {
        g << sir[i] <<' ';
    }
    return 0;
}
