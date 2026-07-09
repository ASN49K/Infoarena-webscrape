#include<fstream.h>

long t, a, b, i, r;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	fin>>t;
	
	for(i=1;i<=t;i++)
	{
		fin>>a>>b;
		
		while(b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		fout<<a<<"\n";
	}
	
	fin.close();
	fout.close();
	
	return 0;
}