
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
        
        r = a % b;
        
        while ( r != 0 ){
            
            a=b;
            b=r;
            r=a % b;
            
        }
        fo <<b<<endl;
        i=i+1;
        
    }
    
    return 0;
    
}
