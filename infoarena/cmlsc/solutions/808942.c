#include<stdio.h>
#define nx 1025
int a[nx],b[nx];
int c[nx][nx];
int main(){
int j,i,n,m,p,max;
FILE*f=fopen("cmlsc.in","r");
fscanf(f,"%d",&n);
fscanf(f,"%d",&m);
for(i=0;i<n;i++) fscanf(f,"%d",&a[i]);
for(i=0;i<m;i++) fscanf(f,"%d",&b[i]);
for(i=0;i<n;i++) for(j=0;j<m;j++) c[i][j]=0;
for(i=0;i<n;i++) for(j=0;j<m;j++) if(a[i]==b[j]) c[i][j]=1;
p=-1; max=0; FILE*h=fopen("cmlsc.out","w");
for(i=0;i<n;i++) for(j=0;j<m;j++) if((c[i][j]==1)&&(i>p)){p=j;max++; break;}
fprintf(h,"%d\n",max);
p=-1;
for(i=0;i<n;i++) for(j=0;j<m;j++) if((c[i][j]==1)&&(i>p)){fprintf(h,"%d ",a[i]);
                                                      p=j; break;}
                                                      fclose(f);fclose(h);
return 0;
}

