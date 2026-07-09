#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, r=1, t;
    fin >> t;
    for (int i=1; i<=t; ++i) {
        fin >> a >> b;
        r=1;
        while (r!=0) {
            r=a%b;
            a=b;
            b=r;
        }
        fout << a << '\n';
    }
    return 0;
}
