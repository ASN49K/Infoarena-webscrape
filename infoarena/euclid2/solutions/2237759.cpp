#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b) {
    int r;
    while(b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    ios::sync_with_stdio(0);

    int t;
    fin>>t;
    while(t--) {
        int a,b;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
