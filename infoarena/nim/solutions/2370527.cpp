#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream f("nim.in"); ofstream g("nim.out");

int n,t,s;

int main() {
    int i,j,x;
    f>>t;
    for(i = 1; i <= t; ++i) {
        f>>n;
        s = 0;
        for(j = 1; j <= n; ++j) {
            f>>x;
            s = s ^ x;
        }
        if(s > 0) {
            g<<"DA\n";
        }
        else {
            g<<"NU\n";
        }
    }
    return 0;
}
