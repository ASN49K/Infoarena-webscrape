#include <bits/stdc++.h>
using namespace std;
 
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b) {
	return (b ? euclid(b, a % b) : a);
}

int main() {

	int T; in >> T;

	for(int t = 1; t <= T; ++t) {
		int a, b; in >> a >> b;
		out << euclid(a, b) << '\n';
	}

    in.close(); out.close();
 
    return 0;
}