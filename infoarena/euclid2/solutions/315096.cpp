#include<fstream.h>
int main()
{int x,y,r,t,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++)
{f>>x>>y;
 while(y>0)
 {r=x%y;
  x=y;
  y=r;
 }
 g<<x<<'\n';}
return 0;
}

