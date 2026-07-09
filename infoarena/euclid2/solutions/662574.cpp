#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
	int c;
	while(b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}
int main() 
{
	int a,b,t;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(int i=1;i<=t;i++)
	{
		f>>a;
		f>>b;
		g<<cmmdc(a, b)<<endl;
	}
	return 0;
}
