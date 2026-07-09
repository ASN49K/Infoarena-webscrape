#include<fstream>
using namespace std;

long cmmdc(long a, long b)
{
	if(b==0) return a;
	else return cmmdc(b,a%b);
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long a,b,T,i;
	f>>T;
	for(i=1; i<=T; i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}