#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int euclid(int x, int y){
    while(y != 0){
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t;
    int x, y;
        in >> t;
        while(t--){
            in >> x >> y;
            out << euclid(x, y) << "\n";
        }
    in.close();
    out.close();
}