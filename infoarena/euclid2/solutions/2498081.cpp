#include <fstream>
#define f in
#define g out

using namespace std;
ifstream in ( "euclid2.in" );
ofstream out( "euclid2.out" );
int T, a, b;

int cmmdc ( int a, int b ){
    int r = 0;
    while ( b ){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    for ( f>>T; T--; ){
        f>>a>>b;
        g<<cmmdc ( a, b )<<"\n";
    }
    return 0;
}

