#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

const int TMax = 1e5;

int t, a, b;

int GCD(int a, int b){
    while (a && b){
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return max(a, b);
}

int main(){
    fin >> t;
    for (int i = 1; i <= t; i++){
        fin >> a >> b;
        fout << GCD(a, b) << '\n';
    }
    return 0;
}
