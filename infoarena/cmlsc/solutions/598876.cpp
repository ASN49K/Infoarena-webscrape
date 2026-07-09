#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, nr, a[1025], b[1025], s[1025][1025], c[1025];

int main()
{
	int i, j;
	fin >> n >> m;
	
	for(i = 1; i <= n; i++)
		fin >> a[i];
	for(i = 1; i <= m; i++)
		fin >> b[i];
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(a[i] == b[j])
				s[i][j] = s[i-1][j-1] + 1;
			else
				s[i][j] = (s[i-1][j] < s[i][j-1] ? s[i][j-1] : s[i-1][j]);
	
	for(i = n, j = m; i > 0; )
		if(a[i] == b[j])
		{
			nr++;
			c[nr] = a[i];
			i--;
			j--;
		}
		else
		   	if(s[i][j-1] <= s[i-1][j])
		  		i--;
		  	else
		  		j--;
	
	fout << nr << '\n';
	for(i = nr; i > 0; i--)
		fout << c[i] << ' ';
			
	fin.close();
	fout.close();
	return 0;
}
