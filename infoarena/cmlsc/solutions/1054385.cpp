#include <fstream>
#include <vector>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out("cmlsc.out");

int d[1025][1025];
int main()
{
	int n, m;
	in >> n >> m;

	int x[1025];
	int y[1025];
	for (int i = 1; i <= n; ++i)
		in >> x[i], d[i - 1][0] = 0;

	for (int i = 1; i <= m; ++i)
		in >> y[i], d[0][i - 1] = 0;

	vector <int> p;
	for (int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(x[i] == y[j]) 
				d[i][j] = d[i - 1][j - 1] + 1, p.push_back(i);
			else 
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);

	out << d[n][m] << "\n";
	for (vector<int>::iterator i = p.begin(); i != p.end(); ++i)
		out << x[*i] << " ";

	in .close();
	out.close();

	return 0;
}