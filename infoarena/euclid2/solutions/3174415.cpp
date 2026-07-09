
#include<iostream>
#include<fstream>
#include<algorithm>


using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}



int main(){
	in.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n,a,b;
	in >> n;
	for (int i=0;i<n;i++) {
		in >> a >> b;
		out << gcd(a, b)<<endl;
	}
	
	return 0;
}