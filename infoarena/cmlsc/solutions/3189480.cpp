#include <fstream>
#include <vector>

#define n_max 1025

using namespace std;

int n, m, k, a[n_max], b[n_max], cmlsc[n_max];
int mat[n_max][n_max];
vector<int> rez;

int main()
{
	ifstream in("cmlsc.in");
	in >> n >> m;

	for (int i = 1; i <= n; i++)
		in >> a[i];
	for (int i = 1; i <= m; i++)
		in >> b[i];
	in.close();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] == b[j])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
	
	for (int i = n, j = m; i && j;)
		if (a[i] == b[j])
		{
			cmlsc[k++] = a[i];
			i--;
			j--;
		}
		else if (mat[i - 1][j] < mat[i][j - 1])
			j--;
		else
			i--;
	
	ofstream out("cmlsc.out");
	out << k << '\n';
	for (int i = 0; i < k; i++)
		out << cmlsc[i] << ' ';
	out.close();

	return 0;
}