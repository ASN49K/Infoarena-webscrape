#include<fstream.h>

int div(int a,int b)
{
while (a!=b)
 {
  if (a>=b)  a-=b;
      else b-=a;
 }
return a;
}

int main()
{
int t,a,b,d;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

f>>t;
for (int i=1;i<=t;i++)
 {
  f>>a>>b;
  g<<div(a,b)<<endl;
 }
return 1;
}