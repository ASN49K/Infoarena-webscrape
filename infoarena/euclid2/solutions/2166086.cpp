using namespace std;

#include <fstream>

static inline int cmmdc(int a, int b)
{
	if (!a) return b;

	if (!b) return a;

	if (a == b) return a;

	if (!(a&1) && !(b&1)) return cmmdc(a>>1, b>>1)<<1;

	if (!(a&1)) return cmmdc(a>>1, b);
	
	if (!(b&1)) return cmmdc(a, b>>1);

	if (a>b) return cmmdc((a-b)>>1, b);
	
	return cmmdc((b-a)>>1, a);
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
