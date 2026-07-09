#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],sol[1025],fra[257],frb[257],n,m,ma,sol2[1025];
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
    frb[b[i]]++;
}

for (i=1;i<=n;i++)
{
    fra[a[i]]++;
    if (frb[a[i]]!=0)
    {
        ma=0;
    for (j=1;j<=m;j++)
    {
        if (a[i]==b[j]) sol[j]=max(sol[j],ma+1);
        ma=max(ma,sol[j]);
    }

    }
}
ma=0;
for (i=1;i<=m;i++)
{
   if (sol[i]>ma) ma=sol[i];
}
g<<ma<<"\n";
int k=0;
for (i=1;i<=m;i++)
{
    if (sol[i]==k+1) {k++;g<<b[i]<<" ";}
}

    return 0;
}
