#include <iostream>
#include <fstream>
#define LL long long 
 
using namespace std;

LL cmmdc(LL a, LL b, LL r){
    if(r == 0)
        return b;
    return cmmdc(b, r, b % r);
}

int main()
{
    LL a, b, t;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> t;
    for(int i = 0; i < t; ++i){
        fin >> a >> b;
        fout << cmmdc(a, b, a % b) << '\n';
    }
    return 0;
}