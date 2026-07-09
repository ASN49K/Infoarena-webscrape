#include <iostream>
#include <fstream>
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
long a[100000],b[100000],n,mx,k,l[100000
];
void solve()
{
    int i,j;
    l[n]=1;
    for (i=n-1;i>=1;i--)
    {
        mx=0;
        for (j=i+1;j<=n;j++)
            if (l[j]>mx && a[i]<=a[j])
            mx=l[j];
        l[i]=mx+1;
    }
    mx=0;
    for (i=1;i<=n;i++)
    if (l[i]>mx){
        mx=l[i];
        k=i;
    }
}
void afis ()
{
    int i;
    g<<mx<<'\n';
    for (i=k;i<=n && mx;i++)
        if (l[i]==mx)
        {g<<a[i]<<' ';
    mx--;}
}
int main()
{ int i,j;
f>>n;
for (i=1;i<=n;i++)
f>>a[i];
solve();
afis();
}
