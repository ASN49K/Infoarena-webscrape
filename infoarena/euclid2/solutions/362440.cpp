#include <fstream>

std::ifstream  fin("euclid2.in");
std::ofstream fout("euclid2.out");

long long int a, b, c;
long int N;

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
	fin >> N;
	
	for (long int i = 0; i < N; i++)
	{
		fin >> a >> b;
		cmmdc();
		fout << a << "\n";
	}
	
	fout.close();
}
