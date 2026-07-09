#include <fstream>
#include <fstream>
#define NMAX 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[NMAX],b[NMAX],i,c[NMAX][NMAX],j;
void afis(int i,int j)
{
    if(i>=1 && j>=1)
    if(a[i]!=b[j])
        {if(c[i][j-1]>c[i-1][j]) afis(i,j-1);
        else afis(i-1,j);}
    else
    {
        afis(i-1,j-1);
        g<<a[i]<<" ";
    }
}
int main()
{f>>n>>m;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=m;i++) f>>b[i];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i-1][j],c[i][j-1]);
g<<c[n][m]<<endl;
afis(n,m);
f.close();
g.close();
    return 0;
}
