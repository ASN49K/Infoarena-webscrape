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
 
                if( second == 0 ) return first;
 
                    else return Recursive::gcd(second, first % second);    
   
          }
};
 
int main() {
 
    ulong nPairs,

          first,

          second,

          i;
 
    const char *FIN = "euclid2.in";

    const char *FOUT = "euclid2.out";
 
    ifstream fin( FIN );

    ofstream fout( FOUT );

    if( !fin || !fout ) {
 
         cout<<"Error opening files!"<<endl;
    }
 
    fin>>nPairs;
 
    for(i = 1; i <= nPairs; i++) {
 
        fin>>first>>second;
 
        fout<<Recursive::gcd(first, second)<<"\n";
    }
 
    return(0);
};