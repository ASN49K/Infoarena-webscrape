#include<stdio.h>
FILE*fin,*fout;
long int a[1024],b[1024],m,n,i,j,max,ok,v[1024],t;
int main(){
fin=fopen("cmlsc.in","r");
fout=fopen("cmlsc.out","w");
fscanf(fin,"%ld %ld\n",&n,&m);
for(i=1;i<=n;i++){fscanf(fin,"%ld ",&a[i]);}
fscanf(fin,"\n");
for(i=1;i<=m;i++){fscanf(fin,"%ld ",&b[i]);}
fclose(fin);  t=-1;
for(i=1;i<=m;i++){  ok=1;
    for(j=1;j<=n;j++){if(b[i]==a[j]){ok=0;t++;v[t]=a[j];break;}}


}


fprintf(fout,"%ld\n",t+1);
for(j=0;j<=t;j++){fprintf(fout,"%ld ",v[j]);}









return 0;
}