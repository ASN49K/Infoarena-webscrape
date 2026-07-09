#include <cstdio>
#include <iostream>


using namespace std;

long  gcd(long  long a, long long b)
{
    if(b == 0)
        return a ;
    return gcd(b, a % b) ;
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    short T;
    cin >> T ;

    while(T -- ) {
       long long a, b ;
        cin >> a >> b ;
        cout << gcd(a, b) << '\n' ;
    }

    return 0;
}
