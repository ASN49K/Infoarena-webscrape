#include <bits/stdc++.h>

using namespace std;

const int NMAX = 350;
const int INF = 1e9;

int flux[NMAX + 1][NMAX + 1];
int cost[NMAX + 1][NMAX + 1];
vector <int> edges[NMAX + 1];

int viz[NMAX + 1];
int minDist[NMAX + 1];
int realDist[NMAX + 1];
int fakeDist[NMAX + 1];

int prv[NMAX + 1];
bool inQ[NMAX + 1];

int s, d, n;

void bellman() {
    for ( int i = 1; i <= n; i ++ ) {
        minDist[i] = INF;
    }

    minDist[s] = 0;
    queue <int> q;
    q.push( s );
    while ( !q.empty() ) {
        int node = q.front();
        q.pop();
        inQ[node] = false;
        for ( auto vec : edges[node] ) {
            if ( flux[node][vec] > 0 && minDist[node] + cost[node][vec] < minDist[vec] ) {
                minDist[vec] = minDist[node] + cost[node][vec];
                if ( !inQ[vec] ) {
                    q.push( vec );
                    inQ[vec] = true;
                }
            }
        }
    }
}
bool dijkstra() {
    for ( int i = 1; i <= d; i ++ ) {
        viz[i] = false;
        realDist[i] = minDist[i];
        fakeDist[i] = INF;
        prv[i] = 0;
    }
    minDist[s] = fakeDist[s] = 0;

    priority_queue <pair<int, int>> pq;

    pq.push( {0, s} );

    while ( !pq.empty() ) {
        int node = pq.top().second;
        pq.pop();
        if ( viz[node] ) continue;
        viz[node] = true;
        for ( auto vec : edges[node] ) {
            if ( flux[node][vec] && fakeDist[node] + realDist[node] + cost[node][vec] - realDist[vec] < fakeDist[vec] ) {
                fakeDist[vec] = fakeDist[node] + realDist[node] + cost[node][vec] - realDist[vec];
                minDist[vec] = minDist[node] + cost[node][vec];
                prv[vec] = node;
                pq.push( {-fakeDist[vec], vec} );
            }
        }
    }
    return prv[d] != 0;
}
int main() {
    ifstream fin( "fmcm.in" );
    ofstream fout( "fmcm.out" );
    int m;
    fin >> n >> m >> s >> d;
    for ( int i = 1, a, b, c, f; i <= m; i ++ ) {
        fin >> a >> b >> f >> c;
        edges[a].push_back( b );
        edges[b].push_back( a );
        flux[a][b] = f;
        cost[a][b] = c;
        cost[b][a] = -c;
    }

    bellman();

    int maxFlow = 0;
    int minCost = 0;
    while( dijkstra() ) {
        int f = INF, node = d, c = 0;
        while ( node != s ) {
            f = min( f, flux[prv[node]][node] );
            c += cost[prv[node]][node];
            node = prv[node];
        }
        node = d;
        while ( node != s ) {
            flux[prv[node]][node] -= f;
            flux[node][prv[node]] += f;

            node = prv[node];
        }
        maxFlow += f;
        minCost += c * f;
    }
    fout << minCost << '\n';
    return 0;
}