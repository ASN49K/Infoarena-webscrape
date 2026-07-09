#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int t;

int gcd(int a, int b){
    int c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    fin >> t;
    while(t--){
        int a, b;
        fin >> a >> b;
        fout << gcd(a,b) << "\n";
    }
    return 0;
}
// român convertit la moldovenism