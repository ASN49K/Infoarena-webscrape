#include<fstream>
using namespace std;

short v[1024][1024];

int main() 
{
	int n, m, a[1024], b[1024], i, j, r[1024], k = 0;
	
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f >> n >> m;
	for(i = 1; i <= n; ++i)
		f >> a[i];
	for(i = 1; i <= m; ++i)
		f >> b[i];
		
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if(a[i] == b[j])
				v[i][j] = 1 + v[i-1][j-1];
			else if(v[i-1][j] > v[i][j-1])
				v[i][j] = v[i-1][j];
			else
				v[i][j] = v[i][j-1];
	
	for(i = n, j = m; v[i][j];)
	{
		if(a[i] == b[j]) {
			r[k++] = a[i];
			--i; --j; 
		}
		else if(v[i][j] == v[i-1][j])
			--i;
		else
			--j;
	}
	g << v[n][m] << '\n';
	for(i = k - 1; i >= 0; --i)
		g << r[i] << ' ';
	g << '\n';
	g.close();
	return 0;
}
