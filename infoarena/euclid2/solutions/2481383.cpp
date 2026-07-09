#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n, a, b, x, i;
    fin>>n;
    for(i=1;i<=n;i++){
        while(fin>>a>>b) {
            while (b) {
                x = a % b;
                a = b;
                b = x;
            }
            fout << a << endl;
        }
    }
    return 0;
}