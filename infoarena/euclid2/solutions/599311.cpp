#include <iostream>
#include <fstream>

using namespace std;
long a,b,t;

long cmmdc(long x, long y){
    long r;
    while(y != 0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> t;
    for(;t--;){
        in >> a >> b;
        out << (cmmdc(a, b)) << endl;
    }
    in.close();
    out.close();
    return 0;
}
