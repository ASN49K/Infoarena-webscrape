#include<fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int main()
{
	int a[10], n, b[10], m, c[10][10], d[10], i, j;
	fin >> n >> m;
	for ( i = 1; i <= n; i++ )
		fin >> a[i];
	for ( i = 1; i <= m; i++ )
		fin >> b[i];
	for (  i = 1; i <= n; i++ )
		for (  j = 1; j <= m; j++ )
			if ( a[i] == b[j] )
				c[i][j] = a[i];
			else c[i][j] = 0;
			int k = 1;
			int e = 0;
			for ( j = 1; j <= m; j++ )
				for ( i = 1; i <= n; i++ )
					if ( c[i][j] != 0  && i > e)
					{
						d[k++] = c[i][j];
						e = i;
					}
					k--;
					fout << k << "\n";
					for ( i = 1; i <= k; i++ )
						fout <<d[i]<< " ";
					fin.close();
					fout.close();
					return 0;
}