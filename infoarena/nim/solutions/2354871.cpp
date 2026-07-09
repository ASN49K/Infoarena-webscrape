#include <bits/stdc++.h>
using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");
int P, n, ans, a;
int main (){
	fin >> P;
	for (int t = 0; t < P; t ++){
		ans = 0;
		fin >> n;
		for (int i = 1; i <= n; i ++){
			fin >> a;
			ans ^= a;
		}
		if (ans)fout << "DA" << '\n';
		else fout<<"NU" << '\n';
	}
	return 0;
}
