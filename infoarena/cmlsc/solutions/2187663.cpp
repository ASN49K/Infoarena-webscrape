#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1200],b[1200],d[1200][1200],sir[1200],k,i,j;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(d[i][j]==d[i-1][j])
        {
            i--;
        }
        else
        {
            if(d[i][j]==d[i][j-1])
            {
                j--;
            }
            else
            {
                k++;
                sir[k]=a[i];
                i--;
                j--;
            }
        }
    }
    fout<<k<<"\n";
    for(i=k;i>=1;i--)
    {
        fout<<sir[i]<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
