#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int i,j,m[1024][1024],a[1024],b[1024],c[1024],na,nb,k=0;

int main()
{
    f>>na>>nb;
    for(i=1;i<=na;i++)
        f>>a[i];
    for(i=1;i<=nb;i++)
        f>>b[i];
    for(i=1;i<=na;i++)
        for(j=1;j<=nb;j++)
            if(a[i]==b[j])m[i][j]=m[i-1][j-1]+1;
            else m[i][j]=(m[i-1][j]>m[i][j-1]) ? m[i-1][j]:m[i][j-1];
    for(i=na,j=nb;i;)
        if(a[i]==b[j])
        {
            k++;c[k]=a[i];i--;j--;
        }
        else (m[i-1][j]<m[i][j-1])? --j:--i;
    g<<k<<'\n';
    for(i=k;i>0;--i)g<<c[i]<<" ";
    return 0;
}
