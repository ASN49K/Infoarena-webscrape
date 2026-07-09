#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>

using namespace std;

const char infile[] = "biconex.in";
const char outfile[] = "biconex.out";

ifstream fin(infile);
ofstream fout(outfile);

const int MAXN = 100005;
const int oo = 0x3f3f3f3f;

typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;

const inline int min(const int &a, const int &b) { if( a > b ) return b;   return a; }
const inline int max(const int &a, const int &b) { if( a < b ) return b;   return a; }
const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }
const inline void Get_max(int &a, const int b)    { if( a < b ) a = b; }

const int lim = (1 << 20);
char buff[lim];
int pos;

inline void get(int &x) {
    x = 0;
    while(!('0' <= buff[pos] && buff[pos] <= '9'))
        if( ++ pos == lim) {
            fread(buff, 1, lim, stdin);
            pos = 0;
        }
    while('0' <= buff[pos] && buff[pos] <= '9') {
        x = x * 10 + buff[pos] - '0';
        if(++ pos == lim) {
            fread(buff, 1, lim, stdin);
            pos = 0;
        }
    }
}

Graph G;
int N, M, depth[MAXN], lowLink[MAXN];
vector <vector <int> > BCC;
stack <pair<int, int> > st;

inline void extractBCC(int x, int y) {
    int tx, ty;
    vector <int> v;
    do {
        tx = st.top().first;
        ty = st.top().second;
        st.pop();
        v.push_back(tx);
        v.push_back(ty);
    } while(tx != x || ty != y);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    BCC.push_back(v);
}

inline void DFs(int Node, int Father, int actLevel) {
    depth[Node] = lowLink[Node] = actLevel;
    for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it) {
        if(*it == Father)
            continue;
        if(!depth[*it]) {
            st.push(make_pair(Node, *it));
            DFs(*it, Node, actLevel + 1);
            lowLink[Node] = min(lowLink[Node], lowLink[*it]);
            if(lowLink[*it] >= depth[Node])
                extractBCC(Node, *it);
        } else lowLink[Node] = min(lowLink[Node], depth[*it]);
    }
}

int main() {
    freopen(infile, "r", stdin);
    get(N);
    get(M);
    //fin >> N >> M;
    for(int i = 1 ; i <= M ; ++ i) {
        int x, y;
        get(x);
        get(y);
        //cerr << x << ' ' << y << '\n';
        //fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    DFs(1, 0, 1);
    fout << BCC.size() << '\n';
    for(auto comp : BCC) {
        for(auto it : comp)
            fout << it << ' ';
        fout << '\n';
    }
    fout.close();
    return 0;
}
