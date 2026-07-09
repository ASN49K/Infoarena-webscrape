#include <iostream>
#include <fstream>
using namespace std;

int a, b, r, n;
int main () {
    ifstream I("euclid2.in");
    ofstream O("euclid2.out");
    I >> n;
    while (n) {
    I >> a >> b;
    if (b>a) 
        swap (a,b);
        
    while (a%b) {
        r=b;
        b=a%b;
        a=r;
    }
    n--;

    O << b << "\n";
}
    return 0;    
}
    
