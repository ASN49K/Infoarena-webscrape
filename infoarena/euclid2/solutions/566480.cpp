#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

struct pereche{
	int a, b;
};

void Cmmdc(int a, int b);
int main()
{
	int n;
	pereche s[100001];
	
	fin >> n;
	for ( int i = 0; i < n; i++ )
	{
		fin >> s[i].a >> s[i].b;
		Cmmdc(s[i].a, s[i].b);
	}
	
	fin.close();
	fout.close();
	return 0;
}

void Cmmdc(int a, int b)
{
	while ( a != b )
	{
		if ( a > b)
			a-=b;
		if ( b > a )
			b-=a;
	}
	fout << a << '\n';
		
}
