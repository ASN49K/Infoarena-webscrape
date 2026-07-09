#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void readvector(vector<int> &v, int n) {
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
}

void LCS(vector<int> &res, vector<int> v, vector<int> w) {
	if (!v.size() || !w.size())
		return;
	if (v[v.size() - 1] == w[w.size() - 1]) {
		res.push_back(v[v.size() - 1]);
		v.pop_back();
		w.pop_back();
		LCS(res, v, w);
		return;
	}
	vector<int> tmp1,tmp2;
	tmp1.reserve(v.size() > w.size() ? w.size() : v.size());
	tmp2.reserve(v.size() > w.size() ? w.size() : v.size());
	tmp1 = res;
	tmp2 = res;
	vector<int> v2(v.begin(), v.end() - 1);
	vector<int> w2(w.begin(), w.end() - 1);
	LCS(tmp1, v2, w);
	LCS(tmp2, v, w2);
	res = (tmp1.size() > tmp2.size() ? tmp1 : tmp2);
}
int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	vector<int> v, w, res;
	v.reserve(m);
	w.reserve(n);
	res.reserve(m > n ? n : m);
	readvector(v, m);
	readvector(w, n);
	LCS(res, v, w);
	printf("%d\n", res.size());
	for (int i = res.size() - 1; i >= 0; --i)
		printf("%d ", res[i]);
	printf("\n");
}