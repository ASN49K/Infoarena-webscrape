#include<fstream>
#include<iostream>
using namespace std;

int max(int a, int b)
{ if(a>b) return a;
else return b;

}
int m,n,i,k,j,a[1024],b[1024],c[1024][1024];

 ofstream g("cmlsc.out");
       
  
int main()
{



ifstream f("cmlsc.in");
f>>m>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(j=1;j<=n;j++)
f>>b[j];
f.close();

 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 if(a[i]==b[j])
 c[i][j]=c[i-1][j-1]+1;
 else c[i][j]=max(c[i-1][j], c[i][j-1]);
 


   g<<c[m][n]<<endl;

       
   
g.close();

return 0;

}
