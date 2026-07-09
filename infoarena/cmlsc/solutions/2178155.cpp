#include <bits/stdc++.h>
using namespace std;

int n, m, r, a[1025], b[1025], c[1025][1025], p[1025];

int main()
{
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i][j - 1], c[i - 1][j]);
	int i = n;
	int j = m;
	while (i && j)
		if(a[i] == b[j])
		{
			r++;
			p[r] = a[i];
			i--;
			j--;
		}
		else if (c[i][j - 1] > c[i - 1][j])
			j--;
		else
			i--;
	cout << r << endl;
	for (int i = r; i > 0; --i)
		cout << p[i] << ' ';
	return 0;
}
