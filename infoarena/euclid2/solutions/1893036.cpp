#include <bits/stdc++.h>
using namespace std;

int a[100005],b[100005],c[100005];
unsigned GCD(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main() {
ifstream fin("euclid2.in");
int n;
fin>>n;
for (int i=1;i<=n;i++)
{
    fin>>a[i]>>b[i];
}
fin.close();
ofstream fout("euclid2.out");
for (int i=1;i<=n;i++)
fout<<GCD(a[i],b[i])<<'\n';
fout.close();
    return 0;
}
