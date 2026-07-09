#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int x, int y){
    while(y){
        int c = x % y;
        x = y;
        y = c;
    }
    return x;
}

int main(){
    int n, x, y;
    in >> n;
    for(int i = 1; i<=n; i++){
        in >> x >> y;
        out << gcd(x, y) <<"\n";
    }
}
