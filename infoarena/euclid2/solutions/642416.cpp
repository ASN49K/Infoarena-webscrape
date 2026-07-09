#include <fstream>
using namespace std;
int main()
{
	unsigned long t,a,b,r;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>t;
	for (int i=0;i<t;i++)
	{
		fin>>a>>b;
		while (b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<'\n';
	}
	fin.close();
	fout.close();
	return 0;
}