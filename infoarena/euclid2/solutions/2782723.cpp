#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");


int cmmdc(int a, int b)
{
    while (a % b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    int n;
    in>>n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        in>>a>>b;
        out<<cmmdc(a, b)<<"\n";
    }
    return 0;
}
