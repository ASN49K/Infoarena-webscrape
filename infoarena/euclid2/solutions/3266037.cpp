#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int T, a, b;

int main() {
    fin >> T;
    for(int i=0; i<T; ++i) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    return 0;
}
