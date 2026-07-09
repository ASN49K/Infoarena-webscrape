#include <bits/stdc++.h>
using namespace std;

#define ll long long

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void solve(){
    int x, y;
    fin>>x>>y;
    fout<<__gcd(x,y)<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	fin.tie(nullptr);

	int t; fin>>t;
	while(t--){
        solve();
	}

    return 0;
}
