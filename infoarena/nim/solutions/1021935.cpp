#include <fstream>
using namespace std;
int t,n,xs,a;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
	fin>>t;
	while(t--)
	{
		fin>>n;
		xs=0;
		while(n--)
		{
			fin>>a;
			xs^=a;
		}
		if(xs)
			fout<<"DA\n";
		else
			fout<<"NU\n";
	}
	return 0;
}
