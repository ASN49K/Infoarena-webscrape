#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int nm,n,m,a[257],b[257],c[257],ne;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int j=1;j<=m;j++)
        cin >> b[j];
    int i=1;
    nm=1;
    int j=1;
    ne=0;

    while(i<=n) {
        j=nm;
        while(a[i]!=b[j] && j<=m)
            j++;


        if(a[i]==b[j]) {
            ne++;
            c[ne]=a[i];

            nm=j+1;
        }
        i++;
    }
    cout << ne << "\n";
    for(int x=1;x<=ne;x++)
        cout << c[x] << " ";
    return 0;
}
