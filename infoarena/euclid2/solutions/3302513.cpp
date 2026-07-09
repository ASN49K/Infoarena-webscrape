#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void compute_cmmdc(int a, int b){
    int r;

    while(b){
        r = a % b;
        a = b;
        b = r;
    }

    fout << a << '\n';
}

int main(){
    int t, x, y;
    
    fin >> t;
    for(int i = 1; i <= t; i++){
        fin >> x >> y;
        compute_cmmdc(x, y);
    }
}