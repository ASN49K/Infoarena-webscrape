#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n, m, a[1025], b[1025], d[1025], k = 1, f[10];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i], f[a[i]]++;
    for(int i = 1; i <= m; ++i) cin >> b[i], f[b[i]]++;
    d[k] = a[1];
    for(int i = 2; i <= n; ++i){
        if(a[i] > d[k]) d[++k] = a[i];
        else{
            int st = 1, dr = k, p = k + 1;
            while(st <= dr){
                int mij = (st + dr) / 2;
                if(d[mij] > a[i]) p = dr, dr = mij - 1;
                else st = mij + 1;
            }
            d[p] = a[i];
        }
    }
    cout << k-1 << '\n';
    for(int i = 1; i <= 9; ++i){
        if(f[i] > 1) cout << i << " ";
    }
    return 0;
}
