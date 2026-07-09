#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long T,a,b,x[1000000],y[1000000],k,p,i,j,mx=0,n[1000000],m[1000000],o;
int main()
{
f>>T;
for(i=1;i<=T;i++)
{
    f>>a>>b;
    x[i]=a;
    y[i]=b;
}

for(i=1;i<=T;i++)
{

for(j=1;j<=x[i];j++)
   if(x[i]%j==0)
{
    k++;
    n[k]=j;
}

for(j=1;j<=y[i];j++)
   if(y[i]%j==0)
{
    p++;
    m[p]=j;
}

 for(j=1;j<=k;j++)
    for(o=1;o<=p;o++)
      if(n[j]==m[o]&&n[j]>mx)
        mx=n[j];

g<<mx<<" ";
g<"\n";
mx=0;
k=0;
p=0;
}

    return 0;
}
