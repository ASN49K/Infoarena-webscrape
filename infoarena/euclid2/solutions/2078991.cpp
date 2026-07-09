#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
   
    int T, a, b, r;
    fin >> T;
    
    for( int i = 1 ; i <= T ; ++i ){
        
        fin >> a;
        fin >> b;
        
        
        while( a % b ){
            r = a % b;
            a = b;
            b = r;
        }
        
        fout << b << "\n";
        
    }
    
    
    
    
}
