#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void cmmdc(long,long,long&);
int main()
{
	long a,b,d;
	f>>a>>b;
	cmmdc(a,b,d);
	g<<d;

return 0;
}
void cmmdc(long a,long b,long &d)
{
	if (b==0) d=a;
	else cmmdc(b,a%b,d);
}