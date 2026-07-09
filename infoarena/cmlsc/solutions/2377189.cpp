#include <bits/stdc++.h>
#define len 1025

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

typedef unsigned short ushort;

vector<ushort> v;

ushort N, M, a[len], b[len], sol[len], rez;

bool ebun(ushort k)
{
    ushort l = 1;
    for(ushort i = 1; i <= M; ++i)
    {
        if(a[i] == b[sol[l]])
            ++l;
        if(l > k)
            return true;
    }
    return l > k;
}

void back(ushort k)
{
    for(ushort i = sol[k - 1] + 1; i <= N; ++i)
    {
        sol[k] = i;
        if(ebun(k))
        {
            if(k > rez)
            {
                rez = k;
                v.clear();
                for(ushort i = 1; i <= k;)
                {
                    #define pb push_back
                    v.pb(b[sol[i++]]);
                }
            }
            if(k < M)
                back(k + 1);
        }
    }
}

int main()
{
    in >> M >> N;
    if(M >= N)
    {
        for(ushort i = 1; i <= M;)
            in >> a[i++];
        for(ushort i = 1; i <= N;)
            in >> b[i++];
    }
    else{
        for(ushort i = 1; i <= M;)
            in >> b[i++];
        for(ushort i = 1; i <= N;)
            in >> a[i++];
        swap(M, N);
    }
    back(1);
    out << rez << '\n';
    for(auto i : v)
        out << i << ' ';
    return 0;
}
