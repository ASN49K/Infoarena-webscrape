#include<fstream>

using namespace std;

	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	
int t,a,b,r;

void gcd(int a, int b) {
	while (b) {
		r=a%b;
		a=b;
		b=r;
	}
	cout<<a<<'\n';
}

int main() {

	cin>>t;
	
	while (t--) {
		cin>>a>>b; if (a<b) swap(a,b);
		gcd(a,b);
	}
	
	return 0;
}
