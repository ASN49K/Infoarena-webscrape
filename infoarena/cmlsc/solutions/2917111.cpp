#include <stdio.h>
#include <vector>

using namespace std;

vector<int> c(1024);

vector<int> cmlsc(vector<int> a, vector<int> b) {
    if (a.size() == 0 || b.size() == 0) {
        vector<int> empty;
        return empty;
    } else if (a[a.size() - 1] == b[b.size() - 1]) {
        vector<int> a_aux(a.begin(), a.end() - 1);
        vector<int> b_aux(b.begin(), b.end() - 1);

        vector<int> res = cmlsc(a_aux, b_aux);
        res.push_back(a[a.size() - 1]);

        return res;
    } else {
        vector<int> a_aux(a.begin(), a.end() - 1);
        vector<int> b_aux(b.begin(), b.end() - 1);

        vector<int> res_a = cmlsc(a_aux, b);
        vector<int> res_b = cmlsc(a, b_aux);

        if (res_a.size() > res_b.size()) {
            return res_a;
        } else {
            return res_b;
        }
    }
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m, nr;
    scanf("%d %d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nr);
        a[i] = nr;
    }

    vector<int> b(n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nr);
        b[i] = nr;
    }

    c = cmlsc(a, b);

    printf("%d\n", c.size());

    for (int i = 0; i < c.size(); i++) {
        printf("%d ", c[i]);
    }

    return 0;
}