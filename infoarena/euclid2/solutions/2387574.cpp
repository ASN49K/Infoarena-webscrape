#include <iostream>
#include <fstream>
using namespace std;
long long euclid(long long a,long long b)
{
   long long c;
    while (b) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long long  T,a,b;
    in>>T;
    for(int i=1;i<=T;i++){
        in>>a;in>>b;
        out<<euclid(a,b);
        out<<endl;
    }
    
    return 0;
}
