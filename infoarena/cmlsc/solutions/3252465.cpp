#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,i,j,smax,pozmax,secv,k;
int v[1030],w[1030],d[1030][1030],secvcom[1030];
int main () {
    cin>>n>>m;
    for (i=1;i<=n;i++) {
        cin>>v[i];
    }
    for (i=1;i<=m;i++) {
        cin>>w[i];
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (v[i]==w[j]) {
                d[i][j]=d[i-1][j-1]+1;
            }
            else {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    i=n;
    j=m;
    while (j>0) {
        if (v[i]==w[j]) {
            secvcom[++k]=v[i];
            i--;
            j--;
        }
        else {
            if (d[i-1][j]<d[i][j-1]) {
                j--;
            }
            else {
                i--;
            }
        }
    }
    cout<<k<<"\n";
    for (i=k;i>=1;i--) {
        cout<<secvcom[i]<<" ";
    }
}

