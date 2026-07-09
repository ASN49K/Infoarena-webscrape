#include <fstream>
using namespace std;
int dc(int x, int y)
{
	if (!y) return x;
	return dc(y, x%y);
}
int main()
{
	unsigned int t,a,b,i;
	ifstream f1("euclid2.in");
	ofstream f2("euclid2.out");
	f1>>t;
	for (i=1;i<=t;i++) 
	{
		f1>>a>>b;
		{f2<<dc(a,b)<<"\n";}
	}
	f1.close();
	f2.close();
	return 0;
}
