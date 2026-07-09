#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void solve()
{
	int a,b;
	in>>a>>b;
	while(a*b)
	{
		a%=b;
		if(a) b%=a;
	}
	out<<((a>b)?a:b)<<'\n';
}

int main()
{
	int t;
	in>>t;
	while(t--) solve();
	return 0;
}