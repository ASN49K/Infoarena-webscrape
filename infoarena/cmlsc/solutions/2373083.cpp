#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,mat[1025][1025];
int a[1025],b[1025],leng;
int v[1024];
int k=0;

void solve()
{
    int i,j;
    i=n;
    j=m;
while (k<leng)
{
    if (a[i]==b[j])
    {
        k++;
        v[k]=a[i];
        i--;
        j--;
    }
    else
    {
        if (mat[i-1][j]>mat[i][j-1]) i--;
        else j--;
    }
}
}


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
}
for (i=1;i<=n;i++)
{
    for (j=1;j<=m;j++)
    {
        if (a[i]==b[j])
        {
            mat[i][j]=mat[i-1][j-1]+1;
        }
        else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    }
}
for (i=1;i<=n;i++)
{
    for (j=1;j<=m;j++)
    {
        leng=max(leng,mat[i][j]);
    }
}

solve();
g<<leng<<"\n";
for (i=k;i>=1;i--) g<<v[i]<<" ";



    return 0;
}
