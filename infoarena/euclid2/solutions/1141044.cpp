#include<fstream>

using namespace std;

ifstream fin( "euclid2.in" );
ofstream fout( "euclid2.out" );

inline int cmmdc( int x, int y ) {
    int r;
    while ( y != 0 ) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main()
{
    int t, a, b;
    fin>>t;
    for( int i = 0; i < t; ++ i ) {
        fin>>a>>b;
        fout<<cmmdc( a, b )<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
