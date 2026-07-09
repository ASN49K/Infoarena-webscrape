 #include <fstream>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 
 int t;
 int a, b, d;
 
 void euclid( int a, int b, int &d ){
	 if ( b == 0 )
		 d = a;
	 else
		 euclid( b, a % b, d ); 
 }
 
 int main()
 {
	 f >> t;
	 for ( int i = 1 ; i <= t ; i++ ){
		 f >> a >> b;
		 euclid( a, b, d );
		 g << d << "\n";
		 d = 0;
	 }
	 return 0;
 }