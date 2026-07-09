#include <fstream>

#define Max 1024

using namespace std;

int main()
{
	int sirA[Max], sirB[Max], solutie[Max];
	int mat[Max][Max];
	int lung_A, lung_B, lung_MAX;
	int X, Y, i, j;

	ifstream inFILE("cmlsc.in");
	ofstream outFILE("cmlsc.out");

	inFILE >> lung_A >> lung_B;

	for (i = 1; i <= lung_A; i++)
	{
		inFILE >> sirA[i];
	}

	for (j = 1; j <= lung_B; j++)
	{
		inFILE >> sirB[j];
	}

	for (i = 1; i <= lung_A; i++)
	{
		for (j = 1; j <= lung_B; j++)
		{
			if (sirA[i] == sirB[j])
				mat[i][j] = mat[i-1][j-1] + 1;
			else
				mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
		}
	}

	for (i = lung_A, j = lung_B; i; )
	{
		if (sirA[i] == sirB[j])
		{
			solutie[++lung_MAX] = sirA[i];
			--i;
			--j;
		}
		else
			if (mat[i-1][j] < mat[i][j-1])
				--j;
			else
				--i;
	}

	outFILE << lung_MAX;

	for (i = lung_MAX; i; --i)
		outFILE << solutie[i];

	// system("pause");
	return 0;
}