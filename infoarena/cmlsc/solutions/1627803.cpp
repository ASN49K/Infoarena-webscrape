#include <fstream>
#include <stack>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025], b[1025], lung[1025][1025], ant[1025], n, m;

int main()
{
	int i, j;
	f >> n >> m;
	for (i = 1; i <= n; i++) f >> a[i];
	for (i = 1; i <= m; i++) f >> b[i];

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) {
			ant[i] = ant[i - 1];
			if (a[i] == b[j]) {
				lung[i][j] = 1 + lung[i - 1][j - 1];
				ant[j] = i;
			}
			else lung[i][j] = max(lung[i - 1][j], lung[i][j - 1]);
		}
	g << lung[n][m] << "\n";

	stack<int> s;
	i = m;
	while (i != ant[i]) {
		s.push(a[ant[i]]);
		i = ant[i];
	}
	while (!s.empty()) g << s.top() << " ", s.pop();
	g << "\n";

	return 0;
}
