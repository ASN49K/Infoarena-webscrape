#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;


int max(int a,int b)
{if(a>b) return a;
else return b;
}
int x[1024],y[1024],c[100][100],m,n;

int main()
{
int i,j;
ifstream f("cmlsc.in");
f>>m>>n;
for(i=1; i<=m; i++)
f>>x[i];
for(i=1; i<=n; i++)
f>>y[i];
f.close();


for(i=1; i<=m; i++)
for(j=1; j<=n; j++)
if(x[i]==y[j])
c[i][j]=c[i-1][j-1]+1;
else c[i][j]=max(c[i-1][j],c[i][j-1]);

ofstream g("cmlsc.out");
g<<c[m][n]<<endl;
for(i=1; i<=m; i++)
for(j=1; j<=n; j++)
if(x[i]==y[j])
g<<x[i]<<" ";
g.close();


system("pause");
return 0;
}
