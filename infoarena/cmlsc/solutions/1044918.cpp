#include <vector>
#include <fstream>

using namespace std;

vector<int> lcs(vector<int> &x, vector<int> &y)
{
	vector<int> sol;
	vector<int> a, b;

	if (x.size() == 0 || y.size() == 0)
	{
		sol.clear();
		return sol;
	}

	else if (x[x.size() - 1] == y[y.size() - 1])
	{
		sol = lcs(lcs(vector<int>(x.begin(), x.end() - 1), vector<int>(y.begin(), y.end() - 1)), x);
		sol.push_back(x[x.size() - 1]);
		return sol;
	}

	else if (x[x.size() - 1] != y[y.size() - 1])
	{
		a = lcs(x, vector<int>(y.begin(), y.end() - 1)); 
		b = lcs(vector<int>(x.begin(), x.end() - 1), y);
		
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

	vector<int> x, y, sol;

	for (int i = 0; i < n; i++)
	{
		int a; IN >> a;
		x.push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		int b; IN >> b;
		y.push_back(b);
	}

	sol = lcs(x, y);

	OUT << sol.size() << endl;

	for (vector<int>::const_iterator iter = sol.begin(); iter != sol.end(); iter++)
		OUT << *iter << " ";

	OUT << endl;

	return 0;
}