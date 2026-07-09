#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long n,m,d;

long euclid ( long n, long m )
{
	if ( !n || !m )
		return n+m;
	if ( n%m==0 )
		return m;
	else
		return euclid(m,n%m);
}

int main()
{
	f>>n>>m;
	g<<euclid(n,m);
}
