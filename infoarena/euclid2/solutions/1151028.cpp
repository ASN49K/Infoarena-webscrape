#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int solve()
{
	int a,b;
	in>>a>>b;
	while(a&&b)
	{
		a%=b;
		if(a) b%=a;
	}
	return ((a>b)?a:b);
}

int main()
{
	int t;
	in>>t;
	while(t--) out<<solve()<<'\n';
}