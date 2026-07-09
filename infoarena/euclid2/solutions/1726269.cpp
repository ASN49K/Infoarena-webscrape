#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
int euclid2(int a, int b)
{
    if (!b) return a;
    return euclid2(b, a % b);
}

int main() {
    int T,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(;T;--T){
        f>>a;f>>b;
        g<<euclid2(a,b)<<endl;
    }
    return 0;
}

