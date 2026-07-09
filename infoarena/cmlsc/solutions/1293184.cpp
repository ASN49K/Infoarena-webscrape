#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int main()
{
    int n,m,i,j,k=1;
    int a[100],b[100],c[100];
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a[i];
    }
    for(j=1;j<=m;j++)
    {
        f>>b[j];
    }
    if(n<m)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i]==b[j])
                {
                    c[k]=a[i];
                    k++;
                }

            }
        }
    }
    else
    {
        for(j=1;j<=m;j++)
        {
            for(i=1;i<=n;i++)
            {
                if(b[j]==a[i])
                {
                    c[k]=b[j];
                    k++;
                }
            }
        }
    }
    g<<k-1<<endl;
    for(int d=1;d<k;d++)
    {
        g<<c[d]<<" ";
    }
}
