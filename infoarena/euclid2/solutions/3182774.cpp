#include <iostream>
using namespace std;

#include <fstream>

int cmmdc(int a, int b){
    while (b != 0){
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T;
    fin >> T;
    int a[100001] = {0}, b[100001] = {0};
    for (int i = 1; i <= T; ++i) {
        fin >> a[i] >> b[i];
    }
    for (int i = 1; i <= T; ++i){
        fout << cmmdc(a[i], b[i]) << "\n";
    }
}