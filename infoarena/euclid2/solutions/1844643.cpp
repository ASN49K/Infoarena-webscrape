#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b){
    if (!b) return a;
    return cmmdc(b,a%b);
}

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int a,b,t;
    fin>>t;
    for (;t>0;t--){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
