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
        while(b){
            x = a%b;
            a = b;
            b = x;
        }
        fout<<a<<endl;
    }
    return 0;
}