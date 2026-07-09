#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b, n, i, aux;
int main() {
    fin >> n;
    for(i = 0; i < n; ++i) {
        fin >> a >> b;
        while(b) {
            aux = a % b;
            a = b;
            b = aux;
        }
        fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
