# include <fstream>
# include <iostream>
# include <math.h>

void read_data ( std :: istream & , int & , int & ) ;
int algorithm ( int & , int & ) ;


int main () {

	std :: ifstream f ("euclid2.in") ;
	std :: ofstream g ("euclid2.out") ;
	
	int a ;
	int b ;
	int T ;
	
	f >> T ;
	for ( int i = 0 ; i < T ; i ++ ) {
	
		read_data ( f , a , b ) ;
		g << algorithm ( a , b ) << '\n' ;

	}
	
	f.close () ;
	g.close () ;
	return 0 ;

}


void read_data ( std :: istream & f , int & a , int & b ) {

	f >> a >> b ;

}

int algorithm ( int & a , int & b ) {

	int d = 0 ;
	int end = 1 ;
	
	if ( a == b ) {
	
		return a ;
	
	}
	
	while ( a % 2 == 0 && b % 2 == 0 ) {
	
		d ++ ;
		a /= 2 ;
		b /= 2 ;
	
	}

	while ( a != b ) {
	
		if ( a % 2 == 0 ) {
		
			a /= 2 ;
		
		} else if ( b % 2 == 0 ) {
		
			b /= 2 ;
		
		} else if ( a > b ) {
		
			a = ( a - b ) / 2 ;
		
		} else {
		
			b = ( b - a ) / 2 ;
		
		}

		end = a ;
			
	}
	
	return end * pow ( 2 , d ) ;
	
}


