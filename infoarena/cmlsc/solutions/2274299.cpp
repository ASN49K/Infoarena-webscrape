#include <iostream>
#include <fstream>
using namespace std;
// 2 linii sau vreo 6 numere
int main()
{short int a[125], b[125], lcs[125], u[125][125]={0}, i, j, m, n;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>m>>n;
for (i=1;i<=m;i++)
    f>>a[i];
for (i=1;i<=n;i++)
    f>>b[i];
for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
        if (a[i]==b[j])
            {u[i][j]=u[i-1][j-1]+1;
             lcs[u[i][j]]=a[i];}
        else if (u[i][j-1]<u[i-1][j])
                u[i][j]=u[i-1][j];
             else u[i][j]=u[i][j-1];

for (i=1;i<=m;i++)
    {for (j=1;j<=n;j++)
        g<<u[i][j];
     g<<endl;}

g<<u[m][n]<<endl;
for (i=1;i<=u[m][n];i++)
        g<<lcs[i]<<" ";
f.close();
g.close();
    return 0;
}
