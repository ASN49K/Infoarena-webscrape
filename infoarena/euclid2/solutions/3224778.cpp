#include <iostream>

using namespace std;

int main()
{
    long long t, n;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        bool ok=true;
        long long v[n], fv=0, cnt=0, sol=INT_MAX, sol2=INT_MAX, d1=-1, d2=-1, pvi=-1;
        cin >> v[0];
        fv=v[0];
        for(int i=1; i<n; i++) {
            cin >> v[i];
            if(v[i]!=fv) {
                if(pvi==-1) {
                    pvi=i;
                } else {
                    d1=i-pvi-1;
                    sol2=min(sol2, d1);
                }
                if(ok==true) {
                    ok=false;
                    cnt=i;
                    sol=n-i-1;
                } else {
                    sol=n-i-1;
                }
            }
        }
        if(ok==true) {
            cout << -1 << "\n";
        } else {
            cout << min(min(sol, sol2), cnt) << "\n";
        }
    }
    return 0;
}
