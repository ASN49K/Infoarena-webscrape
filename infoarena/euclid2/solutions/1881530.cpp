#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t,a,b;

int main()
{
    f >> t;
    while(t--){
        f >> a >> b;
        int r = a % b;
        while(r){
            a = b;
            b = r;
            r = a % b;
        }
        g << b << '\n';
    }
    return 0;
}
