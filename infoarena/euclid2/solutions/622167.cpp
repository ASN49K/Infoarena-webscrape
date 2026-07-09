#include<iostream>
#include<fstream>
using manespace std;
int main (void)
{
long  T, a, b, i;
ifstream f("euclid2.in");
f>>T;
ofstream g("euclid2.out");
for(i=1;i<=T;i++)
 {
 f>>a>>b;
 while( a!=b)
   if(a>b)
     a=a-b;
     else
     b=b-a;
  g<<a;
  }
f.close();
g.close();
return 0;
}