#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a , b;

int parcurgere(int a, int b) {
    int m = min(a,b);
    for(int d = m; d > 0; d--) {
            if(a%d == 0 && b%d == 0)
                return d;
        }
}

int scadere(int a, int b) {
    while(a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int impartire(int a, int b) {
    int aux;
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int main()
{
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin >> a; fin >> b;
        //fout << parcurgere(a,b) << '\n';
        //fout << scadere(a,b) << '\n';
        fout << impartire(a,b) << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}
