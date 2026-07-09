#define MAX_N 100000

#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin("paths.in");
ofstream fout("paths.out");

int n, k, I[MAX_N + 1], L[MAX_N + 1], C[MAX_N + 1], R[MAX_N + 1];
struct { int cost = 0, count = 0; } A[MAX_N + 1];
tuple<int, int> T[MAX_N + 1];
vector<tuple<int, int>> G[MAX_N + 1];
vector<int> leaves;

void dfs(int node)
{
	if ((G[node].size() == 1) && (node != 1))
	{
		leaves.push_back(node);
	}
	else
	{
		for (const auto& edge : G[node])
		{	
			if (get<0>(edge) != get<0>(T[node]))
			{
				T[get<0>(edge)] = make_tuple(node, get<1>(edge));
				dfs(get<0>(edge));
			}
		}
	}
}

void ascend()
{
	queue<int> Q;
	for (int leaf : leaves)
	{
		Q.push(leaf);
		L[leaf] = leaf;
	}
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		do
		{
			int papa = get<0>(T[node]);
			int cost_papa = get<1>(T[node]);
			if (!L[papa] && (G[papa].size() > 2))
			{
				Q.push(papa);
			}
			C[L[node]] += cost_papa;
			if (!L[papa] || (C[L[papa]] < C[L[node]]))
			{
				L[papa] = L[node];
			}
			node = papa;
		} while (G[node].size() == 2);
	}
	sort(leaves.begin(), leaves.end(), [](int a, int b) { return C[a] > C[b]; });
	for (int i = 0; (i < k) && (i < (int) leaves.size()); ++i)
	{
		I[leaves[i]] = i;
		R[1] += C[leaves[i]];
		A[leaves[i]].count = 1;
		Q.push(leaves[i]);
	}
	for (int i = 0; i < (int) leaves.size(); ++i)
	{
		leaves[i] = C[leaves[i]];
		if (i > 0)
		{
			leaves[i] += leaves[i - 1];
		}
	}
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		do
		{
			int papa = get<0>(T[node]);
			int papa_cost = get<1>(T[node]);
			if (A[papa].count == 0)
			{
				Q.push(papa);
			}
			A[papa].cost += A[node].cost + papa_cost;
			A[papa].count += A[node].count;
			node = papa;
		} while (G[node].size() == 2);
	}
}

void fill(int node)
{
	R[node] = R[get<0>(T[node])] + get<1>(T[node]);
	for (const auto& edge : G[node])
	{
		if (get<0>(edge) != get<0>(T[node]))
		{
			fill(get<0>(edge));
		}
	}
}

void solve(int papa)
{
	for (const auto& edge : G[papa])
	{
		if (get<0>(edge) != get<0>(T[papa]))
		{
			int node = get<0>(edge);
			int papa_cost = get<1>(edge);
			
			if (G[node].size() == 1)
			{
				R[node] = R[papa];
				if (I[node] < k)
				{
					if (k < (int) leaves.size())
					{
						R[node] += leaves[k] - leaves[k - 1];
					}
				}
				else
				{
					R[node] += papa_cost;
				}
			}
			else
			{
				if (A[node].cost == 0)
				{
					fill(node);
				}
				else
				{
					int r = R[papa] - A[node].cost + leaves[min(k - 1 + A[node].count, (int) leaves.size() - 1)] - leaves[min(k - 1, (int) leaves.size() - 1)];
					R[node] = R[papa] - ((A[node].count == A[1].count) ? papa_cost : 0);
					if (r > R[node])
					{
						R[node] = r;
						for (const auto& edge : G[node])
						{
							fill(get<0>(edge));
						}
					}
					else
					{
						solve(node);
					}
				}
			}
		}
	}
}

int main()
{	
	fin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		I[i] = k;
		int x, y, c;
		fin >> x >> y >> c;
		G[x].emplace_back(y, c);
		G[y].emplace_back(x, c);
	}
	dfs(1);
	ascend();
	solve(1);
	for (int i = 1; i <= n; ++i)
	{
		fout << R[i] << '\n';
	}
    fin.close();
    fout.close();
    return 0;
}
