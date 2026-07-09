#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int r;

int euclid2 (int a, int b)
{
    if (a%b==0) return b;
    else {
        return euclid2(b, a%b);
    }
}

int main()
{
    int t, a, b;
    fin >> t;

    for (int i=1; i<=t; ++i) {
        fin >> a >> b;
        fout << euclid2(a, b) << '\n';
    }

    return 0;
}
