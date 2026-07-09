#include <iostream>
#include <fstream>
using namespace std;
int main() {
    long int t,a,b,i,r;
    ifstream f;
    f.open("euclid2.in");
    ofstream g;
    g.open("euclid2.out");
    f>>t;
    for(i=1; i<=t; i++) {
             f>>a>>b;
              while(b!=0) {
                          r = b;
                          b = a % b;
                          a = r;
                          }

             g<<a<<endl;
             }
    f.close();
    g.close();
    return 0;
}
