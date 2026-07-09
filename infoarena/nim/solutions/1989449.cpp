#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

#define ll long long
#define pb push_back
const int NMax = 1e5 + 5;
const int inf = 1e9 + 5;

int T,N;

int main() {
    in>>T;
    while (T--) {
        in>>N;

        int nimSum = 0;
        for (int i=1;i <= N;++i) {
            int val;
            in>>val;

            nimSum ^= val;
        }

        if (nimSum) {
            out<<"DA\n";
        }
        else {
            out<<"NU\n";
        }
    }

    in.close();out.close();
    return 0;
}

