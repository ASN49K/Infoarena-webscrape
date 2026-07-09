#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

const int NMax = 1e5 + 5;

int T,N;

int main() {
    in>>T;
    while (T--) {
        in>>N;

        int xorSum = 0;
        for (int i=1;i<=N;++i) {
            int val;
            in>>val;
            xorSum ^= val;
        }

        if (xorSum != 0) {
            out<<"DA\n";
        }
        else {
            out<<"NU\n";
        }
    }
    in.close();out.close();
    return 0;
}

