#include <bits/stdc++.h>
using namespace std;
FILE *fin, *fout;
int x[1025],v[1025],sir[1025];
int d[1025][1025];
int main()
{
    fin=fopen("cmlsc.in", "r");
    fout=fopen("cmlsc.out", "w");
    int n,m,i,j,nr=0;
    fscanf(fin, "%d %d", &n, &m);
    for(i=1;i<=n;i++)
        fscanf(fin, "%d", &x[i]);
    for(i=1;i<=m;i++)
        fscanf(fin, "%d", &v[i]);

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(x[i]==v[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    }

    for(i=n,j=m; i;){
        if(x[i]==v[j])
            nr++, sir[nr]=x[i], i--, j--;
        else{
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;

            }
        }
    fprintf(fout, "%d\n", nr);
    for(i=nr;i>=1;i--)
        fprintf(fout, "%d ", sir[i]);
    return 0;
}
