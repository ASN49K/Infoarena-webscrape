#include <cstdlib>
#include <fstream.h>

using namespace std;

ifstream in("euclid.in");
ofstream out("euclid.out");

int gcd(int a,int b){
    int c;
    while(a%b!=0) {
          c=b;
          b=a%b;
          a=c;        
    }    
    return b;
    
}

int main(){
    int a,b;
    in>>a;
    in>>b;
    out<<gcd(a,b);
}
