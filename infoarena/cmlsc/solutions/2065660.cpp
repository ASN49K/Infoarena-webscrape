#include <iostream>
#include <fstream>

using namespace std;

int a[1024][1024];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n,m,i,j,w[1024],v[1024],sir[100],c;
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
            if(v[i]==w[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                if(a[i-1][j]>a[i][j-1])
                {
                    a[i][j]=a[i-1][j];
                }
                else
                {
                    a[i][j]=a[i][j-1];
                }
            }
        }
    }
    fout<<a[n][m];
    i=n;
    j=m;
    fout<<'\n';
    c=1;
    while(a[i][j]!=0)
    {
        if(a[i][j]==a[i-1][j-1]+1)
        {
         sir[c++]=v[i];
            i--;
            j--;
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
