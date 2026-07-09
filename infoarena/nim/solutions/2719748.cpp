#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x, xorsum;

void Read(){
    xorsum = 0;
    fin >> n;
    for (int i = 1; i <= n; i++){
        fin >> x;
        xorsum = xorsum ^ x;
    }
}

void Print(){
    if (xorsum)
        fout << "DA" << '\n';
    else
        fout << "NU" << '\n';
}

int main(){
    fin >> t;
    while (t--){
        Read();
        Print();
    }
    return 0;
}
