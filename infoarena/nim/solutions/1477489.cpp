#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define pii pair<int, int>
#define mp make_pair
 
using namespace std;
 
const string name = "nim",
             in_file = name + ".in",
             out_file = name + ".out";
 
ifstream fin(in_file);
ofstream fout(out_file);
 
int main() {
	int t;
	fin >> t;
	for (int n, s; t; t--) {
		fin >> n;
		s = 0;
		for (int nr; n; n--) {
			fin >> nr;
			s ^= nr;
		}
		fout << (s ? "DA\n" : "NU\n");
	}
	return 0;
}