#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
    int n;
    f>>n;
    int a, b;
    for (int i =1; i<=n; i++){
        f>>a>>b;
        while(b!=0) {
            int r = a % b;
            a = b;
            b = r;
        }
        g<<a<<"\n";
    }
    return 0;
}
