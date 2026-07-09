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
    int v[T + 1];
    for (int i = 1; i <= T; i++) {
        fin >> a >> b;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        v[i] = a;
    }
    for (int i = 1; i <= T; i++)
        fout << v[i] << endl;
    return 0;
}
