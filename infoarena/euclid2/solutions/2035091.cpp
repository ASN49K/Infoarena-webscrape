#include <iostream>
#include <fstream>

using namespace std;

fstream fin("euclid2.in", ios::in);
fstream fout("euclid2.out", ios::out);

void euclid(int a, int b, int &d) {
    if (!b) {
        d = a;
    } else
        euclid(b, a % b, d);
}

int main()
{
    int T,x1,x2,d;
    fin>>T;
    while(fin>>x1>>x2) {
        euclid(x1,x2,d);
        fout<<d<<'\n';
    }
    return 0;
}
