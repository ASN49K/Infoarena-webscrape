#include <iostream>
#include <fstream>
#include <algorithm>
int d[1024][1024];

int main()
{
	int m,n,a[1024],b[1024],n2 = 0,v[1024];

	std::ifstream fin("cmlsc.in");
	
	fin >> m >> n;
	for(int i = 1; i <= m; ++i)
		fin >> a[i];
	
	for(int i = 1; i <= n; ++i)
		fin >> b[i];

	fin.close();

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			if(a[j] == b[i])
				d[i][j] = d[i-1][j-1] + 1;
			else 
				d[i][j] = std::max(d[i-1][j],d[i][j-1]);
		}
	
	for(int i = n,j = m; i;)
	{
		if(a[j] == b[i])
		{
			v[++n2] = b[i];
			--j;
			--i;
		}
		else if(d[i-1][j] > d[i][j-1])
			--i;
		else
			--j;
	}

	std::ofstream fout("cmlsc.out");

	fout << d[n][m] << "\n";

	for(int i = n2; i > 0; --i)
		fout << v[i] << " ";

	return 0;
}