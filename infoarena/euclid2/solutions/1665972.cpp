#include <fstream>
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if(x % y == 0) return y; else return(y, x % y);
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	int n, a, b;
	fin >> n;
	for(int i = 1; i <= n; i++)
	{
		fin >> a >> b;
		if(a > b) fout << gcd(a,b); else fout << gcd(b,a);
		if(i != n) fout << "\n";
	}
	
	return 0;
}






