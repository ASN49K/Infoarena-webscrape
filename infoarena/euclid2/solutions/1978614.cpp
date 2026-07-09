#include <iostream>
#include <fstream>
using name space std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
int a,b,c,d;
f>>c;
while (c>=1)
{
	f>>a>>b;
	while (a!=0 && b!=0){
	
	if (a>b) a=a%b;
	if (b>a) b=b%a;}
	t=t-1;
	if (a==0) d=b;
	if (b==0) d=a;
	g<<d
	
	}	
	


return 0;	
}

