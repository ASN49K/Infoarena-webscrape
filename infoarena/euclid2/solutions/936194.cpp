/*
Name:	Dumitrascu Constantin
Source:	main.cpp
Date:	06 april 2013
*/

#include <fstream>

using namespace::std;

#define read_file	"euclid2.in"
#define print_file	"euclid2.out"

int Euclid( int, int );

int main() {

    int n, a, b;

	ifstream get( read_file );
	ofstream put( print_file );

	get >> n;

	for( int i = 1; i <= n; i++ ) {

        get >> a >> b;

        put << Euclid( a, b ) << '\n';

	}

	get.close();
	put.close();

	return 0;
}

int Euclid( int a, int b ) {

    int p = a % b;

    while( p ) a = b, b = p, p = a % b;

    return b;

}
