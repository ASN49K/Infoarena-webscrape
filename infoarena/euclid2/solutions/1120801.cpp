#include<iostream.h>
#include<fstream.h>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int cmmdc(int a, int b)
{
int t;
while(b!=0)
{
t=b;
b=a%b;
a=t;
}
return a;
}

int main()
{
int t,i,a,b;
f>>t;
for(i=0;i<t;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}
}