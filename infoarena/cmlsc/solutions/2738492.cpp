
#include <fstream>

using namespace std;

ifstream  cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int MAXN = 1026;
const int M = 1<<11;
int m, n;
int a[MAXN], b[MAXN];
int d[MAXN][MAXN];
int v[MAXN];

void print() {
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++)
            cout << (d[i][j] / M == 0 ? '`' : d[i][j] / M == 1 ? '^' : '<') << (d[i][j] % M)  << "  ";
        cout << "\n";
    }
}

int main()
{
    cin >> m >> n;
    for(int i=1; i<=m; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        cin >> b[i];
    int mi=0, mj=0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) {
            if(a[i] == b[j]) {
                d[i][j] = d[i-1][j-1] % M + 1;
                if(d[i][j] % M > d[mi][mj] % M) {
                    mi = i; 
                    mj = j;
                }
            }
            else if(d[i-1][j] % M > d[i][j-1] % M)
                d[i][j] = d[i-1][j] % M + M;
            else
                d[i][j] =  d[i][j-1] % M + 2*M;
        }
    cout << d[mi][mj] << "\n";
    int cnt = 1;
    while(mi > 0 && mj > 0) {
        if(d[mi][mj] / M == 0) {
            v[cnt] = a[mi];
            cnt++;
            mi--;
            mj--;
        }
        else if(d[mi][mj] / M == 1)
            mi--;
        else
            mj--;
    }
    for(int i=cnt-1; i>0; i--)
        cout << v[i] << " ";
    return 0;
}