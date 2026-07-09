#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;

int eucl(int x, int y) {
    if(x == 0 || y == 0) return x + y;
    else {
        int r;
        r = x % y;
        while(r) {
            x = y;
            y = r;
            r = x % y;
        }
        return y;
    }
}

int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i){
            int x, y;
        f >> x >> y;
        g << eucl(x, y) << '\n';
    }
}
