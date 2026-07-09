#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const string name = ("cmlsc");
ifstream fin(name + ".in");
ofstream fout(name + ".out");

int dyn[1024][1024];
int n, m;
int v1[1024];
int v2[1024];
char a[250];
char b[250];
int rez[1024];
int ans = 0;

void citire(char a[250], char b[250])
{
	fin >> a >> b;
	n = strlen(a);
	m = strlen(b);
	for (int i = 0; i < n; i++)
	{
		v1[i + 1] = a[i] -'0';
	}
	for (int i = 0; i < m; i++)
	{
		v2[i + 1] = b[i] -'0';
	}
}


void reconstituire()
{
	int i = n;
	int j = m;
	while (i!=0 && j!=0)
	{
		if (v1[i] != v2[j]) {
			if (dyn[i - 1][j] > dyn[i][j - 1]) i--;
			else j--;
		}
		else {
			rez[++ans] = v1[i];
			i--;
			j--;
		}
	}
	for (int i = ans; i >= 1; i--) fout << rez[i]<<' ';
}

void solve_dyn()
{	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m ;j++)
		{
			if (v1[i] == v2[j]) {
				dyn[i][j] = 1 + dyn[i - 1][j - 1];
			}
			else {
				dyn[i][j] = max(dyn[i - 1][j], dyn[i][j - 1]);
			}
		}
	}
	fout << dyn[n][m]<<'\n';
	reconstituire();
}

int main()
{
	//citire(a, b);
	fin >> n >> m;
	for (int i = 1; i <= n; i++) fin >> v1[i];
	for (int j = 1; j <= m; j++) fin >> v2[j];
	solve_dyn();
}