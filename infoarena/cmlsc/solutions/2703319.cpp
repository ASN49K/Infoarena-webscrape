#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

short int n, m, a[1025], b[1025], c[1025];

void citire() {
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= m; i++)
		cin >> b[i];
}

int caut(int x) {
	for (int i = 1; i <= m; i++)
		if (x == b[i])
			return i;

	return -1;
}

void rezolva() {
	for (int i = 1; i <= n; i++)
		c[i] = caut(a[i]);

	int p = n;

	while (c[p] == -1 && p > 0)
		--p;

	int l[101];

	l[p] = 1;

	for (int i = p - 1; i >= 1; i--) {
		if (c[i] != -1) {

			int maxim = -1;

			for (int j = i + 1; j <= n; j++)
				if (c[j] != -1 && l[j] > maxim && c[j] > c[i]) {
					maxim = l[j];
				}

			l[i] = 1 + maxim;
		}
	}

	int maxim = 0;

	for (int i = 1; i <= n; i++)
		if (l[i] > maxim) {
			maxim = l[i];
			p = i;
		}

	cout << maxim << '\n';

	cout << a[p] << ' ';
	for (int i=p+1;i<=n;i++)
		if (c[i] != -1 && l[i] == maxim - 1) {
			cout << a[i] << ' ';
			maxim--;
		}
}

int main() {
	citire();
	rezolva();

	cin.close();
	cout.close();
	return 0;
}