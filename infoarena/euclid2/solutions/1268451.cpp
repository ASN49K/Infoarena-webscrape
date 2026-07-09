#include <fstream>

using namespace std;
ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

long long T, i, a, b, c, x, y, D;
long long cmmdc(long long a, long long b) {
    long long r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/*void euclid( long long a, long long b, long long  &x, long long &y){
    if( b == 0){
        x = 1;
        y = 0;
    }
    else{
    long long x0,y0;
    euclid(b, a % b , x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
    }
} */
int main()
{
    fin >> T;
    for(i = 1; i <= T; i ++){
        fin >> a >> b;
    D = cmmdc(a,b);
    fout << D << "\n";
    }
    return 0;
}
