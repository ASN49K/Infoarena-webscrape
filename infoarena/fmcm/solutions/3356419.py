from collections import deque
from heapq import heappush, heappop

class Edge():
    def __init__(self, to, flow, cap, cost, rid):
        self.to = to
        self.flow = flow
        self.cap = cap
        self.cost = cost
        self.rid = rid

class MaxFlow():
    INF = int(1e15)
    
    def __init__(self, n):
        self.n = n
        self.adj = [[] for _ in range(n)]
        self.potential = []
    
    def add_edge(self, u, v, cap, cost):
        self.adj[u].append(Edge(v, 0, cap, cost, len(self.adj[v])))
        self.adj[v].append(Edge(u, 0, 0, -cost, len(self.adj[u]) - 1))

    def compute_potentials(self, src):
        n = self.n
        dist = [self.INF] * n
        dist[src] = 0
        queue = deque([src])
        while queue:
            u = queue.popleft()
            for edg in self.adj[u]:
                if edg.cap > 0 and dist[u] + edg.cost < dist[edg.to]:
                    dist[edg.to] = dist[u] + edg.cost
                    queue.append(edg.to)
        self.potential = dist

    def dijkstra(self, src, target):
        n = self.n
        dist = [self.INF] * n
        dist[src] = 0

        heap = []
        heappush(heap, (0, src))

        self.flow_here = [0] * n
        self.flow_here[src] = self.INF
        self.father_edge = [-1] * n

        while heap:
            d, u = heappop(heap)
            if d > dist[u]:
                continue
            for edg in self.adj[u]:
                if edg.flow < edg.cap:
                    new_dist = dist[u] + edg.cost + self.potential[u] - self.potential[edg.to]
                    if new_dist < dist[edg.to]:
                        dist[edg.to] = new_dist
                        self.flow_here[edg.to] = min(self.flow_here[u], edg.cap - edg.flow)
                        self.father_edge[edg.to] = edg.rid
                        heappush(heap, (new_dist, edg.to))

        path_found = dist[target] < self.INF

        for i in range(n):
            dist[i] += self.potential[i] - self.potential[src]
        for i in range(n):
            self.potential[i] = dist[i]

        return path_found

    def flow(self, src, target):
        #returns (flow, cost)

        self.compute_potentials(src)

        total_flow = 0
        total_cost = 0

        while self.dijkstra(src, target):
            total_flow += self.flow_here[target]
            total_cost += self.potential[target] * self.flow_here[target]

            u = target

            while u != src:
                edg = self.adj[u][self.father_edge[u]]
                edg.flow -= self.flow_here[target]
                self.adj[edg.to][edg.rid].flow += self.flow_here[target]
                u = edg.to


        return (total_flow, total_cost)
    

if __name__ == "__main__":
    fin = open("fmcm.in", "r")
    fout = open("fmcm.out", "w")

    n, m, src, target = map(int, fin.readline().split())
    src -= 1
    target -= 1
    max_flow = MaxFlow(n)
    for _ in range(m):
        u, v, cap, cost = map(int, fin.readline().split())
        max_flow.add_edge(u - 1, v - 1, cap, cost)

    flow, cost = max_flow.flow(src, target)
    fout.write(f"{cost}\n")