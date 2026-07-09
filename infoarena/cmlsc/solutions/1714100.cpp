//#include <cstring>
#include <iostream>
//#include <algorithm>

/*#define pb push_back
#define f first
#define s second
#define pii pair<int, int>
#define mp make_pair
 
using namespace std;
 
const string name = "euro2",
             in_file = name + ".in",
             out_file = name + ".out";
 
const int MAX = 1e4 + 1;*/

//int norma[MAX];
//int aib[MAX];
//pii v[MAX];
//int n;

/*int lsb(int x) {
	return x & (-x);
}

void update(int poz, int val) {
	for (int i = poz; i < MAX; i += lsb(i)) 
		aib[i] = max(aib[i], val);
}

int query(int poz) {
	int maxx = 0;
	for (int i = poz; i > 0; i -= lsb(i))
		maxx = max(aib[i], maxx);
	return maxx;
}
*/

int main() {
	freopen("euro2.in", "r", stdin);
	freopen("euro2.out", "w", stdout);
	/*cin >> n;
	return 0;
	for (int i = 1; i <= n; i++) {
		double nr;
		cin >> nr;
		nr *= 10000;
		v[i].f = (int) nr;
		v[i].s = i;
	}

	sort(v + 1, v + n + 1);

	for (int i = 1; i <= n; i++) 
		norma[v[i].s] = (v[i].f == v[i - 1].f ? norma[v[i - 1].s] : i);

	for (int i = 1; i <= n; i++) {
		int scm = query(norma[i] - 1);
		update(norma[i], scm + 1);

		if (scm == 0)
			v[i].f = -1;
		else v[i].f = scm;
	}

	memset(aib, 0, sizeof(aib));

	for (int i = n; i > 0; i--) {
		int scm = query(norma[i] - 1);
		update(norma[i], scm + 1);
		if (scm < 1 || v[i].f == -1)
			continue;

		if (v[i].f == 1) {
			if (scm >= 2)
				v[i].f += scm;
			else v[i].f = -1;
		} else v[i].f += scm;
		
	}

	int solution = 0;
	for (int i = 1; i <= n; i++) 
		solution = max(solution, v[i].f + 1);

	cout << solution;
	*/
	return 0;
}