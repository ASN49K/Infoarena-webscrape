#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
ifstream in("euclid3.in");
ofstream out("euclid3.out");

#define ll long long
#define ull unsigned long long
#define pb push_back
const int inf = 1e9 + 5;
const int NMax = 1e7 + 5;
const int nrBytes = 4;
const int bits = 8;
const int Radix = 0b11111111;

int T;

int euclid(int,int);

int main() {
    in>>T;
    while (T--) {
        int a,b;
        in>>a>>b;

        out<<euclid(a,b)<<'\n';
    }

    in.close();out.close();
    return 0;
}

int euclid(int a,int b) {
    if (b == 0) {
        return a;
    }

    return euclid(b,a%b);
}
