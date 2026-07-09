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
        while ( b != 0 )
        {
            int rest;
            rest = a % b;
            a = b;
            b = rest;
        }
        fout << b << '\n' ;
    }
}
