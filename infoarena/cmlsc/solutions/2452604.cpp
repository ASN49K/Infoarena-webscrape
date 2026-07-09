#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int nm,n,m,a[1025],b[1025],c[1025],ne;
int main()
{
    fin >> n >> m;
    for(int i=1;i<=n;i++)
        fin >> a[i];
    for(int j=1;j<=m;j++)
        fin >> b[j];
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
    fout << ne << "\n";
    for(int x=1;x<=ne;x++)
        fout << c[x] << " ";
    fin.close();
    fout.close();
    return 0;
}
