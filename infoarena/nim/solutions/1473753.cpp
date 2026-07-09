#include <fstream>
using namespace std;

constexpr char raspunsuri[][4] = {"NU\n", "DA\n"};

int main(){
	ifstream f("nim.in");
	ofstream g("nim.out");
	int t = 0;
	f >> t;
	for(int i = 0; i < t; ++i){
		int n = 0;
		f >> n;
		int rez = 0;
		for(int j = 0, x; j < n; ++j){
			f >> x;
			rez ^= x; }
		g << raspunsuri[rez!=0]; }
	return 0; }
