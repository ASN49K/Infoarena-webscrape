#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int i, j, n, s, a[2001], b[2001], v[2001][2001], m, o[2001][2001], sol[2001], k;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i] == b[j])
            {
                v[i][j]=v[i-1][j-1]+1;
                o[i][j]=1;
            }
            else
            {
                if(v[i][j-1] > v[i-1][j])
                {
                    v[i][j]=v[i][j-1] ;
                    o[i][j]=2;
                }
                else
                {
                    v[i][j]=v[i-1][j];
                    o[i][j]=3;
                }
            }
        }
    fout<<v[n][m]<<endl;

    i=n, j=m;
    while(i >= 1 && j >= 1)
    {
        if(o[i][j] == 1)
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        if(o[i][j] == 2)
        {
            j--;
        }
        if(o[i][j] == 3)
        {
            i--;
        }

    }
    for(i=k; i>=1; i--)
        fout<<sol[i]<<" ";
}
