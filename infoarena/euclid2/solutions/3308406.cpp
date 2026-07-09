#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t, a, b;

int cmmdc(int a, int b){
	if (a > b)swap(a,b);
	int r;
	while (b){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	f >> t;
	for (int i = 1; i <= t; i++){
		cin >> a >> b;
		cout << cmmdc(a,b) << '\n';
	}
	return 0;
}
