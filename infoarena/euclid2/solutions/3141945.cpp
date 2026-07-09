#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n , i , a , b ;

int main()
{
    in >> n ;

    for ( i = 0 ; i < n ; i ++ )
    {
        in >> a >> b ;

       int r = 1 ;

       while ( r != 0 )
       {
           r = a % b ;
           a = b ;
           b = r ;
       }
       out << a << '\n';
    }
    return 0;
}
