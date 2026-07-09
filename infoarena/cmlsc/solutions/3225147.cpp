#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

typedef long long ll;

int n, m;
vector<int>a, b;
int main()
{
	//cout << "buna";
	f >> n >> m;
	a.push_back(0);
	b.push_back(0);//1-->m
	for (int i = 0; i < n; i++)
	{
		int x;
		f >> x;
		a.push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		f >> x;
		b.push_back(x);
	}
	vector<vector<int>>mat(n + 2, vector<int>(m + 2));
	//int mat[1025][1025];
	vector<vector<string>>sol(n+2, vector<string>(m+2));
	for (int i = 0; i <= n; i++)
	{
		mat[i][0] = 0;
		sol[i][0] = "";
	}
	for (int i = 0; i <= m; i++)
	{
		mat[0][i] = 0;
		sol[0][i] = "";
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
				mat[i][j] =  mat[i-1][j - 1]+ (a[i] == b[j]);
			else mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);

			if (sol[i - 1][j].size() > sol[i][j - 1].size())
			{
				if (a[i] == b[j])
					sol[i][j] = sol[i - 1][j] + to_string(a[i]) + " ";
				else
					sol[i][j] = sol[i - 1][j];
			}
			else {
				if (a[i] == b[j])
					sol[i][j] = sol[i][j - 1] + to_string(a[i]) + " ";
				else
					sol[i][j] = sol[i][j - 1];
			}
		}
	}
	
	g << mat[n][m] << "\n" << sol[n][m];

}