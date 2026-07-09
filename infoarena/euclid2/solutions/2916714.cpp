#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a, b;
    ifstream fin("adunare.in");
    ofstream fout("adunare.out");
    fin >> a >> b;
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    if (a == 1) {
        return 0;
    } else {
        return a;
    }
    return 0;
}
