#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    if(b==0) return a;
    return cmmdc(b, a%b);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T, a, b;

    in >> T;

    for(int i=1; i<=T; i++) {
        in >> a >> b;
        out << cmmdc(a, b) << endl;
    }

    return 0;
}
