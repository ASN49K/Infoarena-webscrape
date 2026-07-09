#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
vector< vector<pii> > p;
int r[100000];

bool lt(const vector<pii> &a, const vector<pii> &b) {
	if (a.empty()) return true;
	if (b.empty()) return false;
	return a.back().first < b.back().first;
}

int main(int argc, char *argv[]) {
	FILE *fi = fopen("scmax.in", "r");
	int N;
	fscanf(fi, "%d", &N);
	p.push_back(vector<pii>());
	int pn = 1, a;
	while (N--) {
		fscanf(fi, "%d", &a);
		vector<pii> vk(1, make_pair(a, 0));
		int pi = lower_bound(p.begin(), p.end(), vk, lt) - p.begin();
		if (pi == pn) {
			p.push_back(vector<pii>());
			++pn;
		}
		p[pi].push_back(make_pair(a, p[pi-1].size() - 1));
	}
	fclose(fi);

	int prev = p[p.size()-1].size()-1;
	for (int i = p.size() - 1; i > 0; --i) {
		r[i-1] = p[i][prev].first;
		prev = p[i][prev].second;
	}

	FILE *fo = fopen("scmax.out", "w");
	fprintf(fo, "%d\n", (int)p.size()-1);
	for (int i = 0; i < (int)p.size()-1; ++i)
		fprintf(fo, "%d ", r[i]);
	fprintf(fo, "\n");
	fclose(fo);

	return 0;
}

