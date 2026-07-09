// LCS.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

stack <int> sol;
int n, m, v[1025][1025];
short int *a, *b;

void LCS(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	else if (a[i] == b[j])
	{
		sol.push(a[i]);
		return LCS(i - 1, j - 1);
	}
	else
	{
		if (v[i - 1][j] > v[i][j - 1])
			return LCS(i - 1, j);
		else
			return LCS(i, j - 1);
	}
}//OK

int main()
{
	in >> n >> m;
	a = new short int[n + 1];
	b = new short int[m + 1];

	for (int i = 1; i <= n; i++)
		in >> a[i];

	for (int i = 1; i <= m; i++)
		in >> b[i];

	for (unsigned i = 1; i <= n; i++)
	{
		for (unsigned j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				v[i][j] = v[i - 1][j - 1] + 1;
			}
			else
			{
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
			//out << v[i][j] << ' ';
		}
		//out << '\n';
	}

	out << v[n][m] << '\n';


	LCS(n, m);

	while (!sol.empty())
	{
		out << sol.top() << ' ';
		sol.pop();
	}

	delete a,b;

    return 0;
}//OK

