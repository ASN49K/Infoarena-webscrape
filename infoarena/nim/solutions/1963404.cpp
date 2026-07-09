#include <iostream>
#include <fstream>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

int main() {
    int T;
    in>>T;
    while (T--) {
        int N, val, xorSum = 0;
        in>>N;
        while (N--) {
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
