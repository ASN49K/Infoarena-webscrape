#include <iostream>
#include <fstream>

using namespace std;

//#define CONSOLE

int main() {
    long long a, b, r, i;
    #ifdef CONSOLE
        cin>>a>>b;
    #else
        ifstream fin("euclid2.in");
        ofstream fout("euclid2.out");
        fin>>i;
    #endif
    while (i > 0) {
        #ifdef CONSOLE
            cin>>a>>b;
        #else
            fin>>a>>b;
        #endif
        while (b != 0) {
            r = a%b;
            a = b;
            b = r;
        }
        #ifdef CONSOLE
            cout<<a<<"\n";
        #else
            fout<<a<<"\n";
        #endif
        i--;
    }
    return 0;
}
