#include <fstream>
int cmmdc (int a, int b)
{
	int c;
	while (b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main()
{
	int t, a, b;
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	fin>>t;
	while (t)
	{
		fin>>a>>b;
		fout<<cmmdc(a, b)<<"\n";
		t--;
	}
	return 0;
}