#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc (int a, int b){
    int rest;
    while (b){
        rest=a%b;
        a=b;
        b=rest;}
    return a;}

int main() {
    long long t,a,b,i;
    f >> t;

    for (i=1;i<=t;i++){
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';}
    g.close();
    return 0;
    }
