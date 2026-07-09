
#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int i,t;

long long  a , b , r;

int main() {
    
    fi >>t;
    
    while (i<t){
        
        fi >>a;
        fi >>b;
        
        while ( a != b ){
            
            if( a > b )     a = a - b ;
            else            b = b - a ;
        }
        fo <<b<<endl;
        i=i+1;
        
    }
    
    return 0;
    
}
