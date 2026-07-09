#include <fstream>

#define input "cmlsc.in"
#define output "cmlsc.out"
#define NMAX 1030

using namespace std;

ifstream in(input);
ofstream out(output);

int N, M;
int array1[NMAX], array2[NMAX], dp[NMAX][NMAX], array_fin[NMAX];

int Max(int a, int b)
{
	return a > b ? a : b;
}

void Read_Data()
{
	in >> N >> M;
	for (int i = 1; i <= N; i++)
		in >> array1[i];
	for (int i = 1; i <= M; i++)
		in >> array2[i];
}

void Find_CMSLC()
{
	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= M; j++)
	if (array1[i] == array2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
	else dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
	out << dp[N][M] << "\n";
}

void Find_Array()
{
	int K = 0;
	int i = N, j = M;
	while (i && j)
	{
		if (array1[i] == array2[j])
			array_fin[++K] = array1[i], i--, j--;
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1]) i--;
			else j--;
		}
	}
	for (int p = K; p >= 1; p--)
		out << array_fin[p] << " ";
}

int main()
{
	Read_Data();
	Find_CMSLC();
	Find_Array();
	return 0;
}

