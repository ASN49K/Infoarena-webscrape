#include<iostream.h>
#include<fstream.h>
long a, b, t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{long r;
f>>t;
for(long i=1; i<=t; i++)
{f>>a>>b;
while (b!=0){r=a%b;
             a=b;
			 b=r;}
g<<a<<endl;}
f.close();
g.close();
return 0;
}