#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a, int b){
    int c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int n;
    in>>n;
    for(int i = 1; i <= n; i++){
        int k, l;
        in>>k>>l;
        out<<euclid(k, l)<<"\n";
    }

    return 0;
}

