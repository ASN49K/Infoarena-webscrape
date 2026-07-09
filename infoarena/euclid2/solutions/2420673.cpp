#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t, a, b;
int main(){
	in >> t;
	for (int i = 0; i < t; i++){
		in >> a >> b;
		while (a != b){
			if (a > b){
				a -= b;
			}
			if (a < b){
				b -= a;
			}
		}
		out << a;
	}
	return 0;
}