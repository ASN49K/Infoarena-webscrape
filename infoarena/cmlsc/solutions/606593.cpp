#include <fstream>
#include <iostream>
#include <stack>

#define MAXN 1024

#define max(a, b) \
({	typeof(a) _a=a; \
	typeof(b) _b=b; \
	_a>=_b?_a:_b; \
})

using namespace std;

unsigned short C[MAXN+1][MAXN+1];
stack<unsigned short> lcs;

int BuildTable(
	const unsigned short X[],
	const int n,
	const unsigned short Y[],
	const int m)
{
	int i, j;
	for (i=1; i<=n; ++i)
	{
		for (j=1; j<=m; ++j)
		{
			if (X[i-1] == Y[j-1])
				C[i][j] = C[i-1][j-1] + 1;
			else
				C[i][j] = max(C[i][j-1], C[i-1][j]);
		}
	}
	
	return C[n][m];
}

void GetSolution(
	const unsigned short X[],
	const unsigned short Y[],
	const int i,
	const int j)
{
	if (i && j)
	{
		if (X[i-1] == Y[j-1])
		{
			lcs.push(X[i-1]);
			GetSolution(X, Y, i-1, j-1);
		}
		else if (C[i][j-1] > C[i-1][j])
		{
			GetSolution(X, Y, i, j-1);
		}
		else
		{
			GetSolution(X, Y, i-1, j);
		}
	}
}

int main()
{
	int n,m;
	unsigned short X[MAXN], Y[MAXN];
	fstream fin("cmlsc.in", fstream::in);
	fstream fout("cmlsc.out", fstream::out);
	
	fin >> n >> m;
	//cout << n << " " << m << endl;
	
	for (int i=0; i<n; ++i)
	{
		fin >> X[i];
		//cout << X[i] << " ";
	}
	//cout << endl;
	
	for (int i=0; i<m; ++i)
	{
		fin >> Y[i];
		//cout << Y[i] << " ";
	}
	//cout << endl;
	
	fout << BuildTable(X,n,Y,m) << endl;
	GetSolution(X, Y, n, m);
	
	while (!lcs.empty())
	{
		fout << lcs.top() << " ";
		lcs.pop();
	}
	fout << endl;
	
	fin.close();
	fout.close();
	return 0;
}
