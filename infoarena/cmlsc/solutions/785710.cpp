#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int x[1025], y[1025], d[1025];
int lcs[1025][1025];
int main ()
{
    int n, m;
    f>>n>>m;
    for (int i=1; i<=n; i++)
        f>>x[i];
    for (int i=1; i<=m; i++)
        f>>y[i];
    for (int k=1; k<=n; k++)
        for (int h=1; h<=m; h++)
            if (x[k]==y[h])
            {
               lcs[k][h]=1+lcs[k-1][h-1];
            }
            else
                if (lcs[k-1][h]>lcs[k][h-1])
                    lcs[k][h]=lcs[k-1][h];
                else
                    lcs[k][h]=lcs[k][h-1];
    int k=n, h=m;
    int i;

    for (i=0; lcs[k][h]; )
        if (x[k]==y[h])
        {
            d[i++]=x[k];
            k--;
            h--;
        }
        else
            if (lcs[k][h]==lcs[k-1][h])
                k--;
            else
                h--;
    g<<i<<endl;
    for (k=i-1; k>=0; k--)
        g<<d[k]<<' ';
    g<<endl;
    return 0;
}
