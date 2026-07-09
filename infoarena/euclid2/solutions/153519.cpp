#include<fstream.h>   
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long t,a,b,r;
int main()   
{f>>t;
while(t)
{f>>a;
 f>>b;
 do
  {r=a%b;
   a=b;
   b=r;
  }
 while(r);
 g<<a<<'\n';
 t--;
}
f.close();
g.close();
return 0;   
}  
