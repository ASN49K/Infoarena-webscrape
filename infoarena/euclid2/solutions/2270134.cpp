#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

void citire(){
    in >> n;
}

int mod(int x, int y){
    if(x > y)
        return x - y;
    return y - x;;
}

int euclid(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a % 2 == 0 && b % 2 == 0)
        return 2 * euclid(a >> 1, b >> 1);
    if(a % 2 == 0)
        return euclid(a >> 1, b);
    if(b % 2 == 0)
        return euclid(a, b >> 1);
    if(a % 2 == 1 && b % 2 == 1)
        return euclid(min(a, b), mod(a, b));
}

int main() {

    ios::sync_with_stdio(false);

    citire();

    for(int i = 0; i < n; i++){
        int a, b;

        in >> a >> b;

        out << euclid(a, b) << "\n";
    }

    return 0;
}