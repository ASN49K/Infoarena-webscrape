#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1025][1025];
int main()
{
	int n, m;
	int x[1025], y[1025];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int j = 1; j <= m; j++)
		cin >> y[j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (x[i] == y[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
	int l = a[n][m];
	int i = n,j = m;
	vector<int>sol;
	while (i >= 0 && j >= 0 && l)
	{
		if (x[i] == y[j])
			sol.push_back(x[i]), i--, j--, l--;
		else if (a[i - 1][j] > a[i][j - 1])
			i--;
		else
			j--;
	}
	cout << a[n][m]<< '\n';
	for (int i = a[n][m] - 1; i >= 0; i--)
		cout << sol[i] << ' ';
	return 0;
}