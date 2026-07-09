#include <fstream>

std::ifstream  fin("euclid2.in");
std::ofstream fout("euclid2.out");

long long int a, b, c;

void cmmdc()
{
	while (b)
	{
		c = a % b;
		a = b;
		b = c; 
	}
}

int main()
{	
	fin >> a >> b;
	
	cmmdc();
	
	fout << a;
	
	fout.close();
}
