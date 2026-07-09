#include <fstream>

using namespace std;

ofstream fout("euclid2.out");

int T , a , b;


void Euclid( )
{
    int r = a % b;
    while ( r != 0 )
    {
        a = b;
        b = r;
        r = a % b;
    }
    fout << b << '\n';
}

int main()
{
    ifstream fin("euclid2.in");
    fin >> T;
    for ( int i = 1 ; i <= T ; ++i )
    {
        fin >> a >> b;
        Euclid();
    }
    return 0;
}
