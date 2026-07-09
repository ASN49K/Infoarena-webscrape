#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");





int main() {
	int as, bs;
	f >> as >> bs;
	vector<int> a(as);
	vector<int> b(bs);
	for (int i = 0; i < as; i++)
		f >> a[i];
	for (int i = 0; i < bs; i++)
		f >> b[i];
	vector< vector<int> > lcss(bs + 1);

	lcss[0].resize(as + 1);
	for (size_t ib = 1; ib <= bs; ib++) {
		lcss[ib].resize(as + 1);
		for (size_t ia = 1; ia <= as; ia++){
			if (b[ib - 1] == a[ia - 1])
				lcss[ib][ia] = lcss[ib - 1][ia - 1] + 1;
			else lcss[ib][ia] = max(lcss[ib - 1][ia], lcss[ib][ia - 1]);
		}
	}
	int nr = lcss[bs][as];
	vector<int> res(nr);
	g << nr << endl;
	int ib = bs; int ia = as;
	while (nr) {

		if (a[ia - 1] == b[ib - 1]) {
			res[nr - 1] = a[ia - 1];
			nr--;
			ib--; ia--;
		}
		else if (lcss[ib - 1][ia] > lcss[ib][ia - 1])
			ib--;
		else ia--;
	}

	for (int v : res)
		g << v << " ";

}