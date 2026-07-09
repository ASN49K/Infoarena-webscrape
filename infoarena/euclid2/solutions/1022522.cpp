#include <fstream>
#include <iostream>

using namespace std;

int T,A,B;

ifstream f("euclid.in");
ofstream g("euclid.out");

int cmmdc(int a, int b){

    if(!b) return a;
    return cmmdc(a, a%b);

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

