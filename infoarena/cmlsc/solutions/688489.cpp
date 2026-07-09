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

	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(a[i] == b[j])
				d[i][j] = d[i-1][j-1] + 1;
			else 
				d[i][j] = std::max(d[i-1][j],d[i][j-1]);
		}
	
	for(int i = m,j = n; i;)
	{
		if(a[i] == b[j])
		{
			v[++n2] = a[i];
			--j;
			--i;
		}
		else if(d[i-1][j] > d[i][j-1])
			--i;
		else
			--j;
	}

	std::ofstream fout("cmlsc.out");

	fout << n2 << "\n";

	for(int i = n2; i > 0; --i)
		fout << v[i] << " ";

	return 0;
}