#include <fstream>


using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main(){
	int t, x, val, sum_xor = 0;
	f >> t;
	while( t ){
		f >> x;
		sum_xor = 0;
		for ( int i = 1; i <= x; i++){
			f >> val;
			sum_xor ^= val;
		}
		if( sum_xor > 0 )
			g << "DA\n";
		else
			g << "NU\n";
		--t;
	}

}