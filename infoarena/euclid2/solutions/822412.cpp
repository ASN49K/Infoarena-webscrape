#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main ()
{
	int a,b,t;
	fin>>t;
	for(;t;t--)
	{
		fin>>a>>b;
		while(a && b)
		{
			if(a>b)
				a%=b;
			else
				b%=a;
		}
		if(a>b)
			fout<<a<<endl;
		else
			fout<<b<<endl;
	}
}
