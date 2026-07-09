#include<fstream>
#include<iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,v[2000],a[2000],l,k[2000],p;

void citire(){
    f>>n>>m;
for(i=1;i<=n;i++)
   f>>v[i];
for(i=1;i<=m;i++)
    f>>a[i];

}


int main(){int poz;
citire();
for(i=1,j=1;i<=n&&j<=m;)
   {if(v[i]==a[j]){k[++p]=v[i];i++;j++;poz=i;}
else i++;
if(i==n&&j<m)i=poz,j++;
}
/*
for(i=1;i<=n;i++)
cout<<v[i]<<" ";
cout<<endl;
for(i=1;i<=m;i++)
cout<<a[i]<<" ";
*/

g<<p<<"\n";
for(i=1;i<=p;i++)
g<<k[i]<<" ";

f.close();
g.close();
return 0;}
