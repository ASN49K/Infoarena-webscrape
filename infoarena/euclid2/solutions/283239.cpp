#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long euclid(unsigned long a, unsigned long b)
{
	unsigned long r;
	if(a<b)
	{
		r=a;
		a=b;
		b=r;
	}
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return(b);
}
int main()
{
	unsigned long a,b,t,i;
	f>>t;
	for(i=0;i<t;i++)
	{
		f>>a>>b;
		g<<euclid(a,b)<<'\n';
	}
	f.close();
	g.close();
}