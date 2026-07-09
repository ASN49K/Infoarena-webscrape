#include <fstream>
#include <iostream>

using namespace std;

struct point {
    double x, y;
};

const int MAX_N = 1e5 + 10;
const int MAX_M = 1e5 + 10;

point v[MAX_N];
point q[MAX_M];

int n, m;

double Au[MAX_N];
int up[MAX_N];
int u;

double Al[MAX_N];
int low[MAX_N];
int l;

double cross(const point &A, const point &B, const point &C) {
    const double x1 = C.x - B.x,
              y1 = C.y - B.y,
              x2 = B.x - A.x,
              y2 = B.y - A.y;

    return x1 * y2 - x2 * y1;
}

bool left(const point &A, const point &B, const point &C) {
    return cross(A, B, C) <= 0;
}

bool right(const point &A, const point &B, const point &C) {
    return cross(A, B, C) >= 0;
}

double A(const point &A, const point &B, const point &C) {
    double ret = cross(A, B, C);
    if(ret < 0)
        ret = -ret;

    return ret;
}


void process(int i) {
    if(i == 1){
        u = l = 1;
        up[1] = 1;
        low[1] = 1;
    } else {
        if(v[i].y >= v[1].y) {
            while(u > 2 && left( v[up[u - 1]], v[up[u]], v[i]))
                --u;
            up[++u] = i;
            if(u >= 3)
                Au[u] = Au[u - 1] + A(v[1], v[up[u - 1]], v[i]);

        } else {
            while(l > 2 && right( v[low[l - 1]], v[low[l]], v[i]))
                --l;
            low[++l] = i;

            if(l >= 3)
                Al[l] = Al[l - 1] + A(v[1], v[low[l - 1]], v[i]);
        }
    }
}

int upsearch(const int j) {
    int i, step;
    for(step = 1 ; step < u ; step *= 2);

    for(i = 1 ; step ; step /= 2) {
        if(i + step <= u) {
            int nxt = i + step;
            if(right(v[up[nxt - 1]], v[up[nxt]], q[j]))
                i = nxt;
        }
    }
    return i;
}


int downsearch(const int j) {
    int i, step;
    for(step = 1 ; step < l ; step *= 2);

    for(i = 1 ; step ; step /= 2) {
        if(i + step <= l) {
            int nxt = i + step;
            if(left(v[low[nxt - 1]], v[low[nxt]], q[j]))
                i = nxt;
        }
    }

    return i;
}

double query(int j) {


    if(u + l < 3)
        return 0;

    if(u + l == 3) {
        return A(v[1], v[2], q[j]);
    }

    double ret = 0;

    if(q[j].y >= v[1].y) {
        //the query is in the upper bound
        int fst = upsearch(j);
        ret += Al[l];
        ret += Au[fst] + A(v[1], v[up[fst]], q[j]);
        ret += A(v[1], v[low[l]], q[j]);

        if(right(q[j], v[up[u]], v[low[l]]))
            ret += A(q[j], v[up[u]], v[low[l]]);

        return ret;
    } else {
        //the query is in the lower bound
        int fst = downsearch(j);
        ret += Au[u];

        ret += Al[fst] + A(v[1], v[low[fst]], q[j]);

        ret += A(v[1], v[up[u]], q[j]);

        if(left(q[j], v[low[l]], v[up[u]]))
            ret += A(q[j], v[low[l]], v[up[u]]);

        return ret;
    }

    return 0;
}

int main() {
    ifstream in("geometrie.in");
    in >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
        in >> v[i].x >> v[i].y;
    for(int i = 1 ; i <= m ; ++i)
        in >> q[i].x >> q[i].y;
    in.close();

    FILE * out = fopen("geometrie.out", "w");

    int i = 1, j = 1;
    double ans;
    while(i <= n && j <= m) {
        if(v[i].x < q[j].x) {
            process(i);
            i++;
        } else {
            ans = query(j);

            fprintf(out, "%lf\n", ans/2);
            j++;
        }
    }

    for(; j <= m ; ++j) {
        ans = query(j);
                fprintf(out, "%lf\n", ans/2);
    }

    fclose(out);
    return 0;
}
