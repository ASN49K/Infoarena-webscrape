#include <iostream>
#include <fstream>

using namespace std;

const char iname[] = "cmlsc.in";
const char oname[] = "cmlsc.out";

ifstream fin(iname);
ofstream fout(oname);

int dp[1026][1026], i, j, n, m, k;
int S[1026], T[1026], sol, sol2, pzx, pzy, SIR[1026];

int main()
{
	fin >> n >> m;
	for(i = 1; i <= n; i ++)
		fin >> S[i];
	for(i = 1; i <= m; i ++)
		fin >> T[i];
	
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
		{
			if(S[i] == T[j])
			{
				if(i == 1 || j == 1)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
				if(dp[i][j] > sol)
				{
					sol = dp[i][j];
					pzx = i;
					pzy = j;
				}
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	
	SIR[++k] = S[pzx];
	int limx = pzx;
	int limy = pzy;
	for(i = limx - 1; i >= 1; i --)
		for(j = limy - 1; j >= 1; j --)
		{
			if(S[i] == T[j])
				if(dp[i][j] == dp[pzx][pzy] - 1)
				{
					SIR[++k] = T[j];
					pzx = i;
					pzy = j;
				}
			if(k == sol)
				break;
		}
	fout << sol << "\n";
	for(i = k; i >= 1; i --)
		fout << SIR[i] << " ";
	return 0;
}