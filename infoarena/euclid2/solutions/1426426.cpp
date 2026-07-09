# include <fstream>
# include <iostream>
# include <math.h>

void read_data ( std :: istream & , int & , int & ) ;
int algorithm ( int & , int & ) ;
int algorithm2 ( int & , int & ) ;
int algorithm3 ( int & , int & ) ;
int main () {

	std :: ifstream f ("euclid2.in") ;
	std :: ofstream g ("euclid2.out") ;
	
	int a ;
	int b ;
	int T ;
	
	f >> T ;
	for ( int i = 0 ; i < T ; i ++ ) {
	
		read_data ( f , a , b ) ;
		//g << algorithm ( a , b ) << '\n' ;
		//g << algorithm2 ( a , b ) << '\n' ;
		g << algorithm3 ( a , b ) << '\n' ;
		

	}
	return 0 ;

}


void read_data ( std :: istream & f , int & a , int & b ) {

	f >> a >> b ;

}

int algorithm3 ( int & a , int & b ) {

	int d = 0 ;
	int end ;
	
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


int algorithm ( int & a , int & b ) {

	int min ;
	
	min = std :: min (a,b) ;
	for ( int i = min ; i >= 2 ; i -- ) {
	
		if ( a % i == 0 && b % i == 0 ) {
		
			return i ;
		
		}
	
	}

	return 1 ;
}

int algorithm2 ( int & a , int & b ) {

	while ( a != b ) {
	
		if ( a > b ) {
		
			a -= b ;
		
		} else {
		
			b -= a ;
		
		}
	
	}

	return a ;
}
