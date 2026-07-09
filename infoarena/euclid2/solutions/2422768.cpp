#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(){
	int n;
	in >> n;
	for (int i = 0; i < n ; i++){
		long long a, b;
		in >> a >> b;
		while (b){
			long r = a % b;
			a = b;
			b = r;
		}
		out << a << '\n';
	}

	return 0;
}