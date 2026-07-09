#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct elem{
	int x, dst;
};
struct comp{
	bool operator()( elem a, elem b ){
		return a.dst > b.dst;
	}
};
int cap[355][355], flow[355][355], cost[355][355], bellman[355], aux_bellman[355], dist[355], t[355], ras = 0, n, s, d;
vector <int> v[355];
bool maxflow(){
	int i, x, y, dst, ok, min_flow;
	priority_queue <elem, vector <elem>, comp> q;
	for( i = 1; i <= n; i++ ){
		aux_bellman[i] = dist[i] = INT32_MAX / 3;
		bellman[i] = aux_bellman[i];
	}
	aux_bellman[s] = dist[s] = ok = 0;
	q.push( { s, 0 } );
	while( q.empty() == false ){
		x = q.top().x;
		dst = q.top().dst;
		q.pop();
		if( x == d ){
			ok = 1;
		}
		//cout << x << ' ' << dst << '\n';
		if( dst != dist[x] ){
			continue;
		}
		//cout << x << ' ' << d << '\n';
		for( i = 0; i < v[x].size(); i++ ){
			y = v[x][i];
			//cout << x << ' ' << y << ' ' << ( flow[x][y] < cap[x][y] ) << ' ' << ( dist[x] + cost[x][y] + bellman[y] - bellman[x] < dist[y] ) << '\n';
			if( flow[x][y] < cap[x][y] && dist[x] + cost[x][y] + bellman[y] - bellman[x] < dist[y] ){
				dist[y] = dist[x] + cost[x][y] + bellman[y] - bellman[x];
				t[y] = x;
				aux_bellman[y] = aux_bellman[x] + cost[x][y];
				q.push( { y, dist[y] } );
			}
		}
	}
	if( ok == 0 ){
		return false;
	}
	min_flow = INT32_MAX;
	x = d;
	while( x != s ){
		min_flow = min( cap[t[x]][x] - flow[t[x]][x], min_flow );
		x = t[x];
	}
	ras += min_flow * aux_bellman[d];
	//cout << min_flow << ' ' << aux_bellman[d] << '\n';
	x = d;
	while( x != s ){
		flow[t[x]][x] += min_flow;
		flow[x][t[x]] -= min_flow;
		x = t[x];
	}
	return true;
}
int main(){
	int m, i, x, y, c, z;
	ifstream fin( "fmcm.in" );
	ofstream fout( "fmcm.out" );
	fin >> n >> m >> s >> d;
	for( i = 0; i < m; i++ ){
		fin >> x >> y >> c >> z;
		v[x].push_back( y );
		cap[x][y] = c;
		cost[x][y] = z;
		cost[y][x] = -z;
	}
	for( i = 1; i <= n; i++ ){
		aux_bellman[i] = INT32_MAX / 3;
	}
	queue <int> q;
	aux_bellman[s] = 0;
	q.push( s );
	while( q.empty() == false ){
		x = q.front();
		q.pop();
		for( i = 0; i < v[x].size(); i++ ){
			y = v[x][i];
			if( aux_bellman[x] + cost[x][y] < aux_bellman[y] && cap[x][y] > 0 ){
				aux_bellman[y] = aux_bellman[x] + cost[x][y];
				q.push( y );
			}
		}
	}
	while( maxflow() == true );
	fout << ras;
	return 0;
}