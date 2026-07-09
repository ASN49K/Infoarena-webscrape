#include <fstream>

using namespace std;

int main()
{
	long long a, b, i, n, t, r;
	
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	fin>>t;
	
	for(i=1;i<=t;++i)
	{
		fin>>a >>b;
		do
		{
			r=a%b;
			a=b;
			b=r;
		}while(r!=0);
		
		fout<<a <<'\n';
	}
	
	return 0;
}
			