using namespace std;

#include <fstream>
#include <cstdlib>
#include <algorithm>

static inline int cmmdc(int a, int b)
{
	if (!a) return b;

	if (!b) return a;

	if (a == b) return a;

	if (!(a&1) || !(b&1)) return cmmdc(a>>(!(a&1)), b>>(!(b&1))) << ((a&1) == (b&1));

	return cmmdc(abs(a-b)>>1, min(a,b));
}

int main ()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	
	int t,a,b;
	
	in>>t;

	for(int i = 0; i < t; ++i) {
		in>>a>>b;
		out<<cmmdc(a, b)<<'\n';
	}
	
	return 0;
}
