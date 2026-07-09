#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

namespace Iterative {

          ulong gcd(ulong first, ulong second) {

                ulong temp;

                while( second ) {
 
                       temp = first % second;

                       first = second;

                       second = temp;          
                } 

                return first; 
          } 
};

namespace Recursive {

          ulong gcd(ulong first, ulong second) {

          } 
};

int main() {

    ulong nPairs,
          first,
          second, 
          i;

    const char *FIN = "euclid2.in";
    const char *FOUT = "euclid2.out";

    if( !FIN || !FOUT ) {

         cout<<"Error opening files!"<<endl; 
    }

    ifstream fin( FIN ); 
    ofstream fout( FOUT );

    fin>>nPairs;

    for(i = 1; i <= nPairs; i++) {

        fin>>first>>second;

        fout<<Iterative::gcd(first, second)<<"\n";
    }

    return(0);
};
