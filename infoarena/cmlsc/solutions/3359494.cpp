#include <bits/stdc++.h>
using namespace std;
int x[1025][1025],a[1025],b[1025];
void backTrack(int i,int j,FILE *fout){
    if(i==0||j==0)
        return;
    if (a[i]==b[j]){
        backTrack(i-1,j-1,fout);
        fprintf(fout,"%d ",a[i]);
    }
    else if(x[i-1][j]>x[i][j-1])
        backTrack(i-1,j,fout);
    else
        backTrack(i,j-1,fout);
}
int main(){
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    int n,m,i,j;
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
        }
    fprintf(fout,"%d\n",x[n][m]);
    backTrack(n,m,fout);
    return 0;
}
