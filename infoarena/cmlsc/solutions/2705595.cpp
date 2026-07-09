#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int a[1024], b[1024], d[1024][1024];
int s[1025];

void solve(int x, int y)
{
	int sol = 0;
	if (a[x] == b[y])
	{
		sol = 1;
		if (x == 0 || y == 0)
		{
			d[x][y] = sol;
		}
		else
		{
			d[x][y] = sol + max(d[x - 1][y], d[x][y - 1]);
		}
		s[d[x][y]] = a[x];
	}
	else
	{
		if (x == 0 || y == 0)
		{
			d[x][y] = sol;
		}
		else
		{
			d[x][y] = sol + max(d[x - 1][y], d[x][y - 1]);
		}
	}
	
}

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	// Program
	int N, M;
	f >> N;
	f >> M;
	
	for (int i = 0; i < N; i++)
	{
		f >> a[i];
	}
	for (int i = 0; i < M; i++)
	{
		f >> b[i];
	}
	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			solve(n, m);
		}
	}
	g << d[N - 1][M - 1]<<endl;
	for (int i = 1; i <= d[N - 1][M - 1]; i++)
	{
		g << s[i] << " ";
	}

	// Exit
	f.close();
	g.close();
	return 0;
}
