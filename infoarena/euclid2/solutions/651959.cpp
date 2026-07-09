#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f1("euclid2.in");
    ofstream f2("euclid2.out");
    int T,a,b,r;
    f1>>T;
    for(int i = 0; i < T; i++) {
        f1>>a>>b;
        while(a%b!=0) {
            r=a%b;
            a=b;
            b=r;
        }
        f2<<b<<"\n";
    }
}
