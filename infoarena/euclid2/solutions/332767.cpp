#include <fstream.h>
#include <iostream.h>
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a[100000],b[100000],r,i,t;
f>>t;
for (i=0;i<t;i++)
    f>>a[i]>>b[i];
f.close();
for (i=0;i<t;i++)
    {
    r=0;
    while (b[i])
          {
          r=a[i]%b[i];
          a[i]=b[i];
          b[i]=r;
          }
    }
for (i=0;i<t;i++)
    g<<a[i]<<endl;
g.close();
return 0;
}
