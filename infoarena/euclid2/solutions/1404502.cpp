#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

#ifdef HOME
const string inputFile = "input.txt";
const string outputFile = "output.txt";
#else
const string problemName = "euclid2";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
#endif

int N;

int gcd(int x, int y) {
    if(!y) return x;
    return gcd(y, x % y);
}

int main() {
    int x, y;

#ifndef ONLINE_JUDGE
    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);
#endif

    scanf("%d", &N);

    while(N--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", gcd(x, y));
    }

    return 0;
}
