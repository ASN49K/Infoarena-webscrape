//https://www.infoarena.ro/problema/cmlsc
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n, A[2000], a[2000], s1[2000], s2[2000], p[2000], r[2000], rs[2000], ele1, ele2, nr;

int main(){
    ifstream cin("cmlsc.in");    
    ofstream cout("cmlsc.out");
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        cin >> nr;
        a[nr] = 1;
        A[i] = nr;
    }

    for(int i=1; i<=n; i++){
        cin >> nr;
        if(a[nr] >= 1){
            ele2++;
            s2[ele2] = nr;
            // cout << s2[ele2] << ' ';
            a[nr] = 2;
        }
    }

    for(int i=1; i<=m; i++){
        if(a[A[i]] == 2){
            ele1++;
            s1[ele1] = A[i];
            // cout << s1[ele1] << ' ';
        }
    }

    for(int i=1; i<=ele1; i++){
        p[s1[i]] = i;
    }

    int ele =  ele2;
    int maxim1 = 0, maxim = 0;
    nr=0;
    while(ele--){
        nr++;
        maxim1 = 1;
        r[maxim1] = s2[nr];
        for(int i=nr+1; i<=ele2; i++){
            if(p[s2[nr]] < p[s2[i]]){
                maxim1++;
                r[maxim1] = s2[i];
            }
        }

        if(maxim1 > maxim){
            maxim = maxim1;
            for(int i=1; i<=maxim; i++){
                rs[i] = r[i];
            }
        }
    }

    cout << maxim << endl;
    for(int i=1; i<=maxim; i++){
        cout << rs[i] << ' ';
    }
    
}