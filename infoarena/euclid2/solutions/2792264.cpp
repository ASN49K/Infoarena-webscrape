#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout ("euclid2.oput");

int Euclid(int a, int b)
{
	while(b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int main()
{
	
	int c[100001];
	int a, b;
	int n;
	
	fin >> n;
	int p = 0;
	
	while(n)
	{
		fin >> a >> b;
		c[p++] = Euclid(a, b);
		n--;
		
	}
	
	for (int i = 0; i < p;++i)
		fout << c[i] << '\n';
	
	return 0 ;
}
