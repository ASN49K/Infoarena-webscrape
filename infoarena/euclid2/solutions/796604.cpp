#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define infile "euclid2.in"
#define outfile "euclid2.out"

#define n_max 100005
#define INF 1 << 30
#define MOD 666013

#define ll long long
#define ull unsigned long long

#define pb push_back
#define mkp make_pair
#define pii pair<int, int>
#define FOR(g) \
    for(vector<int>::iterator it=g.begin(); it!=g.end(); ++it)
#define nxt (*it)

#define min(x,y) x<y ? x : y
#define max(x,y) x>y ? x : y
using namespace std;

int T;

inline int cmmdc(int a, int b){
    if(!b)
       return a;

    return cmmdc(b, a%b);
}

int main(){
    ifstream fin(infile);
    ofstream fout(outfile);

    fin >> T;

    int x, y;
    while(T--){
        fin >> x >> y;

        fout << cmmdc(x,y) << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}
