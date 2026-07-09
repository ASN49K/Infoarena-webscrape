#include<stdio.h>
int f1[1025],f2[1025];
int main(){
    int m,n,v1[1025],v2[1025],i,j,k,nr=0;
    FILE *fin=fopen("cmlsc.in","r"),*fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&m,&n);
    for(i=1;i<=m;i++){
    fscanf(fin,"%d",v1[i]);
    f1[v1[i]]++;
    }
    for(j=1;j<=m;j++){
    fscanf(fin,"%d",v2[j]);
    f2[v2[j]]++;
    }
    if(n>=m){
        for(k=1;k<=n;k++)
        if(f1[k]!=0&&f2[k]!=0){
            nr++;
            fprintf(fout,"%d\n%d ",nr,v1[k]);
        }
    }
    else{
        for(k=1;k<=m;k++)
        if(f1[k]!=0&&f2[k]!=0){
            nr++;
            fprintf(fout,"%d\n%d ",nr,v1[k]);
        }
    }
    return 0;
}
