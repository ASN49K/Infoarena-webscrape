#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define nmax 1030
#define MOD 1999999973 
#define INF 2123456789
//#define fin cin 
//#define fout cout 

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[nmax], b[nmax];
int dp[nmax][nmax];
queue <int> q;

int main()
{
	int i, j, cnt;
	fin >> n >> m;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	for (i = 1; i <= m; i++)
		fin >> b[i];
	for (i = n; i >= 1; i--)
		for (j = m; j >= 1; j--)
			if (a[i] == b[j])
				dp[i][j] = dp[i + 1][j + 1] + 1;
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
	i = j = 1; cnt = 0;
	while (i <= n && j <= m)
	{
		if (a[i] == b[j])
		{
			q.push(a[i]);
			cnt++;
			i++; j++;
		}
		else if (dp[i + 1][j] > dp[i][j + 1])
			i++;
		else
			j++;
	}
	fout << cnt << "\n";
	while (!q.empty())
	{
		fout << q.front() << " ";
		q.pop();
	}
	fin.close();
	fout.close();
	return 0;
}