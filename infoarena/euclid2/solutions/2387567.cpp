#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long  T,a,b,c;
    in>>T;
    for(int i=1;i<=T;i++){
    in>>a;
    in>>b;
        
    while (b)
    {c=a%b;
        a=b;
        b=c;
    }
        out<<a<<endl;
    }
    
    return 0;
}
