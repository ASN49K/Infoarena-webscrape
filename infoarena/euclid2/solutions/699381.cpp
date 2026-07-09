#include<iostream>
#include<fstream>
using namespace std;

long cmmdc(long a, long b)
{long l=0;
	while(a%b!=0)
	{l=a%b; a=b; b=l;}
return b;}

int main()
{long T, a, b, i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(i=1;i<=T;i++)
{f>>a>>b;
g<<cmmdc(a, b)<<'\n';}
return 0;}