#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX 1050

using namespace std;

int n, m, maxGs, pi, pj;
int a[MAX], b[MAX];
int sol[MAX][MAX];
vector <int> vctSol;

int main() {
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= m; i++)
		cin >> b[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			sol[i][j] = (a[i] == b[j])? sol[i - 1][j - 1] + 1 : max(sol[i - 1][j], sol[i][j - 1]);

			if (sol[i][j] > maxGs)
				maxGs = sol[i][j], pi = i, pj = j;
		}

	for (; pi && pj; ) {
		if (sol[pi][pj] == sol[pi - 1][pj - 1] + 1)
			vctSol.push_back(a[pi]), pi--, pj--;
		else if (sol[pi][pj] == sol[pi - 1][pj])
			pi--;
		else pj--;
	}

	reverse(vctSol.begin(), vctSol.end());

	cout << vctSol.size() << "\n";

	for (int i = 0; i < vctSol.size(); i++)
		cout << vctSol[i] << " ";

	return 0;
}

