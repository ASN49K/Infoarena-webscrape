#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int d[1030][1030], idx=0, sol[1030];

int main()
{
    int n, m;
    fin >> n >> m;
    int a[n+1], b[m+1];
    for(int i=1; i<=n; i++) {
        fin >> a[i];
    }
    for(int i=1; i<=m; i++) {
        fin >> b[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i]==b[j]) {
                d[i][j]=d[i-1][j-1]+1;
            } else {
                d[i][j]=max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    int i=n, j=m;
    while(i>0 && j>0) {
        if(a[i]==b[j]) {
            sol[idx]=a[i];
            i--;
            j--;
            idx++;
        }
        if(d[i][j-1]>d[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }
    fout << idx << "\n";
    for(i=idx-1; i>=0; i--) {
        fout << sol[i] << " ";
    }
    return 0;
}
