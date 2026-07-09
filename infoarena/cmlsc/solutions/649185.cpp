#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

	int subsir[1024] = {0};
	int m, n, x, i;
	int max = -1, cat = 0;

	fin >> n >> m ;
	for ( i = 1; i <= n; i++ )
	{
		fin >> x;
		subsir[x] = 1;
		max = ( max < x )?x:max;
	}

	for ( i = 1; i <= m; i++ )
	{
		fin >> x;
		subsir[x]++;
		if ( subsir[x] >= 2 ) cat++;
		max = ( max < x )?x:max;
	}

	fout << cat << "\n";
	for ( i = 1; i <= max; i++ )
		if ( subsir[i] >= 2 )
		{
			fout<<i<< " ";
		}

	fin.close();
	fout.close();

	return 0;
}