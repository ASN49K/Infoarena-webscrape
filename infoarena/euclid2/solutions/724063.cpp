#include<fstream>
using namespace std;
ifstream fi ( "euclid2.in" );
ofstream fo ( "euclid2.out" );
int t;
long long int a[100000][2];
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
	 fi>>a[i][1]>>a[i][2];
     fo<<euclid ( a[i][1], a[i][2] )<<'\n';
}
fi.close();
fo.close();
return 0;}
