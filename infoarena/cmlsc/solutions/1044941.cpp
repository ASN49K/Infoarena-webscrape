#include <vector>
#include <fstream>

using namespace std;

vector<int> lcs(int *x, int i, int *y, int j)
{
	vector<int> sol;
	vector<int> a, b;

	if (i == -1 || j == -1)
	{
		sol.clear();
		return sol;
	}

	else if (x[i] == y[j])
	{
		sol = lcs(x, i - 1, y, j - 1);
		sol.push_back(x[i]);
		return sol;
	}

	else if (x[i] != y[j])
	{
		a = lcs(x, i, y, j - 1); 
		b = lcs(x, i - 1, y, j);
		
		if (a.size() > b.size())
			sol = a;
		else
			sol = b;

		return sol;
	}

}

int main()
{
	ifstream IN("cmlsc.in");
	ofstream OUT("cmlsc.out");

	int n, m;

	IN >> n >> m;

	vector<int> sol;

	int x[1024], y[1024];

	for (int i = 0; i < n; i++)
	{
		IN >> x[i];
	}

	for (int i = 0; i < m; i++)
	{
		IN >> y[i];
	}

	sol = lcs(x, n - 1, y, m - 1);

	OUT << sol.size() << endl;

	for (vector<int>::const_iterator iter = sol.begin(); iter != sol.end(); iter++)
		OUT << *iter << " ";

	OUT << endl;

	return 0;
}