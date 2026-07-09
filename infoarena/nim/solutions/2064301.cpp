#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>

#if 1
#define pv(x) cout<<#x<<" = "<<x<<"; ";cout.flush()
#define pn cout<<endl
#else
#define pv(x)
#define pn
#endif

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
const int NMax = 1e5 + 5;

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
