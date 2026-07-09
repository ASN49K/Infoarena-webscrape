#include <fstream>

using namespace std;

#define LL long long

int t;


inline int cmmdc (LL a, LL b)
{
	if (b == 0) return a;
	return cmmdc (b, a % b);
}


int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	f >> t;
	
	for ( ; t; -- t)
	{
		LL A, B;
		
		f >> A >> B;
		
		g << cmmdc (A, B) << '\n';
	}
	
	f.close();
	g.close();
	
	return 0;
}
