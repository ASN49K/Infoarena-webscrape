#include <fstream>
#include <stack>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int x[1025][1025];
int main()
{
	int n, m;
	int a[1025], b[1025];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i - 1] == b[j - 1])
				x[i][j] = x[i - 1][j - 1] + 1;
			else
				x[i][j] = max(x[i - 1][j], x[i][j - 1]);
	int i = n, j = m;
	stack<int>s;
	while (x[i][j] != 0)
	{
		if (a[i - 1] == b[j - 1])
			s.push(a[i - 1]), i--, j--;
		else
			if (x[i - 1][j] < x[i][j - 1])
				j--;
			else
				i--;
	}
	cout << s.size() << '\n';
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}