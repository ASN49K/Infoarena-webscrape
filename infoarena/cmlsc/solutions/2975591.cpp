#include<bits/stdc++.h>
using namespace std;

const int N = 1030;

ifstream in ("cmlsc.in");
ofstream out("cmlsc.out");
// auto& in = cin;
// auto& out = cout;

int n, m, a[N], b[N], best[N][N], sol[N];

void read()
{
	in>>n>>m;
	for(int i=1; i<=n; i++)
		in>>a[i];
	for(int i=1; i<=m; i++)
		in>>b[i];
}

void build()
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(a[i] == b[j])
				best[i][j] = 1 + best[i-1][j-1];
			else
				best[i][j] = max(best[i-1][j], best[i][j-1]);
}
void reconstruct()
{
	int p = best[n][m];
	int i = n, j = m;
	while(i > 0 && j > 0)
	{
		if(a[i] == b[j])
		{
			sol[p--] = a[i];
			i--;
			j--;
		}
		else if(best[i-1][j] > best[i][j-1])
			i--;
		else
			j--;
	}
}
void show()
{
	out<<best[n][m]<<endl;
	for(int i = 1; i <= best[n][m]; i++)
		out<<sol[i]<<' ';
	out<<endl;
}
int main()
{
	read();
	build();
	reconstruct();
	show();
	return 0;
}