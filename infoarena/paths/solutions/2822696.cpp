#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pli pair<ll, int>
using namespace std;

const int N = 100005;
int n, k;
vector<pair<int, int> > v[N];
vector<pli> u[N];

void dump(vector<pli> &x, vector<pli> &y) {
	if(y.size() > x.size()) { swap(x, y); }
	if(x.back() > y.back()) { swap(x.back(), y.back()); }
	for(auto v : y) x.push_back(v);
}

void firstcalc(int x = 1, int w = 0) {
	u[x].push_back({0, x});
	for(pair<int, int> p : v[x]) {
		int y = p.first; int z = p.second;
		if(y == w) continue;
		firstcalc(y, x);
		u[y].back().first += z;
		dump(u[x], u[y]);
	}
}

struct relt {
	relt() { dist = x = -1; }
	ll dist;
	int x;
};

struct furthest {
	furthest() { x = y = dist = -1; }
	int x;
	int y;
	ll dist;
};

furthest fth[N][2];

void dunp(int x, int y, ll z) {
	furthest t = fth[y][0];
	t.dist += z; t.y = y;
	if(t.dist > fth[x][0].dist) { swap(t, fth[x][0]); }
	if(t.dist > fth[x][1].dist) { swap(t, fth[x][1]); }
}

void subtree(int x = 1, int w = 0) {
	fth[x][0].x = x;
	fth[x][0].y = 0;
	fth[x][0].dist = 0;
	for(pair<int, int> p : v[x]) {
		int y = p.first; int z = p.second;
		if(y == w) continue;
		subtree(y, x);
		dunp(x, y, z);
	}
}

relt upfth[N];

void supertree(int x = 1, int w = 0, relt up = relt()) {
	upfth[x] = up;
	relt predown = up;
	if(predown.dist < 0) { predown.dist = 0; predown.x = x; }
	for(pair<int, int> p : v[x]) {
		int y = p.first; int z = p.second;
		if(y == w) continue;
		furthest t = fth[x][0];
		if(t.y == y) t = fth[x][1];
		relt down = predown;
		if(down.dist < t.dist) { down.dist = t.dist; down.x = t.x; }
		supertree(y, x, down);
	}
}

struct one_set_to_rule_them_all {
	// one_set_to_rule_them_all() {}
	one_set_to_rule_them_all(int _k = 0) : k(_k) { sum = 0; }
// private:
	int k;
	multiset<ll> s1, s2;
	map<int, ll> ma;
	ll sum;
public:
	void insert(ll z, int x) {
		ma[x] = z;
		sum += z;
		s2.insert(z);
		if(s2.size() > k) {
			sum -= *s2.begin();
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}
	}
	void erase(int x) {
		// for(int i = 1; i <= n; ++i) {
		// 	cout << x << " " << ma[x] << endl;
		// }
		// for(auto x : s1) {
		// 	cout << x << " ";
		// }
		// for(auto x : s2) {
		// 	cout << x << " ";
		// }
		// cout << endl << endl;
		ll z = ma[x];
		if(s1.find(z) != s1.end()) {
			s1.erase(s1.find(z));
		} else {
			sum -= z;
			// if(s2.find(z) == s2.end()) cout << "GANGASHI" << endl;
			s2.erase(s2.find(z));
			if(s1.size()) {
				sum += *(--s1.end());
				s2.insert(*(--s1.end()));
				s1.erase(--s1.end());
			}
		}
	}
	void increase(int x, ll z) {
		erase(x);
		ma[x] += z;
		insert(ma[x], x);
	}
	ll getAnswer() {
		return sum;
	}
} dists;

void slide(int y, int z) {
	dists.increase(upfth[y].x, z);
	dists.increase(fth[y][0].x, -z);
}

ll fp[N];

void dfs(int x = 1, int w = 0) {
	fp[x] = dists.getAnswer();
	for(pair<int, int> p : v[x]) {
		int y = p.first; int z = p.second;
		if(y == w) continue;
		slide(y, z);
		dfs(y, x);
		// cout << "[0] " << x << " " << dists.s1.size() << " " << dists.s2.size() << endl;
		slide(y, -z);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef wambule
	freopen("paths.in", "r", stdin);
	freopen("paths.out", "w", stdout);
	#else
	freopen("untitledfile.txt", "r", stdin);
	#endif
	cin >> n >> k;
	for(int i = 1; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({y, z});
		v[y].push_back({x, z});
	}
	subtree();
	supertree();
	firstcalc();
	dists = one_set_to_rule_them_all(k);
	for(pli p : u[1]) {
		int z = p.first; int x = p.second;
		dists.insert(z, x);
	}
	dfs();
	for(int i = 1; i <= n; ++i) {
		cout << fp[i] << "\n";
	} cout << endl;
	return 0;
}
