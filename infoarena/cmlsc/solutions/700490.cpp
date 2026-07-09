#include <fstream>
#define nm 1030

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int X[nm], Y[nm], n, m, XY[nm][nm], direction[nm][nm];

void cmlsc()
{
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(X[i] == Y[j])
			{
				XY[i][j] = XY[i - 1][j - 1] + 1;
				direction[i][j] = -1;
			}
			else
				if(XY[i - 1][j] == XY[i][j - 1])
				{
					XY[i][j] = XY[i - 1][j];
					direction[i][j] = 2;
				}
				else
					if(XY[i - 1][j] < XY[i][j - 1])
					{
						XY[i][j] = XY[i][j - 1];
						direction[i][j] = 1;
					}
					else
					{
						XY[i][j] = XY[i - 1][j];
						direction[i][j] = 0;
					}
}
void cauta()
{
	int v[nm], i = n, j = m, c = XY[n][m];
	g << c << '\n';
	while(c > 0)
	{
		if(direction[i][j] == -1)
		{
			v[c] = X[i];
			c --;
			i --;
			j --;
		}
		else
			if(direction[i][j] == 0 || direction[i][j] == 2)
				i --;
			else
				j --;
	}
	for(int i = 1; i <= XY[n][m]; i ++)
		g << v[i] << ' ';
}

int main()
{
	f >> n >> m;
	for(int i = 1; i <= n; i ++)
		f >> X[i];
	for(int j = 1; j <= m; j ++)
		f >> Y[j];
	cmlsc();
	cauta();
}