#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

long cmmdc(long a, long b){
    if (b==0) return a;
    else return cmmdc(b, a%b);
}

int main(){
 
    int t,i;
    long a,b;
    
    in >> t;
    
    for (i=1; i<=t; i++)
        in >> a >> b,
        out << cmmdc(a, b) << "\n";
    
    return 0;
}