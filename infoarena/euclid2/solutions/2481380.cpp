#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int n, a, b, x;
    fin>>n;
    while(n--){
        fin>>a>>b;
        x = a%b;
        while(x){
            a = b;
            b = x;
            x = a%b;
        }
        fout<<b<<endl;
    }
    return 0;
}