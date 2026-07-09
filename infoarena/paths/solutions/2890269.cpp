#define MAX_N 100000

#include <fstream>
#include <cstdint>
#include <tuple>
#include <vector>
#include <set>
using namespace std;

ifstream fin("paths.in");
ofstream fout("paths.out");

int n, k;
int64_t r, C[MAX_N + 1], R[MAX_N + 1];
vector<int> leaves;
vector<tuple<int, int, int, int>> G[MAX_N + 1];
bool CompareFunction(int a, int b)
{
	if (C[a] == C[b])
		return a > b;
	return C[a] > C[b];
}
set<int, decltype(CompareFunction)*> S[2] =
{
	set<int, decltype(CompareFunction)*>(CompareFunction),
	set<int, decltype(CompareFunction)*>(CompareFunction)
};

int dfs(int node, int papa = 0)
{
	int max_leaf = node, previous_max_leaf;
	for (int i = 0; i < (int) G[node].size(); ++i)
		if (get<0>(G[node][i]) != papa)
		{
			get<2>(G[node][i]) = dfs(get<0>(G[node][i]), node);
			C[get<2>(G[node][i])] += get<1>(G[node][i]);
			if (C[max_leaf] < C[get<2>(G[node][i])])
			{
				previous_max_leaf = max_leaf;
				max_leaf = get<2>(G[node][i]);
			}
			else if (C[previous_max_leaf] < C[get<2>(G[node][i])])
				previous_max_leaf = get<2>(G[node][i]);
		}
	for (int i = 0; i < (int) G[node].size(); ++i)
		if (get<0>(G[node][i]) != papa)
			get<3>(G[node][i]) = (get<2>(G[node][i]) == max_leaf) ? ((G[node].size() == 2) ? 0 : previous_max_leaf) : max_leaf;
	return max_leaf;
}

void update_leaf(int leaf, int value)
{
	if (S[0].erase(leaf))
		r -= C[leaf];
	else
		S[1].erase(leaf);
	C[leaf] = value;
	S[1].insert(leaf);
	if ((int) S[0].size() < k)
	{
		r += C[*S[1].begin()];
		S[0].insert(*S[1].begin());
		S[1].erase(S[1].begin());
	}
	else if (CompareFunction(*S[1].begin(), *S[0].rbegin()))
	{
		r += C[*S[1].begin()];
		S[0].insert(*S[1].begin());
		S[1].insert(*S[0].rbegin());
		r -= C[*S[0].rbegin()];
		S[0].erase(*S[0].rbegin());
		S[1].erase(S[1].begin());
	}
}

void solve(int node, int nonnode_max_leaf = 0, int papa = 0)
{
	R[node] = r;
	for (int i = 0; i < (int) G[node].size(); ++i)
		if (get<0>(G[node][i]) != papa)
		{
			const int child = get<0>(G[node][i]),
					  cost = get<1>(G[node][i]),
					  child_max_leaf = get<2>(G[node][i]),
					  nonchild_max_leaf = (C[nonnode_max_leaf] > C[get<3>(G[node][i])]) ? nonnode_max_leaf : get<3>(G[node][i]);
			update_leaf(child_max_leaf, C[child_max_leaf] - cost);
			update_leaf(nonchild_max_leaf, C[nonchild_max_leaf] + cost);
			solve(child, nonchild_max_leaf, node);
			update_leaf(child_max_leaf, C[child_max_leaf] + cost);
			update_leaf(nonchild_max_leaf, C[nonchild_max_leaf] - cost);
		}
}

int main()
{
	fin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		int x, y, c;
		fin >> x >> y >> c;
		G[x].emplace_back(y, c, 0, 0);
		G[y].emplace_back(x, c, 0, 0);
	}
	for (int node = 1; node <= n; ++node)
		if (G[node].size() == 1)
			leaves.push_back(node);
	dfs(1);
	for (int leaf : leaves)
		S[1].insert(leaf);
	while (!S[1].empty() && ((int) S[0].size() < k))
	{
		S[0].insert(*S[1].begin());
		r += C[*S[1].begin()];
		S[1].erase(S[1].begin());
	}
	solve(1);
	for (int i = 1; i <= n; ++i)
		fout << R[i] << '\n';
    fin.close();
    fout.close();
    return 0;
}
