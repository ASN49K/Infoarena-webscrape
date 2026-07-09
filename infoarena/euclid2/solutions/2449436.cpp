#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int t; long long int a, b, r;
    fin >> t;
    for (; t; --t) {
        fin >> a >> b;
        while (b != 0) {
            r = a%b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    return 0;
}
