#define MAX_N 100000

#include <fstream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

ifstream fin("paths.in");
ofstream fout("paths.out");

int n, k, C[MAX_N + 1];
vector<int> leaves;
vector<tuple<int, int>> G[MAX_N + 1];

int dfs(int node, int papa)
{
	int max_leaf = node;
	for (int i = 0; i < (int) G[node].size(); ++i)
	{
		if (get<0>(G[node][i]) != papa)
		{
			const int child_max_leaf = dfs(get<0>(G[node][i]), node);
			C[child_max_leaf] += get<1>(G[node][i]);
			if (C[max_leaf] < C[child_max_leaf])
				max_leaf = child_max_leaf;
		}
	}
	return max_leaf;
}

int main()
{
	fin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		int x, y, c;
		fin >> x >> y >> c;
		G[x].emplace_back(y, c);
		G[y].emplace_back(x, c);
	}
	for (int i = 1; i <= n; ++i)
		if (G[i].size() == 1)
			leaves.push_back(i);	
	for (int i = 1; i <= n; ++i)
	{
		dfs(i, 0);
		sort(leaves.begin(), leaves.end(), [](int a, int b) { return C[a] > C[b]; });
		int result = 0;
		for (int j = 0; (j < k) && (j < (int) leaves.size()); ++j)
			result += C[leaves[j]];
		fout << result << '\n';
		for (const int leaf : leaves)
			C[leaf] = 0;
	}
    fin.close();
    fout.close();
    return 0;
}
