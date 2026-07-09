#define MAX_N 100000
 
#include <fstream>
#include <cstdint>
#include <tuple>
#include <vector>
#include <set>
#include <queue>
#include <stack>
using namespace std;
 
ifstream fin("paths.in");
ofstream fout("paths.out");
 
int n, k, L[MAX_N + 1];
int64_t C[MAX_N + 1], R[MAX_N + 1];
vector<tuple<int, int, int, int>> G[MAX_N + 1];
bool CompareFunction(int a, int b) 
{ 
	if  (C[a] == C[b])
		return a > b;
	return C[a] > C[b];
}
multiset<int, decltype(CompareFunction)*> S(CompareFunction);
 
int dfs(int node)
{
	int max_leaf = (G[node].size() == 1) ? node : 0;
	for (int i = node != 1; i < (int) G[node].size(); ++i)
	{
		const int child_max_leaf = get<2>(G[node][i]) = dfs(get<0>(G[node][i]));
		C[child_max_leaf] += get<1>(G[node][i]);
		if (CompareFunction(child_max_leaf, max_leaf))
			max_leaf = child_max_leaf;
	}
	stack<int> max_right;
	for (int i = G[node].size() - 1; i > (node != 1); --i)
	{
		if (max_right.empty())
			max_right.push(get<2>(G[node][i]));
		else
			max_right.push(CompareFunction(max_right.top(), get<2>(G[node][i])) ? max_right.top() : get<2>(G[node][i]));
	}
	int max_left = (G[node].size() == 1) ? node : 0;
	for (int i = node != 1; i < (int) G[node].size(); ++i, max_right.pop())
	{
		const int max_left_right = (max_right.empty() || CompareFunction(max_left, max_right.top())) ? max_left : max_right.top();
		if (CompareFunction(get<2>(G[node][i]), max_left))
			max_left = get<2>(G[node][i]);
		get<3>(G[node][i]) = max_left_right;
	}
	return max_leaf;
}
 
void solve(int node, int nonnode_max_leaf = 0)
{
	{
		int index = 0;
		for (const int leaf : S)
		{
			R[node] += C[leaf];
			if ((++index) == k)
				break;
		}
	}
	for (int i = node != 1; i < (int) G[node].size(); ++i)
	{
		const int child_node = get<0>(G[node][i]),
				  cost = get<1>(G[node][i]),
				  child_max_leaf = get<2>(G[node][i]),
				  nonchild_max_leaf = CompareFunction(nonnode_max_leaf, get<3>(G[node][i])) ? nonnode_max_leaf : get<3>(G[node][i]);
		for (const int leaf : { child_max_leaf, nonchild_max_leaf })
			S.erase(leaf);
		C[child_max_leaf] -= cost;
		C[nonchild_max_leaf] += cost;
		for (const int leaf : { child_max_leaf, nonchild_max_leaf })
			S.insert(leaf);
		solve(child_node, nonchild_max_leaf);
		for (const int leaf : { child_max_leaf, nonchild_max_leaf })
			S.erase(leaf);
		C[child_max_leaf] += cost;
		C[nonchild_max_leaf] -= cost;
		for (const int leaf : { child_max_leaf, nonchild_max_leaf })
			S.insert(leaf);
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
	{
		vector<int> leaves;
		{
			queue<tuple<int, int>> Q;
			Q.emplace(0, 1);
			while (!Q.empty())
			{
				const int papa = get<0>(Q.front());
				const int node = get<1>(Q.front());
				Q.pop();
				if (G[node].size() == 1)
					leaves.push_back(node);
				for (int i = 0; i < (int) G[node].size(); ++i)
				{
					const int next_node = get<0>(G[node][i]);
					if (next_node == papa)
						swap(G[node][0], G[node][i]);
					else
						Q.emplace(node, next_node);
				}
			}
		}
		dfs(1);
		for (const int leaf : leaves)
			S.insert(leaf);
		solve(1);
	}
	for (int i = 1; i <= n; ++i)
		fout << R[i] << '\n';
	fin.close();
	fout.close();
	return 0;
}
