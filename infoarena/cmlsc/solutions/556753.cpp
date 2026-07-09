#include <iostream>
#include <fstream>

using namespace std;

const char iname[] = "cmlsc.in";
const char oname[] = "cmlsc.out";
const int  nmax	   = 1026;


ifstream fin(iname);
ofstream fout(oname);

int n, m, a[nmax], b[nmax], sz, i, dp[nmax][nmax], j, sol[nmax], pz1, pz2, k;

int main()
{
	fin >> n >> m;
	for(i = 1; i <= n; i ++)
		fin >> a[i];
	for(i = 1; i <= m; i ++)
		fin >> b[i];
	
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
		{	
			if(a[i] == b[j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]) + 1;
			else
				dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]));
			if(dp[i][j] > sz)
			{
				sz = dp[i][j];
				pz1 = i;
				pz2 = j;
			}
		}
	sol[++k] = a[pz1];
	int kd;
	while(pz1 != 0 && pz2 != 0)
	{	
		kd = 0;
		for(i = pz1; i > 0 && kd == 0; i --)
			for(j = pz2; j > 0 && kd == 0; j --)
				if(dp[i][j] == dp[pz1][pz2] - 1 && a[i] == b[j])
				{
					pz1 = i, pz2 = j;
					kd = 1;
					sol[++k] = a[pz1];
					break;
				}
		if(kd == 0)
			pz1 = 0, pz2 = 0;
	}
	fout << sz << "\n";
	for(i = sz; i > 0; i --)
		fout << sol[i] << " ";
	return 0;
}
		
		
		