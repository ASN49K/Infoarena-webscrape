#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;


int max(int a,int b)
{if(a>b) return a;
else return b;
}
int x[1024],y[1024],c[100][100],m,n,s,sir[1024];

int main()
{
int i,j;
ifstream f("subsir.txt");
f>>m>>n;
for(i=1; i<=m; i++)
f>>x[i];
for(j=1; j<=n; j++)
f>>y[j];
f.close();


for(i=1; i<=m; i++)
for(j=1; j<=n; j++)
if(x[i]==y[j])
c[i][j]=c[i-1][j-1]+1;
else c[i][j]=max(c[i-1][j],c[i][j-1]);

for(i=m; i>0; i--)
for (j=n; j>0; j--)
if(x[i]==y[j])
{sir[++s]=x[i];
--i;
--j;
}
else if(c[i-1][j]<c[i][j-1])
--j;
else --i;
cout<<s<<endl;
for(i=s; i>=0; --i)
cout<<sir[i];

system("pause");
return 0;
}
