
#include<iostream>
#include<fstream>
using namespace std;
int max(int a,int b)
{if(a>b)
return a;
else
return b;

}
int main()
{ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,A[100],B[100],c[100][100],sir[100],i,j;
f>>n>>m;
for(i=1;i<=n;i++)
f>>A[i];
for(i=1;i<=m;i++)
f>>B[i];

for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(A[i]==B[j])
c[i][j]=c[i-1][j-1]+1;
else
c[i][j]=max(c[i-1][j],c[i][j-1]);
 g<<c[n][m]<<endl;
int nr=0;
while((n>0)&&(m>0))
{if(A[n]==B[m])
{sir[nr]=A[n];
    nr++;
    n--;
    m--;
}
else
{if(c[n-1][m]>c[n][m-1])
n--;
else
m--;
}}
for(j=nr-1;j>=0;j--)
g<<sir[j]<<" ";
g.close();
f.close();

}
