#include <fstream>
#include <vector>

using std::vector;
using std::ifstream;
using std::ofstream;

int main()
{
	ifstream in ("cmlsc.in");
	ofstream out("cmlsc.out");

	int m, n;
	vector <int> x, y;

	if(in && !in.eof() && in >> m >> n)
	{
		int i, t;
		for(i = 0; in && i < m && in >> t; ++i)	x.push_back(t);
		for(i = 0; in && i < n && in >> t; ++i)	y.push_back(t);
	}

	vector< vector<int> >c(m+1, vector<int>(n+1, 0));

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(x[i-1] == y[j-1])
			{
				c[i][j] = c[i-1][j-1]+1;
				continue;
			}
			if(c[i-1][j] >= c[i][j-1]) c[i][j] = c[i-1][j];
			else c[i][j] = c[i][j-1];
		}
	}

	int l1 = m, cc = n;
	vector <int> v;
	while(l1 || cc)
	{
		if(l1 && cc && x[l1-1] == y[cc-1])
		{
			v.push_back(x[l1-1]);
			--l1; --cc;
			continue;
		}
		if(l1 && c[l1][cc] == c[l1-1][cc])
		{
			--l1;
			continue;
		}
		if(cc && c[l1][cc] == c[l1][cc-1]) cc--;
	}

	out << c[m][n] << std::endl;
	vector<int>::reverse_iterator rIt;
	for(rIt = v.rbegin(); rIt != v.rend(); ++rIt)
		out << *rIt << " ";
}