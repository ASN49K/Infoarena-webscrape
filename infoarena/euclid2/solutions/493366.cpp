#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
	int r=1;
	while(r)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	int T,i,a,b;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin >> T;
	for(i=1;i<=T;i++)
	{
		fin >> a >> b;
		fout << cmmdc(a,b) << "\n";
	}
	
}