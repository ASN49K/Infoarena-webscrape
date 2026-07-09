#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Dim = 1025;
short a[Dim], b[Dim];
short L[Dim][Dim];
int n, m;


void Read();
void CmlsComun();
void Write(int i, int j);

int main()
{
	Read();
	CmlsComun();

	fout << L[n][m] << '\n';
	Write(n, m);

	return 0;
}

void CmlsComun()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i] == b[j]) L[i][j] = 1 + L[i - 1][j - 1];
			else L[i][j] = max(L[i][j - 1], L[i - 1][j]);
}

void Read()
{
	fin >> n >> m;
	for(int i = 1; i <= n; ++i)
        fin >> a[i];
    for(int i = 1; i <= m; ++i)
        fin >> b[i];

    fin.close();

}

void Write(int i, int j)
{
    if(L[i][j])
    {
        if(a[i] == b[j])
        {
            Write(i - 1, j - 1);
            fout << a[i] << ' ';
        }
        else
        {
            if(L[i - 1][j] > L[i][j - 1])
                Write(i - 1, j);
            else
                Write(i, j - 1);
        }
    }
}
