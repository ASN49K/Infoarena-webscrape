from collections import deque
import heapq


def dijkstra(residual,n,source, potentials):
    """Run Dijkstra's algorithm to find the shortest path with reduced costs."""
    dist = [float('inf')] * n
    parent = [-1] *  n
    dist[source] = 0
    pq = [(0, source)]  # (distance, node)

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue

        for v in residual[u]:
            if residual[u][v][0] > 0:
                reduced_cost = residual[u][v][1] + potentials[u] - potentials[v]
                if dist[u] + reduced_cost < dist[v]:
                    dist[v] = dist[u] + reduced_cost
                    parent[v] = u
                    heapq.heappush(pq, (dist[v], v))

    return dist, parent

def initialize_residual_graph(graph):
    """
    Ensure reverse arcs are included in the residual graph with zero initial flow.
    """
    n = len(graph)
    residual = {i: {}for i in range(n)}
    for u in range(n):
        for v, cap, cost, flow in graph[u]:
            residual[u][v]=[cap, cost ]  # Forward arc
            residual[v][u]=[ 0, -cost ]   # Reverse arc
    #print("Rez",residual)
    return residual

def bellman_ford(residual, n, source):
    """
    Bellman-Ford algorithm to detect negative cost cycles.
    graph: adjacency list of residual graph with cost.
    n: number of nodes.
    source: source node.
    Returns: dist (list of shortest distances), parent (to reconstruct cycle).
    """

    dist = [float("inf")] * n
    parent = [-1] * n
    dist[source] = 0

    for _ in range(n - 1):
        for u in range(n):
            for v in  residual[u]  : #arc i v
                if residual[u][v][0]>0 and dist[u] + residual[u][v][1] < dist[v]:
                    dist[v] = dist[u] + residual[u][v][1]
                    parent[v] = u

    return dist, parent

def min_cost_max_flow(graph, source, sink):
    """
    Finds the minimum cost maximum flow in a graph.
    graph: adjacency list where each edge is [to, capacity, cost, flow].
    source: source node.
    sink: sink node.
    Returns: (max_flow, min_cost).
    """
    residual = initialize_residual_graph(graph)
    dist_init, parent = bellman_ford(residual, n, source)
    max_flow = 0
    min_cost = 0

    # Step 1: Find max flow using BFord (Edmonds-Karp style).
    while True:

        dist , parent = dijkstra(residual, n, source,dist_init)
        if dist[sink]==float("inf"):
            break  # No more augmenting path.

        # Find bottleneck capacity.
        path_flow = float("inf")
        v = sink
        while v != source:
            u = parent[v]
            path_flow = min(path_flow, residual[u][v][0])
            v = u

        # Augment flow along the path.
        #print("crestere",path_flow,residual)
        v = sink
        while v != source:
            u = parent[v]
            residual[u][v][0] -= path_flow
            residual[v][u][0] += path_flow

            v = u

        max_flow += path_flow



    min_cost=0
    for u in range(n):
        for v,cap,cost,flow in graph[u]:
            #print(u,v, residual[v][u][0],cost)
            min_cost+=residual[v][u][0]*cost

    return max_flow, min_cost

f=open("fmcm.in")
n,m,source,sink=[int(x) for x in f.readline().split()]
source-=1
sink-=1
# Example usage
graph=[[] for i in range(n)]
for line in f:
    x,y,cap,cost=[int(x) for x in line.split()]
    graph[x-1].append([y-1,cap,cost,0])
f.close()
""" 
graph = [
    [[1, 4, 2, 0], [3, 4, 4, 0]],  # Node 0
    [[2, 3, 1, 0]],                 # Node 1
    [[4, 10, 3, 0]],                # Node 2
    [[2, 2, 1, 0], [4, 7, 10, 0]], # Node 3
    []                              # Node 4
]

source = 0
sink = 4"""

#print(graph)

max_flow, min_cost = min_cost_max_flow(graph, source, sink)
#print("Max Flow:", max_flow)
#print("Min Cost:", min_cost)
g=open("fmcm.out","w")
g.write(str(min_cost))
g.close()
