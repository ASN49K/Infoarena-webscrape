#include<iostream.h>
#include<fstream.h>
int a, b, t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int r;
f>>t;
for(int i=1; i<=t; i++)
{f>>a>>b;
while (b!=0){r=a%b;
             a=b;
			 b=r;}
g<<a<<endl;}
f.close();
g.close();
return 0;
}