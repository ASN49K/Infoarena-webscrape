#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long int cmmdc(long long int x,long long int y) {
    while (y) {
        long long int Rest=x%y;
        x=y;
        y=Rest;
    }
    return x;
}
void citire() {
    int t;
    long long int a,b;
    f>>t;
    for (int i=1;i<=t;i++) {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
}
void rez() {

}
int main() {
    citire();
    rez();
    return 0;
}
