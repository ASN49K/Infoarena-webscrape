#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    if(!b) return a;
    else return cmmdc(b, a%b);
}

int main()
{
    ifstream f("euclid1.in");
    ofstream g("euclid2.out");

    int T, a, b;

    f >> T;
    for(int i=1; i<=T; i++) {
        f >> a >> b;
        g << cmmdc(a, b) << endl;
    }

    f.close();
    g.close();
    return 0;
}
