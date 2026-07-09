#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>

#define ll long long
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

const int NMax = 1e6 + 5;
const int inf = 1e9 + 5;

int T,N;

int main() {
    in>>T;
    while (T--) {
        in>>N;

        int xorSum = 0;
        for (int i=1;i <= N;++i) {
            int val;
            in>>val;

            xorSum ^= val;
        }

        if (xorSum) {
            out<<"DA\n";
        }
        else {
            out<<"NU\n";
        }
    }
    in.close();out.close();
    return 0;
}
