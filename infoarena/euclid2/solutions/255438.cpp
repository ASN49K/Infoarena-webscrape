#include <iostream>
#include <fstream>
using namespace std;
int main() {
    long int t,a,b,i;
    ifstream f;
    f.open("euclid.in");
    ofstream g;
    g.open("euclid.out");
    f>>t;
    for(i=1; i<=t; i++) {
             f>>a>>b;
             while(a!=0 && b!=0) {
                        if(a>=b) {
                                 a=a-b;
                                 }
                        else if(b>a) {
                             b=b-a;
                             }
                        }
             g<<b<<endl;
             }
    f.close();
    g.close();
    return 0;
}
