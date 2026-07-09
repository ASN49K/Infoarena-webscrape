#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
	int r;
	while(b) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    
    int t, a, b;
    fin >> t;
    for(int i=1; i<=t; i++) {
		fin >> a >> b;
		fout << cmmdc(a, b) << endl;
	}
    return 0;
}
