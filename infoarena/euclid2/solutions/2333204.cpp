#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int T;
    long long int a, b, r;
    fin >> T;
    for (int i = 1; i <= T; i++) {
        fin >> a >> b;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a;
        fout << "\n";
    }
    return 0;
}
