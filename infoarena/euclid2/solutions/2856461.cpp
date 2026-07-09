#include <fstream>

using namespace std;

int cmmdc ( int a,int b)
{

	while(b)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	ifstream reader ("euclid2.in");
	ofstream writer ("euclid2.out");
	int a,b,nr;
	reader>>nr;
	while(nr)
	{
       
		reader>>a>>b;
	        writer<<cmmdc(a,b)<<'\n';
		--nr;
	}
	return 0;
}
