#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{while(b!=0)
	{int t=b;
	b=a%b;
	a=t;}
return a;}
int main()
{int a,b,n;
f>>n;
for(int i=1;i<=n;i++)
	{f>>a>>b;
	g<<cmmdc(a,b)<<endl;}
f.close();
g.close();
return 0;}