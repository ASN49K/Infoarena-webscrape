#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 1025;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j, a[maxn], b[maxn], c[maxn], last, ans, d[maxn], last2;
int ansmx, imax;
int rez[maxn], rezk;

int main()
{
    f >> n >> m;

    for(i = 1; i <= n; i ++) {
        f >> a[i];
    }
    for(i = 1; i <= m; i ++) {
        f >> b[i];
    }

    for(i = 1; i <= n; i ++) { last = 0; imax = 0;
        for(j = 1; j <= m; j ++) {
            if(a[i] == b[j]) {
                c[j] = last + 1;
                if(c[j] > ans) {
                    ans = c[j];
                    ansmx = j;
                }
                d[j] = imax;
            }
            else {
                if(c[j] > last){
                    last = c[j];
                    imax = j;
                }
            }
        }
    }

    g << ans << '\n';
    for(i = ansmx; i != 0; i = d[i]) {
        rez[++rezk] = b[i];
    }
    for(i = rezk; i >= 1; i --) {
        g << rez[i] << ' ';
    }

    f.close();
    g.close();
    return 0;
}
