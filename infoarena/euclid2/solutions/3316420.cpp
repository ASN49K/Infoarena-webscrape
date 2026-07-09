#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream gout("euclid2.out");

int euclid(int a, int b){
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int T, a, b;

    fin >> T;

    for (int i = 1; i <= T; i++){
        fin >> a >> b;
        gout << euclid (a,b) << "\n";
    }
    
    return 0;
}