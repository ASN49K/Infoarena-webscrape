#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int fa(int a, int b) {
    if(!b) return a;
    else return fa(b, a%b);
}

int main() {
    int n, a, b;
    fin >> n;
    for(int i = 1; i<= n;++i) {
        fin >> a >> b;
        fout << fa(a, b) << endl;
    }
    return 0;
}
