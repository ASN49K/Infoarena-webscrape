#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025], b[1025], c[1025][1025];
int n, m;

void scrie_sol(int i, int j)
{
    if(i == 0 && j == 0)
        return;
    else
    {
        if(a[i] == b[j])
        {
            scrie_sol(i - 1, j - 1);
            g << a[i] << " ";
        }
        else
        {
            if(c[i - 1][j] > c[i][j - 1])
                scrie_sol(i - 1, j);
            else
                scrie_sol(i, j - 1);
        }
    }
}
int main()
{
	f >> n >> m;

	for(int i = 1; i <= n; i++)
		f >> a[i];

	for(int i = 1; i <= m; i++)
		f >> b[i];

	for(int i = 1; i <= m; i++)
		c[0][i] = 0;

	for(int i = 1; i <= n; i++)
		c[i][0] = 0;


	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}

	g << c[n][m] << "\n";

	scrie_sol(n, m);
}
