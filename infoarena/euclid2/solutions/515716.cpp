#include<iostream.h>
#include<fstream.h>
int main()
{long a, b, t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(t; t; --t)
{f>>a>>b;
while (b!=0){long r=a%b;
             a=b;
			 b=r;}
g<<a<<"\n";}
f.close();
g.close();
return 0;}