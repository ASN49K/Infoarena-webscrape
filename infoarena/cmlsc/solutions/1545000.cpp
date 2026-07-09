#include <iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
char n,m,a[1024],b[1024],w[1024][1024],i,j,v[1024],i1,j1,k=0;
int main()
{
    f>>n;for(i=1;i<=n;i++) f>>a[i];
    f>>m;for(i=1;i<=m;i++) f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j]) w[i][j]=1+w[i-1][j-1];
        else w[i][j]=max(w[i-1][j],w[i][j-1]);
    }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++) g<<w[i][j]<<' ';g<<endl;
    }*/
    i1=n;j1=m;
    while(w[i1][j1]>0)
    {
        if(w[i1-1][j1]==w[i1-1][j1-1]&&(w[i1-1][j1]==w[i1][j1]-1 || w[i1-1][j1]==w[i1][j1] ))
        {
            if(a[i1]==b[j1])
               {k++;v[k]=a[i1];}
            i1--;
            j1--;

        }
        else
            if(w[i1-1][j1]>w[i1-1][j1-1])
                i1--;
    }
    g<<k<<'\n';
    for(i=k;i>=1;i--) g<<v[i]<<' ';

}
