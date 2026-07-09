#include<fstream>
#include<iostream>
using namespace std;
long cmmdc(long a, long b)
{
while(a!=b)
	{
	if(a>b)a=a%b;
	else b=b%a;
	}
return a;
}
int main()
{
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
long n,i,a,b;
f>>n;
for(i=1;i<=n;i++)
		{
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
		}
f.close();
g.close();
return 0;
}