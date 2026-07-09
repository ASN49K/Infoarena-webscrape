
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("sclm.in");
ofstream fout("sclm.out");
int n,i,j,l[1001],a[1001],pmax=1,p[1001];
int main()
{
fin>>n;
for(i=1;i<=n;i++)fin>>a[i];
l[n]=1;
for(i=n-1;i>=1;i--)
{l[i]=1;
p[i]=-1;
    for(j=i+1;j<=n;j++)
    if(l[j]+1>l[i]&&a[i]<=a[j]){l[i]=l[j]+1;p[i]=j;}
}
for(i=1;i<=n;i++)
        if(l[pmax]<l[i])
            pmax=i;
fout<<l[pmax]<<'\n';
i=pmax;
while(i!=-1)
{
    fout<<i<<" ";
    i=p[i];
}

    return 0;
}
