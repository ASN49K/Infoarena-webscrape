#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

short a[1025], b[1025], sol[1025][1025], visited[256], m, n;

void read_input()
{
	string line;
	ifstream myfile("cmlsc.in");
	if (myfile.is_open())
	{
		myfile >> m;
		myfile >> n;
		//cout << m;
		//cout << n;
		int i;
		//cout << '\n';
		i = 1;
		while (i <= m)
		{
			myfile >> a[i++];
			//cout << a[i - 1] << ' ';
		}
		//cout << '\n';
		i = 1;
		while (i <= n)
		{
			myfile >> b[i++];
			//cout << b[i - 1] << ' ';
		}
		myfile.close();
	}
}

short max(short a, short b)
{
	return a > b ? a : b;
}

void print_solution()
{
	short i = n, j = m;
	short sol_arr[1025];
	while (sol[i][j] > 0)
	{
		if (sol[i][j] == sol[i][j - 1])
		{
			j = j - 1;
		}
		else
		{
			if (sol[i][j] == sol[i - 1][j])
			{
				i = i - 1;
			}
			else
			{
				sol_arr[sol[i][j]] = a[j];
				i = i - 1;
			}
		}
	}
	
	ofstream fout("cmlsc.out");
	fout << sol[n][m] << '\n';
	for (i = 1; i <= sol[n][m]; i++)
	{
		fout << sol_arr[i] << ' ';
	}
	fout.close();
}

void resolve1()
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (b[i] == a[j])
			{
				sol[i][j] = sol[i - 1][j - 1] + 1;
			}
			else
			{
				sol[i][j] = max(sol[i - 1][j], sol[i][j - 1]);
			}
		}
		visited[b[i]]++;
	}

	print_solution();

	//cout << '\n';
	//cout << '\n';
	//for (i = 1; i <= n; i++)
	//{
	//	cout << '\n';
	//	for (j = 1; j <= m; j++)
	//	{
	//		cout << sol[i][j] << ' ';
	//	}
	//}

	//cout << '\n';
	//cout << '\n';

	//cin >> i;
}

int main()
{
	read_input();

	resolve1();

	return 0;
}