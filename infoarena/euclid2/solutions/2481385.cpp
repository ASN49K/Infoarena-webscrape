#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, a, b, x, i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(i=1;i<=n;i++){
        while(fin>>a>>b) {
            while (b) {
                x = a % b;
                a = b;
                b = x;
            }
            fout << a << '\n';
        }
    }
    return 0;
}