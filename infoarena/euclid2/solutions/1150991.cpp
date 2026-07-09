#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void solve()
{
	int a,b;
	in>>a>>b;
	while(a&&b)
	{
		a%=b;
		if(a) b%=a;
	}
	out<<((a>b)?a:b)<<'\n';
	out.flush();
}

int main()
{
	int t,i=0;
	in>>t;
	while(t--) solve();
}