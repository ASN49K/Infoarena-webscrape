#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f1("euclid2.in");
    ofstream f2("euclid2.out");
    int T,a,b;
    f1>>T;
    for(int i = 0; i < T; i++) {
        f1>>a>>b;
        while(a!=b) {
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        f2<<a<<"\n";
    }
}
