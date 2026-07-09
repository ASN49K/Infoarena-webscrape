#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025], b[1025], c[1025][1025], v[1025];
int m, n, i, j,k;
int main()
{
    fin>>m>>n;
    for(j=1;j<=m;j++)
    {
        fin>>a[j];
    }
    for(i=1;i<=n;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            c[i][j]=max(c[i-1][j], c[i][j-1]);
            if(a[j]==b[i])
            {
                c[i][j]++;
            }
        }
    }
    j=m; i=n;
    k=1;
    while(j!=0&&i!=0)
    {
        if(a[j]==b[i])
        {
            v[k]=b[i];
            i--;
            j--;
            k++;
        }
        else if (c[i-1][j]>c[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    k--;
    fout<<k<<'\n';
    for(i=k;i>=1;i--)
    {
        fout<<v[i]<<' ';
    }
    fin.close();
    fout.close();
}
