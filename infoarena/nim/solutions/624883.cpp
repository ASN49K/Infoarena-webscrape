#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T , xorsum , x , n;

int main()
{
	for(fin>>T;T;T--)
	{
		xorsum = 0;
		for(fin>>n;n;n--)
		 fin>>x , xorsum^=x;

		if(!xorsum) fout<<"NU"; else fout<<"DA";
		fout<<'\n';
	}
	return 0;
}
