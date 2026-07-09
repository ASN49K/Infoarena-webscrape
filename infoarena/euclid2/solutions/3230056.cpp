#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int divi(int a, int b) {
    int r;
    if(b == 0) {
        return a;
    }  else {
        r = a % b;
        a = b;
        b = r;
        return divi(a, b);
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
