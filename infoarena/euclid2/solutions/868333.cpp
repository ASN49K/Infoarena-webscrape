#include<fstream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{return gcd(b,a%b);}
}
int main()
{
	int pairs,a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>pairs;
	while(pairs)
	{
		f>>a;
		f>>b;
		g<<gcd(a,b)<<"\n";
		pairs--;
	}
	f.close();
	g.close();
	return 0;
}
