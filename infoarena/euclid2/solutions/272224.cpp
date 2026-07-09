#include<fstream.h>
int main()
{unsigned long a,r,b,T;
int i;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

f>>T;
 for(i=1;i<=T;i++)
  {f>>a>>b;
   while(b!=0)
    {r=a%b;
     a=b;
     b=r;}
    g<<a<<'\n';}
f.close();
g.close();
return 0;
}
