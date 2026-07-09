#include <iostream>
#include <fstream>
using namespace std;

int b[1030],c[1030],a[1030][1030],sc[1030],n,m;

int main()
{
    fstream f("cmlsc.in",ios::in);
    f>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)f>>b[i];
    for(i=1;i<=m;i++)f>>c[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(b[i]==c[j])a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    f.close();f.open("cmlsc.out",ios::out);
    f<<a[n][m]<<"\n";
    int k=a[n][m],nk=k;
    i=n;j=m;
    while(i&&j)
    {
        if(b[i]==c[j])
           {sc[k--]=b[i];i--;j--;}
        else
            if(a[i-1][j]>a[i][j-1])i--;
            else j--;
    }
    for(i=1;i<=nk;i++)
        f<<sc[i]<<" ";
    return 0;
}
