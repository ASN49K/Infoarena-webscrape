# include <fstream>
# include <iostream>

void read_data ( std :: istream & , int & , int & ) ;
int algorithm ( int & , int & ) ;
int algorithm2 ( int & , int & ) ;

int main () {

	std :: ifstream f ("euclid2.in") ;
	std :: ofstream g ("euclid2.out") ;
	
	int a ;
	int b ;
	int T ;
	
	f >> T ;
	for ( int i = 0 ; i < T ; i ++ ) {
	
		read_data (f,a,b) ;
		//g << algorithm ( a , b ) << '\n' ;
		g << algorithm2 ( a , b ) << '\n' ;

	}
	return 0 ;

}


void read_data ( std :: istream & f , int & a , int & b ) {

	f >> a >> b ;

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
