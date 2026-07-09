#include <bits/stdc++.h>
#define SQR 1000000
#define ULL unsigned long long
#define MOD 9973

using namespace std;

ifstream fin("ssnd.in");
ofstream fout("ssnd.out");

vector<ULL> prime;
void generare() {
    bitset<SQR + 1> ciur;
    ciur[0] = ciur[1] = 1;
    for (ULL d = 4; d <= SQR; d += 2)
        ciur[d] = 1;
    for (ULL i = 3; i * i <= SQR; i += 2)
        if (!ciur[i])
            for (ULL d = i * i; d <= SQR; d += 2 * i)
                ciur[d] = 1;
    for (ULL i = 2; i <= SQR; i++)
        if (!ciur[i])
            prime.push_back(i);
}

ULL calcNrDiv(ULL n) {
    ULL p = 0, nrDiv = 1;
    while (n % 2 == 0)
        p++, n /= 2;
    nrDiv *= (p + 1);
    for (auto &d : prime) {
        if (d * d > n)
            break;
        if (n % d == 0) {
            p = 0;
            while (n % d == 0)
                p++, n /= d;
            nrDiv *= (p + 1);
        }
    }
    if (n > 1)
        nrDiv *= 2;
    return nrDiv;
}

ULL calcSumDiv(ULL n) {
    ULL sumDiv = 1;
    if (n % 2 == 0) {
        ULL p = 2;
        while (n % 2 == 0)
            p *= 2, n /= 2;
        sumDiv = p - 1;
    }
    for (auto &d: prime) {
        if (d * d > n)
            break;
        if (n % d == 0) {
            ULL p = d;
            while (n % d == 0)
                p *= d, n /= d;
            sumDiv *= (p - 1) / (d - 1);
        }
    }
    if (n > 1)
        sumDiv *= (n * n  - 1) / (n - 1);
    return sumDiv;
}

int main() {
    generare();
    int t;
    fin >> t;
    for (int i = 0; i < t; i++) {
        ULL x;
        fin >> x;
        fout << calcNrDiv(x) << ' ' << calcSumDiv(x) << '\n';
    }
    return 0;
}