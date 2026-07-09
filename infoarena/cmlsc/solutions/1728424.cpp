#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int main(){

int a[500],b[500],c[500][500],n,m,i,j,d[500],k=0;
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
        k++;
        d[k]=a[i];
        i--; j--;
    }
    else{
       if(c[i-1][j]>c[i][j-1]) i--;
       else j--;
    }

    for(i=k;i>=1;i--)
        g<<d[i]<<" ";


return 0;
}
