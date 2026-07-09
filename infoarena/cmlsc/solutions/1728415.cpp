#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int main(){

int a[100],b[100],c[100][100],n,m,i,j;
f>>n>>m;

for(i=1;i<=n;i++)
    f>>a[i];

for(i=1;i<=m;i++)
    f>>b[i];


for(i=1;i<=m;i++)
  c[0][i]=0;
for(i=1;i<=n;i++)
  c[i][0]=0;

  ///fac tablou
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(a[i]==b[j])
        c[i][j]=c[i-1][j-1]+1;
      else
        c[i][j]=max(c[i-1][j],c[i][j-1]);


int lungime=c[n][m];

/// frec tablou

g<<lungime<<'\n';

i=n; j=m;

while(i>0 && j>0)
    if(a[i]==b[j]){
        g<<a[i]<<" ";
        i--; j--;
    }
    else{
       if(c[i-1][j]>c[i][j-1]) i--;
       else j--;
    }



return 0;
}
