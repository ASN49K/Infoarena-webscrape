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
    j=m; i=n; int max=-1;
    k=1;
    while(j!=0&&i!=0)
    {
        if(c[i][j]==c[i-1][j-1]+1)
        {
            if(max==c[i][j])
            {
                i--;
            }
            else
            {
            v[k]=b[i];
            i--;
            k++;
            max=c[i][j];
            }
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
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            fout<<c[i][j]<<' ';
        }
        fout<<'\n';
    }
    fout<<k<<'\n';
    for(i=k;i>=1;i--)
    {
        fout<<v[i]<<' ';
    }
    fin.close();
    fout.close();
}
