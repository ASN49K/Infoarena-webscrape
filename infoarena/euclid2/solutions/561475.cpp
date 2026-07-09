#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
		if(a%b==0)
			return b;
		else
			return cmmdc(b, a%b);
}
			


int main()
{
	int a, b, T;


	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>T;
	for(int i=0; i<T; i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a, b)<<"\n";
	}
	fin.close();
	fout.close();

	return 0;
}