#include <bits/stdc++.h>

using namespace std;

ifstream fin("costperm.in");
ofstream fout("costperm.out");
long long n, i, a, poz[100002], aib[100002];
long long rasp;

static inline void Add(int poz, int val) {
    for(int i = poz; i <= n; i += (i & -i)) aib[i] += val;
}

static inline int Sum(int poz) {
    int sum = 0;
    for(int i = poz; i >= 1; i -= (i & -i)) sum += aib[i];
    return sum;
}

int main() {
    fin.tie(nullptr);
    fout.tie(nullptr);

    fin >> n;
    for(i = 1; i <= n; i++) {
        fin >> a;
        Add(a, 1);
        poz[a] = i;
    }
    for(i = 1; i <= n; i++) {
        rasp += 1LL * i * Sum(poz[i] - 1);
        Add(poz[i], -1);
    }
    fout << rasp;

    return 0;
}
