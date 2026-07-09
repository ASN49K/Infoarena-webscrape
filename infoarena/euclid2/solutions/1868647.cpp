#include <bits/stdc++.h>
using namespace std;

// computes gcd(a,b)
int gcd(int a, int b) {
    while (b) { int t = a%b; a = b; b = t; }
    return a;
}

int main() {

    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");

    int T; fin >> T;
    for (int t = 0; t < T; t++) {
	int a, b; fin >> a >> b;
	fout << gcd (a, b) << "\n";
    }
    
    return 0;
}
