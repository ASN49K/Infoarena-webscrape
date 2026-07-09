#include<fstream>
#include<iostream>
using namespace std;
int cmmdc(int a, int b)
{
while(a!=b)
	{
	if(a>b)a=a-b;
	else b=b-a;
	}
return a;
}
int main()
{
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int n,v[20],i,a,b;
f>>n;
for(i=1;i<=n;i++)
		{
		f>>a>>b;
		v[i]=cmmdc(a,b);
		}
for(i=1;i<=n;i++)g<<v[i]<<endl;
f.close();
g.close();
return 0;
}