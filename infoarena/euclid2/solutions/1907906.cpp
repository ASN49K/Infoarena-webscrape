#include <iostream>
#include <fstream>

using namespace std;

int i,t;
long long  a , b , r;

int main() {
    
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> t;
    for (i = 1; i <= t; i++)
    {
        fin >> a ;
        fin >> b ;
        
        r = a % b ;
        while ( r != 0 )
        {
            a = b ;
            b = r ;
            r = a % b ;
        }
        fout << b << endl;
    }
}
