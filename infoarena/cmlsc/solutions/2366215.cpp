#include <fstream>
#define LGMAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[LGMAX], B[LGMAX], lg[LGMAX][LGMAX], caz[LGMAX][LGMAX];
int n, m;

int main()
{
	int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i ++)
    	fin >> A[i];
	for (i = 1; i <= m; i ++)
		fin >> B[i];
	for (i = n; i >= 1; i --)
		for (j = m; j >= 1; j --)
		{
			if (A[i] == B[j])
			{
				lg[i][j] = lg[i + 1][j + 1] + 1;
				caz[i][j] = 1;
			}
			else
			{
				caz[i][j] = 2;
				lg[i][j] = lg[i + 1][j + 1];
				if (lg[i + 1][j] > lg[i][j])
				{
					lg[i][j] = lg[i + 1][j];
					caz[i][j] = 3;
				}
				if (lg[i][j + 1] > lg[i][j])
				{
					lg[i][j] = lg[i][j + 1];
					caz[i][j] = 4;
				}
			}
		}
	fout << lg[1][1] << '\n';
	for (i = 1; i <= n; i ++)
		for (j = 1; j <= m; j ++)
			if (caz[i][j] == 1)
				fout << A[i] << ' ';
    return 0;
}
