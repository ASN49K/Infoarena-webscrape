#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int n , r, a, b, i;
int main(){
    f >> n;
    for( i = 1; i <= n; ++i ){
        f >> a >> b;
        while ( b > 0 ){
            r = a % b;
            a = b;
            b = r;
        }
        g << a << "\n";
    }
    return 0;
}
