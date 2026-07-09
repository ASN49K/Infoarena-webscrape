#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b){
    while (b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int T;
    fin >> T;
    for (int i = 0; i < T; ++i){
        int a, b;
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
