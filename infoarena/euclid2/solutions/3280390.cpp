#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int x, int y){
    while(y){
        int t = y;
        y = x % y;
        x = t;
    }

    return x;
}

int main(){
    int n;
    fin >> n;
    int x,y;
    for(int i = 0; i<n; i++){
        fin >> x >> y;
        fout << gcd(x, y) << endl;
    }
}
