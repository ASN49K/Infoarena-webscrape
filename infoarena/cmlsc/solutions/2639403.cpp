#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1024;
const int MMAX = 1024;
int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	vector<int> a,b;
	int n,m;
	cin >> m >> n;
	a.resize(m+1);
	b.resize(n+1);
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	int mat[MMAX][NMAX];
	for(int i = 0; i < m; i++)
		mat[i][0] = 0;
	for(int j = 0; j < n; j++)
		mat[0][j] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if(a[i] == b[j])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
	int ct = 0, sir[MMAX];
	for(int i = m, j = n; i && j; )
	{
		if(a[i] == b[j])
		{
			sir[++ct] = a[i];
			i--;
			j--;
		}
		else if(mat[i][j-1] < mat[i-1][j])
			i--;
		else
			j--;
	}
	cout << mat[m][n] << '\n';
	for(int i = ct; i; --i)
	{
		cout << sir[i] << ' ';
	}
	return 0;
}

