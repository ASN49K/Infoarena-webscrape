#include <fstream>
using namespace std;
int main(){
	int t, n, i, j, x, s;
	ifstream fin( "nim.in" );
	ofstream fout( "nim.out" );
	fin >> t;
	for( j = 0; j < t; j++ ){
		fin >> n;
		s = 0;
		for( i = 0; i < n; i++ ){
			fin >> x;
			s ^= x;
		}
		if( s > 0 ){
			fout << "DA\n";
		}
		else{
			fout << "NU\n";
		}
	}
	return 0;
}