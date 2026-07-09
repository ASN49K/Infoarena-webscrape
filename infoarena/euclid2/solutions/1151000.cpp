#include<fstream>

using namespace std;

int c;

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
	c++;
	if(!c%1000) out.flush();
}

int main()
{
	int t;
	in>>t;
	while(t--) solve();
}