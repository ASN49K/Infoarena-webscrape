#include <fstream>
using namespace std;

int euclid(int a, int b)
{
	if(b==0)
		return a;
	else
		return euclid(b,a%b);
}

int main()
{
	long long a, b;
	
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int i, t;
	fin>>t;

	for(i=1;i<=t;++i)
	{
		fin>>a >>b;
		fout<<euclid(a,b) <<'\n';
	}
	
	return 0;
}
			