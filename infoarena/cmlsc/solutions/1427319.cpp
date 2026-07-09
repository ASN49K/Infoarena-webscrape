# include <iostream>
# include <fstream>
# include <vector>
# include <stack>

# define UP 2
# define LEFT 1
# define COLT 3
# define NOTHING 0
# define AMBELE 4


void read_data ( std :: istream & , int & , int & ) ;
void read_numbers ( std :: istream & , int , std :: vector <int> & ) ;
void print_vector ( std :: ostream & , std :: vector <int> ) ;
void dynamic_programming ( std :: ostream & , std :: vector <int> & , std :: vector <int> & ) ;


int main () {

	int N , M ;
	std :: ifstream f ( "cmlsc.in" ) ;
	std :: ofstream g ( "cmlsc.out" ) ;
	
	read_data ( f , M , N ) ;
	std :: vector <int> first (M) ;
	std :: vector <int> second (N) ;
	
	read_numbers ( f , M , first ) ;
	read_numbers ( f , N , second ) ;
	
	//print_vector ( g , first ) ;
	//print_vector ( g , second ) ;
	
	dynamic_programming ( g , first , second ) ;
	
	
	f.close () ;
	g.close () ;
	return 0 ;

}

void read_numbers ( std :: istream & f , int N , std :: vector <int> & array ) {

	for ( int i = 0 ; i < N ; i ++ ) {
	
		f >> array[i] ;
	
	}

}


void print_vector ( std :: ostream & g ,  std :: vector <int> array ) {

	for ( unsigned int i = 0 ; i < array.size () ; i ++ ) {
	
		g << array[i] << ' ' ;
	
	}

	g << '\n' ;
	
}


void read_data ( std :: istream & f , int & M , int & N ) {

	f >> M >> N ; 

}


void dynamic_programming ( std :: ostream & g , std :: vector <int> & first ,
							 std :: vector <int> & second ) {

	int **track ;
	int **matrix ;
	int size1 = first.size () ;
	int size2 = second.size () ;
	
	
	
	track = new int *[size1+1] ;
	matrix = new int * [size1+1] ;
	for ( int i = 0 ; i <= size1 ; i ++ ) {
	
		track[i] = new int [size2+1] ;
		matrix[i] = new int [size2+1] ;
	
	}
	
	for ( int i = 0 ; i <= size1 ; i ++ ) {
	
		for ( int j = 0 ; j <= size2 ; j ++ ) {
		
			track[i][j] = NOTHING ;
			matrix[i][j] = NOTHING ;
		
		}
	
	}
	
	for ( int i = 1 ; i <= size1 ; i ++ ) {
	
		for ( int j = 1 ; j <= size2 ; j ++ ) {
		
			if ( first[i-1] == second[j-1] ) {
			
				matrix[i][j] = 1 + matrix[i-1][j-1] ;
				track[i][j] = COLT ;
			
			} else {
			
				if ( matrix[i][j-1] > matrix[i-1][j] ) {
				
					track[i][j] = LEFT ;
					matrix[i][j] = matrix[i][j-1] ;
				
				} else if ( matrix[i][j-1] == matrix[i-1][j] ) {
				
					track[i][j] = AMBELE ;
					matrix[i][j] = matrix[i][j-1] ;
				
				} else {
				
					track[i][j] = UP ;
					matrix[i][j] = matrix[i-1][j] ;
				
				}
			
			}
		
		}
	
	}
	
	g << matrix[size1][size2] << '\n' ;
	int i = size1 ;
	int j = size2 ;
	std :: stack <int> stiva ;

	while ( track[i][j] != NOTHING ) {
	
		if ( track[i][j] == UP ) {
		
			i -- ;
		
		} else if ( track[i][j] == LEFT ) {
		
			j -- ;
		
		} else if ( track[i][j] == COLT ) {
		
			stiva.push (first[i-1]) ;
			i -- ;
			j -- ;
		
		} else {
		
			i -- ;
		
		}
	
	}

	while ( ! stiva.empty () ) {
	
		g << stiva.top () << ' ' ;
		stiva.pop () ;
	
	}
	g << '\n' ;	
	
	for ( i = 0 ; i <= size1 ; i ++ ) {
	
		delete [] track[i] ;
		delete [] matrix[i] ;
	
	}
	
	delete [] track ;
	delete [] matrix ;
	

}


