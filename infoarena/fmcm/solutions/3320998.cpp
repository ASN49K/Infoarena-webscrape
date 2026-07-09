#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define inf INT_MAX

const int nmax = 355;

int flow[nmax][nmax];
int cost[nmax][nmax];
int cap[nmax][nmax];
int tata[nmax];

vector<int> adj[nmax];
int d[nmax];

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

#define cin fin
#define cout fout

bool dijsktra(int start, int end) {
	for(int i = 0; i < nmax; i ++) {
		d[i] = inf;
	}

	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	d[start] = 0;
	while(!pq.empty()) {
		auto [cc, i] = pq.top();
		pq.pop();
		if(cc != -d[i]) continue;
		if(i == end) continue;

		for(auto pi : adj[i]) {
			if(cap[i][pi] > flow[i][pi]) {
				// int c = cap[i][pi] - flow[i][pi];

				if(d[pi] > d[i] + cost[i][pi]) {
					d[pi] = d[i] + cost[i][pi];
					pq.push({-d[pi], pi});
					tata[pi] = i;
				}
			}
		}
	}
	return d[end] < inf;
}

int doFlux(int start, int end) {
	int Cost = 0;
	while(dijsktra(start, end)) {
		// for(auto vn : adj[end]) {
			int new_flux = inf;
			// tata[end] = vn;
			for(int i = end; i != start; i = tata[i]) {
				new_flux = min(new_flux, cap[tata[i]][i] - flow[tata[i]][i]);
			}
			if(new_flux == 0) continue;
			Cost += new_flux * d[end];
			for(int i = end; i != start; i = tata[i]) {
				flow[tata[i]][i] += new_flux;
				flow[i][tata[i]] -= new_flux;
			}
		// }
	}
	return Cost;
}

int32_t main()
{
	int n,m, start, end;
	cin >> n >> m >> start >> end;
	for(int i = 0; i < m; i++) {
		int a,b,c,cst;
		cin >> a >> b >> c >> cst;
		adj[a].push_back(b);
		adj[b].push_back(a);
		cost[a][b] = cst;
		cost[b][a] = -cst;
		cap[a][b] = c;
	}
	cout << doFlux(start, end);
	return 0;
}