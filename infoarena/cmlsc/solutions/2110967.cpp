#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long n,m,i,j,k,x[101],y[101],a[101][101],d[101];
void drum()
{i=n;j=m;k=0;
while(a[i][j])
{if(x[i]==y[j]) {k++;
                 d[k]=x[i];
                 i--;
                 j--;
                }
else if(a[i-1][j]>a[i][j-1]) i--;
else j--;

}

}
int main()
{f>>n;

f>>m;
for(i=1;i<=n;i++)
f>>x[i];
for(i=1;i<=m;i++)
f>>y[i];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(x[i]==y[j]) a[i][j]=1+a[i-1][j-1];
               else if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
               else a[i][j]=a[i][j-1];


g<<a[n][m]<<'\n';
drum();
for(i=k;i>=1;i--)
    g<<d[i]<<" ";



    return 0;
}
