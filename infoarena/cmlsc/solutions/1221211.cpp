#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1000],b[1000],m,n;
void cmlsc(int a[1000],int b[1000],int m,int n)
{
    int i,j;
    for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
    if(a[i]==b[j])
     fout<<a[i]<<" ";
}
int main()
{
    fin>>m>>n;
    int i;
    for(i=1;i<=m;i++)
     fin>>a[i];
    for(i=1;i<=n;i++)
     fin>>b[i];
    cmlsc(a,b,m,n);
    return 0;
}
