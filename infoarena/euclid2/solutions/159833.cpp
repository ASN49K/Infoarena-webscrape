#include <fstream>

int t, a, b;

int cmmdc(int a, int b)
{
	if(b == 0)	return a;
	return cmmdc(b, a%b);
}

int main()
{
	std::ifstream read("euclid2.in");
	std::ofstream write("euclid2.out");
	read >> t;
	for(; t; --t)
	{
		read >> a >> b;
		write << cmmdc(a, b) << std::endl;
	}
	return 0;
}
