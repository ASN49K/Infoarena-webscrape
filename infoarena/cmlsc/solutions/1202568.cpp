/******************************************************************************************
*           .--.																		  *
* ::\`--._,'.::.`._.--'/::			@author Ana M. Mihut	@course InfoArena EduArchive  *
* ::::. `  __::__ ' .:::::			@alias  LT-Kerrigan		@date   31.05.2014			  *
* ::::::-:.`'..`'.:-::::::			@link   http://infoarena.ro/problema/cmlsc			  *
* ::::::::\ `--' /::::::::			@detail	Subsequences		  						  *
*																						  *
*******************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define SIZE 1024

int m, n;
int X[SIZE], Y[SIZE], LCS[SIZE][SIZE], Sol[SIZE];

void LCS_Mat(){
	freopen("cmlsc.out", "w", stdout);
	int i, j;
	int count = 0;

	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (X[i] == Y[j])
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
			else
				LCS[i][j] = std::max(LCS[i - 1][j], LCS[i][j - 1]);

	for (i = m, j = n; i;)
		if (X[i] == Y[j]){
			Sol[++count] = X[i]; 
			--i; 
			--j;
		}
		
		else if (LCS[i - 1][j]<LCS[i][j - 1])
			j--;
		else
			i--;
	
	std::cout << count << std::endl;
	for (int i = count; i >= 1; i--)
		std::cout << Sol[i] << ' ';
}

int main(){
	FILE *in = freopen("cmlsc.in", "r", stdin);
	fscanf(in, "%d %d", &m, &n);

	for (int i = 1; i <=m; i++)
		std::cin >> X[i];
	for (int j = 1; j <=n; j++)
		std::cin >> Y[j];

	LCS_Mat();

	return 0;
}


