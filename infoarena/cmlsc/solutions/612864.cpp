#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

void read();
void solve();
void check();
void print();

int main()
{
	read();
	solve();
	check();
	print();

	return 0;
}

int nr_a, nr_b;
char a[1025];
char b[1025];
int dp[1025][1025];

void read()
{
	ifstream ifs("cmlsc.in", fstream::in);

	ifs >> nr_a >> nr_b;

	for (int i = 1; i <= nr_a; ++i)
		ifs >> a[i];

	for (int j = 1; j <= nr_a; ++j)
		ifs >> b[j];

	ifs.close();
};

void solve()
{

	for (int i = 1; i <= nr_a; ++i)
		for (int j = 1; j <= nr_b; ++j)
			if (a[i] == b[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
};

void check()
{
};

void print_sol(int i, int j)
{
	if (i == 0) return;
	if (j == 0) return;

	if (dp[i][j] == dp[i-1][j])
	{
		print_sol(i-1, j);
		return;
	}

	if (dp[i][j] == dp[i][j-1])
	{
		print_sol(i, j-1);
		return;
	}

	print_sol(i-1, j-1);
	printf("%c ", a[i]);
}

void print()
{
	freopen("cmlsc.out", "w", stdout);
	printf("%d\n",dp[nr_a][nr_b]);

	print_sol(nr_a, nr_b);
};
