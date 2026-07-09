#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const string name = ("cmlsc");
ifstream fin(name + ".in");
ofstream fout(name + ".out");

int dyn[1024][1024];
int n, m;
int v[1024];
int a[1024];

void solve()
{
	fin >> n >> m;
	for (int i = 1; i <= n; i++) fin >> v[i];
	for (int i = 1; i <= m; i++) fin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (v[i] == a[j])
			{
				dyn[i][j] = 1 + dyn[i - 1][j - 1];
			}
			else {
				dyn[i][j] = max(dyn[i - 1][j], dyn[i][j - 1]);
			}
		}
	}
	int rez[1024];
	int ans = 0;
	for (int i=n;i;){
		for (int j = m; i;) {

			if (v[i] == a[j])
			{
				rez[++ans] = v[i];
				i--;
				j--;
			}
			else if (dyn[i - 1][j] < dyn[i][j - 1]) j--;
			else i--;
		}
	}
	fout << ans << '\n';
	for (int i = ans; i >= 1; i--)
	{
		fout << rez[i] << ' ';
	}
		
}

int main()
{
	solve();
}