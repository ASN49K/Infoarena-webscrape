#include <fstream>
#include <vector>
#include <iostream> 

using namespace std;

#define MAXN 1030

int SOL[MAXN][MAXN];
int n, m, a[MAXN], b[MAXN];
vector < int > rec;

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		f >> a[i];
	
	for (int i = 1; i <= m; ++i)
		f >> b[i];
	
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i] == b[j])
				SOL[i][j] = SOL[i - 1][j - 1] + 1;
			else
				SOL[i][j] = max(SOL[i - 1][j], SOL[i][j - 1]);
	
	g << SOL[n][m] << '\n';
	
	for (int i = n, j = m; i != 0 && j != 0; )
	{
		if (a[i] == b[j])
		{
			rec.push_back(a[i]);
		
			--i;
			--j;
		}
		else
		{
			i = SOL[i - 1][j] >= SOL[i][j - 1] ? i - 1 : i ;
			j = SOL[i - 1][j] >= SOL[i][j - 1] ? j : j - 1;
	
		}
	}
	
	for (int i = rec.size() - 1; i >= 0; --i)
		g << rec[i] << " ";
	
	f.close();
	g.close();
	
	return 0;
}
