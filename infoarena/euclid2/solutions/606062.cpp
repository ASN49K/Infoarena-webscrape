#include<fstream.h>
int main()
{long a,b,r,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
while(t--)
     {f>>a>>b;
     while((r=a%b))
           a=b,b=r;
     g<<b<<"\n";}
return 0;}
