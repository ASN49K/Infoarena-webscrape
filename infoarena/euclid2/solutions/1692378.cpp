#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
long int x,y;

int cmmdc( int a , int b )
{
    if( b != 0 )
        return cmmdc( b , a % b );
    else
        return a ;
}

int main()
{
    fin >> n ;
    for( int i = 0 ; i < n ; ++i )
    {
        fin >> x >> y ;
        fout << cmmdc( x , y ) << '\n';
    }
    return 0;
}
