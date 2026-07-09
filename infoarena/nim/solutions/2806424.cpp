#include <bits/stdc++.h>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,n,x,s;

int main()
{
    f >> t;
    for (int k=1;k<=t;k++) {
        f >> n >> s;
        for (int i=1;i<n;i++) {
            f >> x;
            s ^= x;
        }
        if (s==0) {
            g << "NU" << '\n';
        }
        else {
            g << "DA" << '\n';
        }
    }
    return 0;
}
