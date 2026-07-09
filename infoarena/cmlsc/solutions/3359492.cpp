#include <bits/stdc++.h>
using namespace std;
short x[1025][1025];
short a[1025],b[1025];
int main(){
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    int n,m,i,j;
    cin >> n >> m;
    for(i=1;i<=n;i++)
        cin >> a[i];
    for(i=1;i<=m;i++)
        cin >> b[i];
    for(i=1;i<n;i++)
        for(j=1;j<m;j++){
            if(a[i]==b[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
        }
    fprintf(fout,"%d",x[n-1][m-1]);
    return 0;
}
