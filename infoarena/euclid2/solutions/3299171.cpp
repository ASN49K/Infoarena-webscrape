#include <fstream>
using namespace std;
int cmmdc( int a, int b ){
	int r;
	while( b > 0 ){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(){
	int n, i, x, y;
	ifstream fin( "euclid2.in" );
	ofstream fout( "euclid2.out" );
	fin >> n;
	for( i = 0; i < n; i++ ){
		fin >> x >> y;
		fout << cmmdc( x, y ) << '\n';
	}
	return 0;
}