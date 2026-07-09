#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

const int NMAX = 1e4 + 5;

int Q, N, A[NMAX];

static inline void Read ()
{
    f >> N;

    for(int i = 1; i <= N; ++i)
        f >> A[i];

    return;
}

static inline void Test_Case ()
{
    Read();

    long long s = 0;

    for(int i = 1; i <= N; ++i)
        s ^= (1LL * A[i]);

    if(s == 0)
        g << "NU";
    else
        g << "DA";

    g << '\n';

    return;
}

int main()
{
    f.tie(NULL);

    f >> Q;

    while(Q--)
        Test_Case();

    return 0;
}
