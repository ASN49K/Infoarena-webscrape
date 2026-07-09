#include<fstream.h>

int div(int a,int b)
{int x;
while (b)
 if(!b) return a;
  else
   {
    x=a;
    a=b;
    b=x%b;
   }
return a;
}

int main()
{
int t,a,b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

f>>t;
for (int i=1;i<=t;i++)
 {
  f>>a>>b;
  g<<div(a,b)<<'\n';
 }
return 1;
}