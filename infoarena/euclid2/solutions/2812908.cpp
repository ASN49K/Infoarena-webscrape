#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("euclid2.in");
ofstream fout ("euclid2.out");

int main (){
    int teste, a, b, r;
    fin >> teste;
    while(teste--){
        fin >> a >> b;
        while(b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    return 0;
}
