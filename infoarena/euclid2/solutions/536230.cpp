#include <fstream>
#define LL long long
using namespace std;

int cmmdc(LL a, LL b)
{
	if(b == 0)return a;
	return cmmdc(b, a % b);
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	int t;
	
	for(f >> t; t; --t)
	{
		LL a, b;
		
		f >> a >> b;
		
		g << cmmdc(a, b) << '\n';
	}
	
	f.close();
	g.close();
}
