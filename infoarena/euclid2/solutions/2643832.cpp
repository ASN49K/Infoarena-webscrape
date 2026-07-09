#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    int t, a, b, r;
    cin >> t;
    for(int i=0; i<t; i++) {
		fin >> a >> b;
		while(b!=0) {
			r = a%b;
			a = b;
			b = r;
		}
		fout << a;
	}
    return 0;
}
