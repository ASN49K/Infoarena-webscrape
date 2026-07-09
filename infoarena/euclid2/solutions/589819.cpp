#include<fstream>
#include<stdio.h>
using namespace std;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,i,a,b,j;
f>>t;
for(i=1;i<=t;i++)
{	f>>a>>b;
if((a%b==0)||(b%a==0))
	if(a>b)
		g<<b<<endl;
	else
		g<<a<<endl;
else
{if(a<b)
j=a/2;
else
j=b/2;
while((a%j!=0)||(b%j!=0))
	j--;
g<<j<<endl;}
}
}
	