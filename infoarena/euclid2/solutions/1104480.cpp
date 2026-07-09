#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return euclid(b,a%b);
	}
}

int solve()
{
	int a,b,n;
	in>>n;
	for(int i=1;i<=n;i++)
	{
		in>>a>>b;
		out<<euclid(a,b)<<"\n";
	}
}

int main()
{
	solve();
	return 0;
}
