#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n, m, x, k, a[2049], d[2049], P[2049], I[2049], f[11];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> x, f[x]++;
    for(int i = 1; i <= m; ++i){
        cin >> x;
        if(f[x] != -1) f[x]++;
        if(f[x] > 1 && f[x] != -1) a[++k] = x, f[x] = -1;
    }
    n = k;
    k = 1;
    d[k] = a[1];
    P[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(a[i] > d[k]) d[++k] = a[i], P[i] = k;
        else {
            int st = 1, dr = k, p = k+1;
            while(st <= dr){
                int mij = (st + dr) / 2;
                if(d[mij] > a[i]) p = dr, dr = mij-1;
                else st = mij+1;
            }
            d[p] = a[i];
            P[i] = p;
        }
    }
    int j = n;
    for(int i = k; i >= 1; --i){
        while(P[j] != i) j--;
        I[i] = j;
    }
    cout << k << '\n';
    for(int i = 1; i <= k; ++i){
        cout << a[I[i]] << " ";
    }
    return 0;
}
