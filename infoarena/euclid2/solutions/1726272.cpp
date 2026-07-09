#include <cstdlib>
#include <iostream>
#include <fstream>
int T,a,b;
using namespace std;
int euclid2(int a, int b)
{
    if (b) return euclid2(b, a % b);
    return a;
}

int main() {

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(int i = 0;i<T;i++){
        f>>a>>b;
        g<<euclid2(a,b)<<'\n';
    }
    return 0;
}

