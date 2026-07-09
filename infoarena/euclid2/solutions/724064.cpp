#include<fstream>
using namespace std;
ifstream fi ( "euclid2.in" );
ofstream fo ( "euclid2.out" );
int t;
long long int a,b;
int euclid( int a, int b )
{
if( !b )
     return a;
return euclid ( b, a%b ) ;

}
int main() {
fi>>t;
int i;
for( i=1; i<= t; i++ )
{
	 fi>>a>>b;
     fo<<euclid ( a, b )<<'\n';
}
fi.close();
fo.close();
return 0;}
