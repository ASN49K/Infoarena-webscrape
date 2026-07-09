#include<iostream>
#include<fstream>

using namespace std;

int main()
{
ifstream f ("cmlsc.in");
ofstream o ("cmlsc.out");
int n,m;
int a[1025],b[1025],c[1025];

f>>n>>m;
int i,j,k,l,u=0;
l=0;

if(n<m)
{
n=n+m;
m=n-m;
n=n-m;

for(i=1;i<=m;i++)
                f>>a[i];
for(i=1;i<=n;i++)
              { f>>b[i];

                    if(b[i]==a[1])
                           {c[++u]=a[1];k=i; l++; a[1]=-1999;}
              }

for(j=k;j<=n;j++)
    {
        for(i=2;i<=m;i++)
                   if(b[j]==a[i])
                             {  l++;c[++u]=a[i];}
    }

}
else
  {

for(i=1;i<=n;i++)
                f>>a[i];
for(i=1;i<=m;i++)
              { f>>b[i];

                    if(b[i]==a[1])
                           {c[++u]=a[1];k=i; l++; a[1]=-1999;}
              }

for(j=k;j<=m;j++)
    {
        for(i=2;i<=n;i++)
                   if(b[j]==a[i])
                             {  l++;c[++u]=a[i];}
    }
  }
o<<u<<"\n";
for(i=1;i<=u;i++)
            o<<c[i]<<" ";



return 0;}
