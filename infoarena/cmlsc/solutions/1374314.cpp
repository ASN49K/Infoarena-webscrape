#include <iostream>
#include <fstream>
using namespace std;
int a[1050][1050], b[1050], c[1050], i, n, m, q, k, d[1030], o;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(i=1; i<=n; i++) fin>>b[i];

    for(i=1; i<=m; i++) fin>>c[i];
    for(i=1; i<=n; i++)
    for(q=1; q<=m; q++)
    {
        if(b[i]==c[q])
        {
            a[i][q]=a[i-1][q-1]+1;
        }
        else a[i][q]=max(a[i-1][q], a[i][q-1]);
    }
    fout<<a[n][m]<<"\n";
    q=m;
    i=n;
    k=a[i][q];
    while(i>0&&q>0)
    {
        while(a[i][q]==k) q--;
        q++;
        while(a[i][q]==k) i--;
        i++;
        o++;
        d[o]=b[i];

        k--;
        i--;
        q--;
    }
    for(i=o; i>0; i--) fout<<d[i]<<" ";
    return 0;
}
