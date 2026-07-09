#include <iostream>
#include <string>
#include<stdlib.h>
#include<fstream>
using namespace std;

int max(int a,int b)
{
    if(a>b)
        return a;
    else return b;
}
 ofstream g("cmlsc.out");
void afisare(int v1[],int i,int j,int a[][1100])
{
if(i>0&&j>0&&a[i][j]!=0)
	if(a[i][j-1]==a[i-1][j]&&a[i-1][j]==a[i-1][j-1]&&a[i][j-1]!=a[i][j])
         {afisare(v1,--i,--j,a);g<<v1[j+1]<<' ';}
        else if(a[i][j-1]==a[i][j])
		 afisare(v1,i,--j,a);
	else if(a[i-1][j]==a[i][j])
		 afisare(v1,--i,j,a);
	else afisare(v1,--i,--j,a);
}
int a[1100][1100];
int main()
{
    ifstream f("cmlsc.in");
    int n,m,v1[1100],v2[1100],nr=0,k=0,v[1100];
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>v1[i];
    for(int j=1;j<=m;j++)
        f>>v2[j];
   for(int i=1;i<=m;i++)
       for(int j=1;j<=n;j++)
           {if(v2[i]==v1[j])
               a[i][j]=1+max(a[i-1][j],a[i][j-1]);
           else a[i][j]=max(a[i-1][j],a[i][j-1]);
                }
  g<<a[m][n]<<endl;
 afisare(v1,m,n,a);
f.close();
g.close();
return 0;
}

