#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t,n,nim;

int main() 
{
	fin >> t;
	for(int i = 1; i <= t; i++) 
	{
		fin >> n;
		int xs = 0;
		for(int j = 1; j <= n; j++) 
		{
			fin >> nim;
			xs ^= nim;
		}

		if(xs) fout << "DA" << '\n';
		else fout << "NU" << '\n';
	}
}