#include <fstream>

using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	unsigned T,a=0,b,i;
	fin>>T;
	for(i=1;i<=T;i++)
	{
		if(a!=0)
		{
			fout<<'\n';
		}
		fin>>a>>b;
		while(a!=b)
		{
			if(a>b)
				a=a-b;
			else
				if(b>a)
					b=b-a;
		}
		fout<<a;
	}
	fin.close();
	fout.close();
	return 0;
}
