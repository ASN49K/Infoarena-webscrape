
 # include <fstream>
 
 using namespace std;
 
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 
 int t;
 int x, y, d;
 
 void euclid( int a, int b, int &d )
 {
	 if ( b == 0 )
		 d = a;
	 else
		 euclid( b, a % b, d );
 }
 
 inline void citire()
 {
	 int t, i;
	 
	 f >> t;
	 for ( i = 1 ; i <= t ; i++ )
	 {
		 f >> x >> y;
		 euclid( x, y, d );
		 g << d << "\n";
	 }
	 
 }
 
 int main()
 {
	 citire();
	 return 0;
 }
 
 