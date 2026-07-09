// un mic brut
#include <bits/stdc++.h>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
 
#ifdef LOCAL
	ifstream fin("input.txt");
	ofstream fout("output.txt");
#else
	#define fin cin
	#define fout cout
#endif
 
const int INF = 1e9;
const int NMAX = 2000;
 
int N, K;
vector<pair<int, int>> adj[NMAX + 1];
int nodeList[NMAX + 1], first[NMAX + 1], last[NMAX + 1], parent[NMAX + 1], w[NMAX + 1];
long long sumW[NMAX + 1];
bool visited[NMAX + 1];
 
void dfs(int u = 1, int v = -1) {
	nodeList[0]++;
	nodeList[nodeList[0]] = u;
	first[u] = nodeList[0];
	parent[u] = v;
 
	for(const auto &it: adj[u]) {
		if(it.first != v) {
			w[it.first] = it.second;
			sumW[it.first] += sumW[u] + w[it.first];
			dfs(it.first, u);
		}
	}
 
	last[u] = nodeList[0];
}
 
struct Node {
	long long val;
	int index;
};
Node segTree[4 * NMAX + 1];
long long lazy[4 * NMAX + 1];
 
Node join(const Node &a, const Node &b) {
	if(a.val > b.val) {
		return a;
	}
	return b;
}
 
void build(int node = 1, int left = 1, int right = N) {
	if(left == right) {
		segTree[node] = {sumW[nodeList[left]], left};
		lazy[node] = 0;
	} else {
		int mid = (left + right) >> 1;
 
		build(2 * node, left, mid);
		build(2 * node + 1, mid + 1, right);
 
		segTree[node] = join(segTree[2 * node], segTree[2 * node + 1]);
		lazy[node] = 0;
	}
}
 
void propagate(int node) {
	if(lazy[node]) {
		segTree[2 * node].val += lazy[node];
		segTree[2 * node + 1].val += lazy[node];
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
		lazy[node] = 0;
	}
}
 
void update(int a, int b, int val, int node = 1, int left = 1, int right = N) {
	if(left >= a && right <= b) {
		segTree[node].val += val;
		lazy[node] += val;
	} else {
		int mid = (left + right) >> 1;
 
		propagate(node);
 
		if(a <= mid) {
			update(a, b, val, 2 * node, left, mid);
		}
 
		if(b > mid) {
			update(a, b, val, 2 * node + 1, mid + 1, right);
		}
 
		segTree[node] = join(segTree[2 * node], segTree[2 * node + 1]);
	}
}
 
// Node query(int a, int b, int node = 1, int left = 1, int right = N) {
// 	if(left >= a && right <= b) {
// 		return segTree[node];
// 	} else {
// 		int mid = (left + right) >> 1;
 
// 		propagate(node);
 
// 		Node p = {-INF, INF}, q = {-INF, INF};
 
// 		if(a <= mid) {
// 			p = query(a, b, 2 * node, left, mid);
// 		}
 
// 		if(b > mid) {
// 			q = query(a, b, 2 * node + 1, mid + 1, right);
// 		}
 
// 		return join(p, q);
// 	}
// }

Node query1N() {
	return segTree[1];
}
 
void updateChain(int u) {
	while(u != -1 && !visited[u]) {
		update(first[u], last[u], -w[u]);
		visited[u] = 1;
 
		u = parent[u];
	}
}
 
int main() {
	ios_base :: sync_with_stdio(0); fin.tie(0); fout.tie(0);
	#ifndef LOCAL
		freopen("paths.in", "r", stdin);
		freopen("paths.out", "w", stdout);
	#endif

	fin >> N >> K;

	assert(N <= NMAX);

	for(int i = 1; i < N; i++) {
		int u, v, c;
		fin >> u >> v >> c;
 
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
 
	for(int root = 1; root <= N; root++) {
		nodeList[0] = 0;
		for(int i = 1; i <= N; i++) {
			w[i] = sumW[i] = visited[i] = 0;
		}

		dfs(root);
		build();

		long long sum = 0;

		for(int i = 1; i <= min(N, K); i++) {
			Node ans = query1N();
			int index = ans.index, u = nodeList[index];
			sum += ans.val;

			updateChain(u);
		}

		fout << sum << '\n';
 	}
	return 0;
}