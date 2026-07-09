#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1050],b[1050],d[1050],n,m,c[1050][1050],k;
void citire()
{int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
}
void comun()
{int i,j;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])
        c[i][j]=1+c[i-1][j-1];
    else c[i][j]=max(c[i-1][j],c[i][j-1]);
}
void sir()
{int i,j;
    k=0;
    i=n;j=m;
    while(c[i][j]!=0)
        if(a[i]==b[j]){
            k++;
            d[k]=a[i];
            i--;j--;
        }else if(c[i][j]==c[i-1][j])i--;
        else j--;

    fout<<k<<endl;
    for(i=k;i>=1;i--)
       fout<<d[i]<<' ';
}
int main()
{
   citire();
   comun();
   sir();
}
