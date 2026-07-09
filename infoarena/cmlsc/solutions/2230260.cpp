#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define IntPairArray vector<pair<int, int>>
#define IntArray vector<int>
#define MultiHashMap multimap<int, int>
#define IntPair pair<int, int>

class SegmentTree {
public:
	SegmentTree(int dim) {
		this->dim = dim;
		container = IntPairArray(4 * dim);
	}

	IntPair query(int l, int r) {
		return query(1, 1, dim, l, r);
	}

	void update(int l, int r, IntPair val) {
		update(1, 1, dim, l, r, val);
	}

	IntPair top() {
		return container[1];
	}

private:
	IntPair query(int node, int a, int b, int l, int r) {
		if (a > r || b < l) return { 0, 0 };
		if (a >= l && b <= r) return container[node];
		int mid = (a + b) / 2;
		return max(query(node * 2, a, mid, l, r), query(node * 2 + 1, mid + 1, b, l, r));
	}

	void update(int node, int a, int b, int l, int r, IntPair val) {
		if (a > r || b < l) return;
		if (a >= l && b <= r) {
			container[node] = val;
			return;
		}
		int mid = (a + b) / 2;
		update(node * 2, a, mid, l, r, val);
		update(node * 2 + 1, mid + 1, b, l, r, val);
		container[node] = (container[node * 2].first >= container[node * 2 + 1].first) ? 
			container[node * 2] : container[node * 2 + 1];
	}

	IntPairArray container;
	int dim;
};

IntArray lcs(IntArray a, IntArray b) {
	SegmentTree sTree = SegmentTree(a.size());
	MultiHashMap hashMap = MultiHashMap();
	for (int i = 0; i < (int)a.size(); ++i) {
		hashMap.insert(IntPair(a[i], i + 1));
	}

	IntPairArray prevPos = IntPairArray(b.size(), { -1, -1 });
	for (int i = 0; i < (int)b.size(); ++i) {
		pair<MultiHashMap::iterator, MultiHashMap::iterator> ret = hashMap.equal_range(b[i]);
		IntArray positions;
		for (MultiHashMap::iterator it = ret.first; it != ret.second; ++it) {
			positions.push_back(it->second);
		}
		IntPair mMax = { -1, -1 };
		for (int j = positions.size() - 1; j >= 0; --j) {
			int pos = positions[j];
			IntPair currMax = sTree.query(1, pos - 1);
			mMax = (mMax.first < currMax.first) ? currMax : mMax;
			sTree.update(pos, pos, {currMax.first + 1, i});
		}
		prevPos[i] = { mMax.first + 1, mMax.second };
	}
	int it = sTree.top().second;
	IntArray ans;
	do {
		ans.push_back(b[it]);
		it = prevPos[it].second;
	} while (prevPos[it].first!=1);
	ans.push_back(b[it]);
	return ans;
}

int main() {
	int n, m;
	fin >> n >> m;
	IntArray a(n), b(m);
	for (int i = 0; i < n; ++i) {
		fin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		fin >> b[i];
	}
	IntArray ans = lcs(a, b);
	fout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; --i) {
		fout << ans[i] << " ";
	}
	return 0;
}