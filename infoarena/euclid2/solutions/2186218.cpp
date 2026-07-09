#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n, a[1000], b[1000], R;
    in >> n;
    for( int i = 1; i <= n; i++ ){
        in >> a[i] >> b[i];
    }
    for( int i = 1; i <= n; i++ ){
        while( b[i] != 0 ){
            R = a[i] % b[i];
            a[i] = b[i];
            b[i] = R;
        }
        out << a[i] << endl;
    }
}
