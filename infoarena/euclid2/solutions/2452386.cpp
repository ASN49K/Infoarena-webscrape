#include <bits/stdc++.h>
using namespace std;

int N, K, v[21];
ifstream fin("suman.in");
ofstream fout("suman.out");

int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(b, a % b);
}


int main()
{
    fin >> N >> K;

    for(int i = 1; i <= K; ++i) fin >> v[i];

    long long s = 0;

    for(int i = 1; i < (1 << K); ++i)
    {
        int contor = 0;
        long long produs = 1;

        for(int j = 0; j < K; ++j)
        {
            if(i  & (1 << j))
            {
                contor++;
                produs = (1LL * produs * v[j + 1])/cmmdc(produs, v[j + 1]);
            }
        }


        long long s_current = 0;

        for(int j = 1; j <= N/produs; ++j) s_current += j * produs;

        if(contor % 2) s += s_current;
        else s -= s_current;
    }

    fout << s;
}
