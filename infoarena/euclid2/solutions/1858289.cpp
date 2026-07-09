#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n, a, b;
    int rest;
    f >> n;
    for (int i = 0; i < n; i++){
        f >> a >> b;
        if (a < b)
            swap (a, b);
        while (b){
            rest = a % b;
            a = b;
            b = rest;
        }
        g << a << '\n';
    }
    return 0;
}
