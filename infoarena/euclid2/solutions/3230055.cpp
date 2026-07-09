#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int divi(int a, int b) {
    if(a == b) {
        return a;
    } else if(a > b) {
        return divi(a - b, b);
    } else {
        return divi(a, b - a);
    }
}

int main()
{
    unsigned int t, a, b, cmmdc;

    fin >> t;

    while(t--){
        fin >> a >> b;
        cmmdc = divi(a, b);
        fout << cmmdc << "\n";
    }

    return 0;
}
