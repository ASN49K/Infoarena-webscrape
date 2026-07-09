#include <fstream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

template<typename T> T gcd(T a,T b) { return !b ? a : gcd(b,a % b);}

int main()
{
	int T , X  , Y;
	for(fin>>T;T;T--)
	{
		fin>>X>>Y;
		fout<<gcd(X,Y)<<'\n';
	}
	return 0;
}
