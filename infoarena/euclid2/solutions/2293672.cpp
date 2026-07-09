#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t, a, b;

int f(int a, int b) {
	if(!b)
		return a;
	return f(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--) {
		cin>>a>>b;
		cout<<f(a, b)<<'\n';
	}
	return 0;
}

