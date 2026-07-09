#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<set>
#define MOD 1000000007
#define INF 0x3F3F3F3F
#define mp make_pair
using namespace std;
using PI = pair<int, int>;
ifstream in("nim.in");
ofstream out("nim.out");
int teste, n;
int main() {
	in >> teste;
	for (int k = 0; k < teste; k++) {
		in >> n;
		int* v = new int[n + 1];
		for (int i = 1; i <= n; i++) in >> v[i];
			int x = v[1];
			for (int i = 2; i <= n; i++)
				x ^= v[i];
			if (x) out << "DA" << '\n';
			else out << "NU" << '\n';
	}
	return 0;
}