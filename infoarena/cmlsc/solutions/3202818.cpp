 //#include <iostream>
#include <stack>
#define MAX 1024
#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int x[MAX + 1][MAX + 1];
int a[MAX + 1], b[MAX + 1];
int main()
{
	int	n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int j = 0; j < m; j++)
		cin >> b[j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i - 1] != b[j - 1])
				x[i][j] = max(x[i - 1][j], x[i][j - 1]);
			else
				x[i][j] = x[i - 1][j - 1] + 1;

	int i = n, j = m;
	cout << x[n][m] << '\n';
	stack<int>q;
	while (i && j)
	{
		if (a[i-1] == b[j-1])
			q.push(a[i-1]), i--, j--;
		else if (x[i][j - 1] > x[i - 1][j])
			j--;
		else
			i--;
	}
	while (!q.empty())
		cout << q.top() << ' ', q.pop();
	return 0;
}