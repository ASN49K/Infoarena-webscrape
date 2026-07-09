#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b) {
    int aux;
    while (b) {
        aux = a%b;
        a = b;
        b = aux;
    }
    return a;
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int N, a, b;
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> a >> b;
        fout << euclid(a,b) << "\n";
    }    
}