#include <iostream>
#include <fstream>

using namespace std;

int a[1024][1024];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m,i,j,w[1024],v[1024],sir[1000],c;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>v[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>w[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            a[i][j]=a[i-1][j-1]+(v[i]==w[j]);


        }
    }
    fout<<a[n][m];
    i=n;
    j=m;
    fout<<'\n';
    c=1;
    while(a[i][j]!=0)
    {
        if(v[i]==w[j])
        {
         sir[c++]=v[i];
            i--;
            j--;
            continue ;
        }
        else
        {
            if(a[i][j]==a[i-1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(i=c-1;i>=1;i--)
    {
        fout<<sir[i]<<" ";
    }
}
