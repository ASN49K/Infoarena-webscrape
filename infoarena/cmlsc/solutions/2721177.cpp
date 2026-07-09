#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("arbint.in");
ofstream g("arbint.out");

const int NMAX = 100001;
const int INF = (1 << 30);

int n, m, aint[4 * NMAX];

void build(int node, int left, int right) {

    if(left == right) {
        int x;
        f >> x;

        aint[node] = x;
        return;
    }

    int mid = (left + right) / 2;

    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);

    aint[node] = max(aint[2 * node], aint[2 * node + 1]);
}

int query(int node, int left, int right, int a, int b) {

    if(left > b || right < a)
        return -INF;

    if(left >= a && right <= b)
        return aint[node];

    int mid = (left + right) / 2;

    return max(
                query(2 * node, left, mid, a, b),
                query(2 * node + 1, mid + 1, right, a, b)
               );
}

void update(int node, int left, int right, int index, int val) {

    if(left > index || right < index)
        return;

    if(left == right) {
        aint[node] = val;
        return;
    }

    int mid = (left + right) / 2;

    update(2 * node, left, mid, index, val);
    update(2 * node + 1, mid + 1, right, index, val);

    aint[node] = max(aint[2 * node], aint[2 * node + 1]);
}

int main() {

    f >> n >> m;

    build(1, 1, n);

    for(;m--;) {

        int t, a, b;
        f >> t >> a >> b;

        if(t == 0)
            g << query(1, 1, n, a, b) << '\n';
        else
            update(1, 1, n, a, b);
    }

    return 0;
}
