#include <iostream>
#include <fstream>
#include <stdint.h>
#include <algorithm>

const int32_t MAX_N = 350;
const int32_t MAX_M = 12500;
const int32_t MAX_DIST = 1000000000;
const int32_t MAX_FLOW = 10000;

int32_t min(int32_t x, int32_t y) {
	return (x < y) ? x : y;
}

struct Node {
	int32_t adjStart, adjInd;
	int32_t dist, level;
};
struct AdjItem {
	int32_t node, cost;
	int32_t flow, cap;
	int32_t next;
};
struct MaxFlowRes {
	int64_t maxFlow, minCost;
};

struct Queue {
	int32_t start = 0, end = 0;
	int32_t queue[MAX_N + 1];
	bool inQueue[MAX_N];

	bool IsEmpty() {
		return start == end;
	}
	void Push(int32_t node) {
		if(inQueue[node])
			return;
		inQueue[node] = true;

		queue[end++] = node;
		if(end == MAX_N + 1)
			end = 0;
	}
	int32_t Pop() {
		int32_t node = queue[start++];
		if(start == MAX_N + 1)
			start = 0;
		
		inQueue[node] = false;
		return node;
	}
};
struct PQueue {
	struct Item {
		int32_t node, dist;

		bool operator<(const Item& other) const {
			if(dist != other.dist)
				return dist > other.dist;
			return node > other.node;
		}
	};

	int32_t size;
	Item items[MAX_M];

	bool IsEmpty() {
		return !size;
	}
	void Push(Item item) {
		items[size++] = item;
		std::push_heap(items, items + size);
	}
	Item Pop() {
		std::pop_heap(items, items + size);
		return items[--size];
	}
};

int32_t n, m, src, dst;
Node nodes[MAX_N];
AdjItem adj[MAX_M << 1];
int64_t dstDist;
Queue queue;
PQueue pQueue;

bool PrecalcDists() {
	for(int32_t i = 0; i != n; ++i)
		nodes[i].dist = MAX_DIST;
	
	nodes[src].dist = 0;
	queue.Push(src);

	while(!queue.IsEmpty()) {
		int32_t node = queue.Pop();

		for(int32_t ind = nodes[node].adjStart; ind != -1; ind = adj[ind].next) {
			if(adj[ind].flow == adj[ind].cap)
				continue;

			int32_t next = adj[ind].node;
			int32_t nextDist = nodes[node].dist + adj[ind].cost;
			if(nextDist < nodes[next].dist) {
				nodes[next].dist = nextDist;
				queue.Push(next);
			}
		}
	}

	return nodes[dst].dist != MAX_DIST;
}
bool CalcDists() {
	for(int32_t i = 0; i != n; ++i)
		nodes[i].dist = MAX_DIST;
	
	nodes[src].dist = 0;
	pQueue.Push({ src, 0 });

	while(!pQueue.IsEmpty()) {
		PQueue::Item item = pQueue.Pop();
		int32_t node = item.node;
		if(nodes[node].dist != item.dist)
			continue;
		
		for(int32_t ind = nodes[node].adjStart; ind != -1; ind = adj[ind].next) {
			if(adj[ind].flow == adj[ind].cap)
				continue;
			
			int32_t next = adj[ind].node;
			int32_t nextDist = nodes[node].dist + adj[ind].cost;
			if(nextDist < nodes[next].dist) {
				nodes[next].dist = nextDist;
				pQueue.Push({ next, nextDist });
			}
		}
	}

	return nodes[dst].dist != MAX_DIST;
}
void UpdateEdgeCosts() {
	for(int32_t node = 0; node != n; ++node) {
		for(int32_t ind = nodes[node].adjStart; ind != -1; ind = adj[ind].next) {
			int32_t next = adj[ind].node;
			if(nodes[node].dist != MAX_DIST && nodes[next].dist != MAX_DIST)
				adj[ind].cost -= nodes[next].dist - nodes[node].dist;
		}
	}

	dstDist += nodes[dst].dist;
}
bool BuildGraphLevels() {
	for(int32_t i = 0; i != n; ++i) {
		nodes[i].adjInd = nodes[i].adjStart;
		nodes[i].level = -1;
	}

	nodes[src].level = 0;
	queue.Push(src);

	while(!queue.IsEmpty()) {
		int32_t node = queue.Pop();

		for(int32_t ind = nodes[node].adjStart; ind != -1; ind = adj[ind].next) {
			int32_t next = adj[ind].node;
			if(adj[ind].flow == adj[ind].cap || nodes[next].level != -1 || adj[ind].cost)
				continue;
			
			nodes[next].level = nodes[node].level + 1;
			queue.Push(next);
		}
	}

	return nodes[dst].level != -1;
}
int32_t DFSPushFlow(int32_t node, int32_t flow) {
	if(node == dst || !flow)
		return flow;
	
	for(int32_t ind = nodes[node].adjStart; ind != -1; ind = adj[ind].next) {
		int32_t next = adj[ind].node;
		if(adj[ind].cost || nodes[next].level != nodes[node].level + 1)
			continue;
		
		int32_t nextFlow = min(flow, adj[ind].cap - adj[ind].flow);
		int32_t resFlow = DFSPushFlow(next, nextFlow);

		if(resFlow) {
			adj[ind].flow += resFlow;
			adj[ind ^ 1].flow -= resFlow;
			return resFlow;
		}
	}
	return 0;
}

void ReadGraph(std::istream& fin) {
	fin >> n >> m >> src >> dst;
	--src; --dst;

	for(int32_t i = 0; i != n; ++i)
		nodes[i].adjStart = -1;
	for(int32_t i = 0; i != m; ++i) {
		int32_t node1, node2, cap, cost;
		fin >> node1 >> node2 >> cap >> cost;
		--node1; --node2;

		adj[i << 1].node = node2;
		adj[i << 1].cost = cost;
		adj[i << 1].cap = cap;
		adj[i << 1].next = nodes[node1].adjStart;
		nodes[node1].adjStart = i << 1;

		adj[(i << 1) + 1].node = node1;
		adj[(i << 1) + 1].cost = -cost;
		adj[(i << 1) + 1].cap = 0;
		adj[(i << 1) + 1].next = nodes[node2].adjStart;
		nodes[node2].adjStart = (i << 1) + 1;
	}
}
MaxFlowRes GetMaxFlow() {
	if(!PrecalcDists())
		return { 0, 0 };

	MaxFlowRes res;
	res.maxFlow = 0;
	res.minCost = 0;

	do {
		UpdateEdgeCosts();
		while(BuildGraphLevels()) {
			int32_t currFlow;
			do {
				currFlow = DFSPushFlow(src, MAX_FLOW);
				res.maxFlow += currFlow;
				res.minCost += currFlow * dstDist;
			} while(currFlow);
		}
	} while(CalcDists());

	return res;
}

int main() {
	std::ifstream fin("fmcm.in");
	std::ofstream fout("fmcm.out");

	ReadGraph(fin);
	fout << GetMaxFlow().minCost << '\n';

	fin.close();
	fout.close();

	return 0;
}