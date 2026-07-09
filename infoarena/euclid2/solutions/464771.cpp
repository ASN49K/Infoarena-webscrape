#include <cstdlib>
#include <fstream>

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
    int a,b,t,k;
    in>>t;
    for(k=1;k<=t;k++){
                      in>>a>>b;
                      out<<gcd(a,b)<<"\n";
    }
}
