#include <fstream>
#include <iostream>

using namespace std;

int T,A,B;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){

    if (!b) return a;
    return cmmdc(b, a % b);

}

int main()
{
    f>>T;
    while (T) {
        f>>A>>B;
        g<<cmmdc(A, B)<<"\n";
        --T;
    }
    return 0;
}

