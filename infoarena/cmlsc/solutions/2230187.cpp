#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define IntArray vector<int>
#define MultiHashMap multimap<int, int>
#define IntPair pair<int, int>
#define IntTuple tuple<int, int, int>

class SegmentTree {
public:
	SegmentTree(int dim) {
		this->dim = dim;
		container = IntArray(4 * dim, 0);
	}

	int query(int l, int r) {
		return query(1, 1, dim, l, r);
	}

	void update(int l, int r, int val) {
		update(1, 1, dim, l, r, val);
	}

	int top() {
		return container[1];
	}

private:
	int query(int node, int a, int b, int l, int r) {
		if (a > r || b < l) return 0;
		if (a >= l && b <= r) return container[node]; 
		int mid = (a + b) / 2;
		return max(query(node * 2, a, mid, l, r), query(node * 2 + 1, mid + 1, b, l, r));
	}

	void update(int node, int a, int b, int l, int r, int val) {
		if (a > r || b < l) return;
		if (a >= l && b <= r) {
			container[node] = val;
			return;
		}
		int mid = (a + b) / 2;
		update(node * 2, a, mid, l, r, val);
		update(node * 2 + 1, mid + 1, b, l, r, val);
		container[node] = max(container[node * 2], container[node * 2 + 1]);
	}

	IntArray container;
	int dim;
};

int lcs(IntArray a, IntArray b) {
	SegmentTree sTree = SegmentTree(a.size());
	MultiHashMap hashMap = MultiHashMap();
	for (int i = 0; i < (int) a.size(); ++i) {
		hashMap.insert(IntPair(a[i], i + 1));
	}
	
	for (int i = 0; i < (int) b.size(); ++i) {
		pair<MultiHashMap::iterator, MultiHashMap::iterator> ret = hashMap.equal_range(b[i]); 
		IntArray positions;
		for (MultiHashMap::iterator it = ret.first; it != ret.second; ++it) {
			positions.push_back(it->second);
		}
		for (int i = positions.size() - 1; i >=0; --i){
			int pos = positions[i];
			int currMax = sTree.query(1, pos - 1);  
			sTree.update(pos, pos, currMax + 1);
		}
	}
	return sTree.top();
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
	fout << lcs(a, b);
	/*fout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		fout << ans[i] << " ";
	}*/
    return 0;
}

