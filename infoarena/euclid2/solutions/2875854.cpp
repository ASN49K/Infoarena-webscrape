#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, t, aux;
    fin >> t;
    for(int i = 1; i <= t; i++) {
        fin >> a >> b;
        while(b != 0) {
            aux = b;
            b = a % b;
            a = aux;
        }
        fout << a << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
