#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],sol1[1025],fra[257],frb[257],n,m,ma,soll[1025],c[1025],sol[1025];
int main()
{
    int i,j;
f>>n>>m;
for (i=1;i<=n;i++)
{
f>>a[i];
}

for (i=1;i<=m;i++)
{
    f>>b[i];
    c[i]=b[i];
    frb[b[i]]++;
}

for (i=1;i<=n;i++)
{
    if (frb[a[i]]!=0)
    {
        ma=0;
        for (j=1;j<=m;j++)
        {
            if (b[j]==a[i]) {soll[j]=ma+1;sol1[i]=ma+1;}
            ma=max(ma,sol[j]);
        }
        for (j=1;j<=m;j++)
        {
            if (sol[j]<soll[j]) sol[j]=soll[j];
        }
    }
}
ma=0;
for (i=1;i<=n;i++)
    {
        ma=max(ma,sol1[i]);
    }
  //  cout<<frb[1];
    g<<ma<<"\n";
    j=m;
for (i=n;i>=1;i--)
{
    if (sol1[i]==ma) {
    j=m;
    while (b[j]!=a[i] && sol[j]!=ma && j>0)
    {
        j--;
    }
    if (j!=0) {g<<a[i]<<" ";m=j;ma--;}

    }
    if (ma==0) break;
}
    return 0;
}
