#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
    int rest;
    while(b!=0) {
        rest=a%b;
        a=b;
        b=rest;
    }
    return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t,a,b;
    fin>>t;
    for(int i=0;i<t;i++) {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
