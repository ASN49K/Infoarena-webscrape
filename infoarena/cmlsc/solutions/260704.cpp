#include <fstream>
#include<iostream>
#include<stdio.h>
using namespace std;

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}


int m,n,x[100],y[100],c[100][100];

int main()
{int i,j,m,n,c[1000][1000];
ifstream f("subsir.in");


f>>m>>n;
for(i=1;i<=m;i++)
f>>x[1];
for(j=1;j<=n;j++)
f>>y[1];
f.close();


for(i=1;i<=m;i++)
    for(j=1;j<n;j++)
    if(x[i]==y[j])
    c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);
cout<<c[m-1][n-1];
system("pause");
return 0;
}    
    
