#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
    ifstream in("euclid.in");
    ofstream out("euclid.out");
    int t;
    int x, y;
    if(in.is_open()){
        in >> t;
        while(t--){
            in >> x >> y;
            int d =  max(x, y) % min(x, y);
            d == 0 ? out << min(x, y) << "\n" : out << d << "\n";
        }
    }
}