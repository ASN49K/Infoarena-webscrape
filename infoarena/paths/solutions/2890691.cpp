#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#define MAX_N 100000

using namespace std;

ifstream fin("paths.in");
ofstream fout("paths.out");

int n, k;
struct Edge { int dest; int64_t cost; };
vector<Edge> G[MAX_N + 1];

// Information about a node that doesn't depend on the root.
struct NodeInfo {
	int max_node; // A destination in the tree for which the path [current node -> max_node] has maximum cost.
	int64_t max_cost; // Cost of [current node -> max_node].
	int max_neighb; // The neighbour that leads to max_node (0 if max_node = current node).
	int sec_neighb_mn; // Same as max_node, but if you cannot go through max_neighb.
	int64_t sec_neighb_mc; // Cost of [current node -> sec_neighb_mn].
} I[MAX_N + 1];

// C[i] = what you earn if you go through [current root -> i] and 'consume' THE REMAINING edges.
// Some edges are already 'consumed', specifically the edges from [current root -> j], where j leads to a branch that is guaranteed to
// be 'consumed' before the branch to i, because it is more valuable (if you want to go to i, then you must've already been to j).
int64_t C[MAX_N + 1];

// Sin - the set of greatest k elements in C; Sout - the set with the rest of the elements from C; sin_sum - the sum of Sin elements.
multiset<int64_t> Sin, Sout;
int64_t sin_sum;

// The final result.
int64_t R[MAX_N + 1];

void dfs1(int, int);
void dfs2(int, int);
void dfs3(int, int);

int main()
{
	// Reading the graph.
	fin >> n >> k;

	for (int i = 1; i <= n - 1; ++i)
	{
		int x, y; int64_t c;
		fin >> x >> y >> c;
		G[x].push_back({ y, c });
		G[y].push_back({ x, c });
	}

	// Calculate NodeInfo for all nodes, but as if they weren't connected to their father.
	// Also calculate C[any node], where the root is 1.
	dfs1(1, 0);

	// Completes NodeInfo calculation (as if the nodes are connected to their father this time).
	// C[] remains unchanged.
	dfs2(1, 0);

	// Prepare Sin, Sout and sin_sum for dfs3.
	for (int i = 1; i <= n; ++i)
		Sout.insert(C[i]);

	while ((int)Sin.size() < k) {
		Sin.insert(*Sout.rbegin());
		sin_sum += *Sout.rbegin();
		Sout.erase(--Sout.end());
	}

	// Get the final result in R.
	//dfs3(1, 0);

	for (int i = 1; i <= n; ++i)
		fout << R[i] << '\n';

	return 0;
}

// Calculates the NodeInfo for 'node' and all its descendants, but as if they weren't connected to thier father.
// Also calculates C[node] and C[any descendant], where the root is 'node'.
void dfs1(int node, int father)
{
	int max_node = node, max_neighb = 0, sec_neighb_mn = node;
	int64_t max_cost = 0, sec_neighb_mc = 0;

	auto updateMaxNode = [&](int new_max_node, int64_t new_max_cost, int new_max_neighb)
	{
		if (new_max_cost > max_cost) {
			sec_neighb_mn = max_node, sec_neighb_mc = max_cost;
			max_node = new_max_node, max_cost = new_max_cost, max_neighb = new_max_neighb;
		}
		else if (new_max_cost > sec_neighb_mc)
			sec_neighb_mn = new_max_node, sec_neighb_mc = new_max_cost;
	};

	for (Edge edge : G[node])
	{
		int& son = edge.dest;

		if (son == father)
			continue;

		dfs1(son, node);

		// The only cost that changes when I become root (instead of my son) is the cost of my son's max_node,
		// because only the path to that node is considered to 'consume' the edge between me and my son.
		int& son_max_node = I[son].max_node;
		int64_t& son_max_cost = C[son_max_node];
		son_max_cost += edge.cost;

		updateMaxNode(son_max_node, son_max_cost, son);
	}

	I[node] = { max_node, max_cost, max_neighb, sec_neighb_mn, sec_neighb_mc };
	C[node] = 0;
}

// Updates NodeInfo for all 'node' descendants using 'node's NodeInfo. Doesn't change the costs.
// (completes NodeInfo computation from dfs1 if 'node' NodeInfo is complete).
void dfs2(int node, int father)
{
	for (Edge edge : G[node])
	{
		int& son = edge.dest;

		if (son == father)
			continue;

		// Get node's max_node that doesn't go through son.
		int new_max_node = (I[node].max_neighb != son) ? I[node].max_node : I[node].sec_neighb_mn;
		int64_t new_max_cost = edge.cost + (I[node].max_neighb != son ? I[node].max_cost : I[node].sec_neighb_mc);
		int& new_max_neighb = node;

		// Update the son with the information found on 'node'.
		// Note: I'm counting on the fact that son doesn't know about me yet (its max_neighb or sec_neighb is not me).
		if (new_max_cost > I[son].max_cost) {
			I[son].sec_neighb_mn = I[son].max_node, I[son].sec_neighb_mc = I[son].max_cost;
			I[son].max_node = new_max_node, I[son].max_cost = new_max_cost, I[son].max_neighb = new_max_neighb;
		}
		else if (new_max_cost > I[son].sec_neighb_mc)
			I[son].sec_neighb_mn = new_max_node, I[son].sec_neighb_mc = new_max_cost;

		// Go to son after you completely update son information.
		dfs2(son, node);
	}
}

// C, Sin, Sout and sin_sum must be valid with root 'node' when calling this function, along with the NodeInfos.
// Computes the final result for 'node' as root and all its descendants, and saves it in R.
void dfs3(int node, int father)
{
	R[node] = sin_sum;

	auto transfer = [](int giver_node, int taker_node, int64_t cost)
	{
		// Remove C[giver_node] from one of the sets.
		if (Sin.find(C[giver_node]) != Sin.end()) {
			Sin.erase(Sin.find(C[giver_node]));
			sin_sum -= C[giver_node];
		}
		else
			Sout.erase(Sout.find(C[giver_node]));

		// Remove C[taker_node] from one of the sets.
		if (Sin.find(C[taker_node]) != Sin.end()) {
			Sin.erase(Sin.find(C[taker_node]));
			sin_sum -= C[taker_node];
		}
		else
			Sout.erase(Sout.find(C[taker_node]));

		// Transfer the cost.
		C[giver_node] -= cost;
		C[taker_node] += cost;

		// Add both costs to Sout at first.
		Sout.insert(C[giver_node]);
		Sout.insert(C[taker_node]);

		// If the giver was from Sin and taker from Sout, it is possible that both should be in Sin now.
		// So also move the smallest element from Sin to make some space if necessary.
		if (Sin.size() > 0) {
			sin_sum -= *Sin.begin();
			Sout.insert(*Sin.begin());
			Sin.erase(Sin.begin());
		}

		// Sin must have k elements, so put back the elements that we erased above.
		while ((int)Sin.size() < k) {
			Sin.insert(*Sout.rbegin());
			sin_sum += *Sout.rbegin();
			Sout.erase(--Sout.end());
		}
	};

	for (Edge edge : G[node])
	{
		int& son = edge.dest;

		if (son == father)
			continue;

		// C, Sin, Sout and sin_sum must be changed for the new root 'son'.
		// The only thing that actually changes is a transfer of edge.cost from C[giver_node] to C[taker_node].
		// giver_node is the son's max_node that doesn't go through node; taker_node the node's max_node that doesn't go through son.
		int& giver_node = (I[son].max_neighb != node) ? I[son].max_node : I[son].sec_neighb_mn;
		int& taker_node = (I[node].max_neighb != son) ? I[node].max_node : I[node].sec_neighb_mn;

		transfer(giver_node, taker_node, edge.cost);

		dfs3(son, node);

		// Change C, Sin, Sout and sin_sum back.
		transfer(taker_node, giver_node, edge.cost);
	}
}
