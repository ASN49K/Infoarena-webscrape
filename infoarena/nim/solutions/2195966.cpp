#pragma GCC optimize("03")
#include <bits/stdc++.h>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main(){
	int t, n, x;
	in >> t;
	while(t--){
		in >> n;
		int s = 0;
		while(n--){
			in >> x;
			s ^= x;
		}
		out << (s ? "DA\n" : "NU\n");
	}
	return 0;
}	
