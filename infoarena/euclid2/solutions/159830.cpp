#include <fstream>

int t, a, b;

int cmmdc(int a, int b)
{
	if(b == 0)
		return a;
	else
		return cmmdc(b, a%b);
}

int main()
{
	std::ifstream read("euclid2.in");
	std::ofstream write("euclid2.out");
	read >> t;
	int i;
	for(i = 0; i < t; i++)
	{
		read >> a >> b;
		write << cmmdc(a, b) << std::endl;
	}
	return 0;
}
