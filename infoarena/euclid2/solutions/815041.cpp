#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main ()
{
	unsigned long a,b,t;
	fin>>t;
	for(t;t;t--)
	{
		fin>>a>>b;
		while(a && b)
		{
			if(a>b)
				a=a-b;
			else
				b=b-a;
		}
		if(a>b)
			fout<<a<<endl;
		else
			fout<<b<<endl;
	}
}
