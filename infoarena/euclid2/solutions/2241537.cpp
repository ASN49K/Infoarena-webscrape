#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin >> n;
    for( int i = 1 ; i <= n ; ++i )
    {
        int a , b;
        fin >> a >> b;
        while ( a != 0 && b != 0 )
            if( a > b )
                a = a % b;
            else
                b = b % a;
            if( a != 0 )
                fout << a;
            else
                fout << b;
    }
}
