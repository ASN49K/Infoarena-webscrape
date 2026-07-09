#include <fstream>

using namespace std;

int l1, l2, a[1030], b[1030], m[1030][1030], ls, sol[1030];

int main () {
	ifstream fi("cmlsc.in");
	ofstream fo("cmlsc.out");
	fi >> l1 >> l2;
	for (int i = 1; i <= l1; i++)
		fi >> a[i];
	for (int i = 1; i <= l2; i++)
		fi >> b[i];
	for (int i = 1; i <= l1; i++)
		for (int j = 1; j <= l2; j++)
			if (a[i] == b[j])
				m[i][j] = m[i-1][j-1]+1;
			else
				m[i][j] = max(m[i-1][j], m[i][j-1]);
	for (int i = l1, j = l2; i and j;)
		if (a[i] == b[j])
			sol[++ls] = a[i], i--, j--;
		else
			if (m[i-1][j] < m[i][j-1])
				j--;
			else
				i--;
	fo << ls << '\n';
	for (int i = ls; i; i--)
		fo << sol[i] << ' ';
	return 0;
}