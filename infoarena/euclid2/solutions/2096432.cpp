#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pb push_back
#define mp make_pair
const int NMax = 5e2 + 5;
const ll inf = 1e18 + 5;
using zint = short;

int T,N;

int euclid(int a,int b) {
    return b ? euclid(b,a%b) : a;
}

int main() {
    in>>T;
    while (T--) {
        int x,y;
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }

    in.close();out.close();
    return 0;
}
