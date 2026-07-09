
#include <fstream>


using namespace std;

long  gcd(long  long a, long long b)
{
    if(b == 0)
        return a ;
    else return gcd(b, a % b) ;
}

int main()
{
   ifstream cin("euclid2.in") ;
   ofstream cout("euclid2.out") ;

    short T;
    cin >> T ;

    while(T -- ) {
       long long a, b ;
        cin >> a >> b ;
        cout << gcd(a, b) << '\n' ;
    }

    return 0;
}
