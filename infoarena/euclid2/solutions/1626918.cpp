#include <iostream>
#include <fstream>

using namespace std;

const char inFile[] = "euclid2.in";
const char outFile[] = "euclid2.out";

int euclid( int a, int b ){

    if( b == 0 )
        return a;
    return euclid( b, a%b );

}

void solve( ifstream& fin , ofstream& fout ){

    int tests, a, b;

    fin >> tests;

    while( (tests--) ){

        fin >> a >> b;
        fout << euclid( a, b ) << "\n";

    }

}

int main()
{

    ifstream fin(inFile);
    ofstream fout(outFile);

    solve( fin, fout );

    return 0;
}
