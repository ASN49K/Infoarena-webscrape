#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

#define maxim(a,b) ((a > b) ? a : b)
#define MAX 1024
int main()
{
    int m,n,a[MAX],b[MAX],c[MAX],i,j,d[MAX][MAX],k;

    f>>m>>n;
    for(int i = 1;i <= m;i++)
    {
        f>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        f>>b[i];
    }

    for(i = 1;i <= m;i++)
        for(j = 1;j <= n;j++)
        {
            d[i][j] = 0;
        }

    for(i = 1;i <= m;i++)
        for(j = 1;j <= n;j++)
        {
            if(a[i] == b[j])
            {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else
            {
                d[i][j] = maxim(d[i][j-1],d[i-1][j]);
            }
        }
        i = m;
        j = n;
        k = 0;
        while(d[i][j] !=0)
        {
            if(d[i][j] == (d[i-1][j-1] + 1))
            {
                c[++k] = a[i];
                i--;
                j--;
            }
            else
            {
                if(d[i-1][j]>d[i][j-1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }

        g<<d[m][n]<<"\n";
        for(i = k;i >= 1;i--)
        {
            g<<c[i]<<" ";
        }
        f.close();
        g.close();
    return 0;
}
