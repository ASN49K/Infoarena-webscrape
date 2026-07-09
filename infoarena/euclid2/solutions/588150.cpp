#include<fstream.h>
int main()
{long a,b,r,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
while(t--)
     {f>>a>>b;
     r=a%b;
     while(r!=0)
           a=b,b=r,r=a%b;
     g<<b<<"\n";}
f.close();
g.close();
return 0;}
