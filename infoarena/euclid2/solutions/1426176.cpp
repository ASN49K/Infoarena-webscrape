#include <fstream>
using namespace std;

using num = unsigned long long;

constexpr num gcd(const num a, const num b){
	return (b == 0) ? a : gcd(b, a%b); }

int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n = 0;
	f >> n;
	for(int i = 0, a, b; i < n; ++i){
		f >> a >> b;
		g << gcd(a, b) << '\n'; }
	return 0; }
