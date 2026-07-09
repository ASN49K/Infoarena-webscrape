// Lungimea CMLSC a doua siruri
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Dim = 1025;
int a[Dim], b[Dim], n, m;
int c[Dim][Dim];

void Read();
void Cmlsc();
void Write(int i, int j);
void Debug();

int main()
{
	Read();
	Cmlsc();
	fout << c[n][m] << '\n';
//	Debug();
	Write(n, m);
	fin.close();
	fout.close();
}


void Read()
{
	fin >> n >> m;
	for (int i = 0; i < n; ++i)
		fin >> a[i];
	for (int i = 0; i < m; ++i)
		fin >> b[i];
}

// O(n^2) Time Complexity
// O(n^2) Memory Complexity
void Cmlsc()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if ( a[i - 1] == b[j - 1] )
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);

}

void Write(int i, int j)
{
	if ( !i || !j) return;
	if ( a[i - 1] == b[j - 1] )
	{
		Write(i - 1, j - 1);
		fout << a[i - 1] << ' ';
		return;
	}
	// aici a[i - 1] != b[j - 1]
	if ( c[i - 1][j] > c[i][j - 1] )
		Write(i - 1, j);
	else
		Write(i, j - 1);
}



void Debug()
{
	for (int i = 1; i <= n; ++i)
	{
		for ( int j= 1; j <= m; ++j)
			fout << setw(3) << c[i][j];
		fout << '\n';
	}
}
