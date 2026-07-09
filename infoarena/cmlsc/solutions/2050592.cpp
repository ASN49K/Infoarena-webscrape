#include <iostream>
#include <cstdio>
#include <algorithm>
#define LG 1026

using namespace std;
FILE *fin=fopen("cmlsc.in","r"),*fout=fopen("cmlsc.out","w");
int n,m,c[LG][LG],a[LG],b[LG],v[LG];
int main(){
    fscanf(fin,"%d%d",&n,&m);
    for(int i=1;i<=n;i++) fscanf(fin,"%d",&a[i]);
    for(int i=1;i<=m;i++) fscanf(fin,"%d",&b[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                c[i][j]=1+max(max(c[i-1][j-1],c[i][j-1]),c[i-1][j]);
            }
            else{
                c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    fprintf(fout,"%d\n",c[n][m]);
    int i=n,j=m;
    while (i>0 and j>0) {
        while (c[i][j]==c[i-1][j]) i--;
        while (c[i][j]==c[i][j-1]) j--;
        v[c[i][j]] = a[i];
        i--; j--;
    }
    for(int y=1;y<=c[n][m];y++) fprintf(fout,"%d ",v[y]);
    return 0;
}
