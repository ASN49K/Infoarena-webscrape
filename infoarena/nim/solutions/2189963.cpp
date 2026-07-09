#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int T, N;
int main()
{
    f >> T;
    for(int p = 1; p <= T; p++) {
        f >> N;
        long long x, sum = 0;
        for(int i = 1; i <= N; i++)
            f >> x, sum ^= x;
        if(!sum) g << "NU\n";
        else g <<"DA\n";
    }
    return 0;
}
