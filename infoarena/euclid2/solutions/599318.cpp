#include <iostream>
#include <fstream>

using namespace std;
long a,b,t;

long cmmdc(long x, long y){
    if(!y) return x;
    return cmmdc(y, x%y);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> t;
    for(;t--;){
        in >> a >> b;
        out << (cmmdc(a, b)) << '\n';
    }
    in.close();
    out.close();
    return 0;
}
