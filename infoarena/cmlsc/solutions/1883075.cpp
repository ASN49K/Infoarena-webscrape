#include <cstdio>
#include <vector>
using namespace std;

vector<int> a, b;
vector<int> v, res;
auto fin = fopen("cmlsc.in", "r");
auto fout = fopen("cmlsc.out", "w");

void input() {
    int lena, lenb, el;
    fscanf(fin, "%d %d", &lena, &lenb);
    a.reserve(lena);
    b.reserve(lenb);
    while (lena--) {
        fscanf(fin, "%d", &el);
        a.push_back(el);
    }
    while (lenb--) {
        fscanf(fin, "%d", &el);
        b.push_back(el); 
    }
}

void output() {
    fprintf(fout, "%d\n", res.size());
    for (auto i = 0u; i < res.size(); ++i)
        fprintf(fout, "%d ", res[i]);
    fprintf(fout, "\n");
}

bool isSubchain() {
    auto i = 0u, j = 0u;
    while (i < v.size() && j < b.size()) {
        // printf("%d ~ %d: %d, %d\n", v[i], b[i], i, j);
        if (v[i] == b[j])
            ++i;
        ++j;
    }
    // printf ("%d %d ", i, j);
    // printf ("%-6s", i == v.size()?"true":"false");
    // for (auto i = 0; i < v.size(); ++i)
    //     printf("%d ", v[i]);

    // printf("\n");
    return i == v.size();
}

void bkt(int level) {
    if (level == a.size()) {
        if (isSubchain() && v.size() > res.size())
            res = v;
        return;
    }
        
    bkt(level + 1);
    v.push_back(a[level]);
    bkt(level + 1);
    v.pop_back();
}

void solve() {
    bkt(0);
}

int main() {
    // freopen("cmlsc.in", "r", stdin);
    // freopen("cmlsc.out", "w", stdout);

    input();
    solve();
    output();

    return 0;
}