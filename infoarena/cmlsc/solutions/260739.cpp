#include<iostream>
#include<fstream>
using namespace std;
int a[1024], b[1024],c[1024][1024];

int max(int a, int b)

{if (a>b)
return a;
else return b;
}

int main()

{int m, n, i, j;
ifstream f("cmlsc.in");
f>>m>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(i=1;i<=n;i++)
f>>b[i];
f.close();
    
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
c[i][j]=c[i-1][j-1]+1;
else c[i][j]=max(c[i][j-1],c[i-1][j]);
        

ofstream g("cmlsc.out");
g<<c[m][n]<<endl;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
g<<a[i]<<" ";
      
g.close();
return 0;
     }   
