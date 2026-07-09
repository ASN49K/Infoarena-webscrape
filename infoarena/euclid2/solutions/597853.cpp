#include<fstream>
using namespace std;

int a,b,nr;
fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);

int cmmdc(int a,int b)
{
	if(!b) return a;
	return cmmdc(b,a%b);
}

int main()
{
	f>>nr;
	while(nr)
	{
		nr--;
		f>>a>>b;
		g<<cmmdc(a,b)<<'\n';
	}
	return 0;
}