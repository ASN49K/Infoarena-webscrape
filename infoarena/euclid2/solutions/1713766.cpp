//http://www.infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int l,a,b,r,k;
	fin>>l;
	for(k=1;k<=l;k++)
	{
		fin>>a>>b;
		r=a%b;
		while(r!=0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		fout<<b<<'\n';
	}
	return 0;
}
