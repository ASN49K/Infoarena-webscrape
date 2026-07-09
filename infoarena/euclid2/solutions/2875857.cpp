#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    long long a, b, t, aux;
    fin >> t;
    for(long long i = 1; i <= t; i++) {
        fin >> a >> b;
        while(b != 0) {
            aux = b;
            b = a % b;
            a = aux;
        }
        fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
