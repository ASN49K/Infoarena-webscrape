#include<stdio.h>
using namespace std;
FILE *f1=fopen("cmlsc.in","r");
FILE *f2=fopen("cmlsc.out","w");
int n,m,a[1025],b[1025],sol[1025],v[1025][1025],i,j,nrs;
int main(){
    fscanf(f1,"%d%d",&m,&n);
    for (i=1;i<=m;i++)
        fscanf(f1,"%d",&a[i]);
    for (i=1;i<=n;i++)
        fscanf(f1,"%d",&b[i]);
    fclose(f1);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
          if (a[i]==b[j])
            {  v[i][j]=v[i-1][j-1]+1;
            }
              else{
                if (v[i-1][j]>v[i][j-1]) {
                        v[i][j]=v[i-1][j];
                }
                  else{
                    v[i][j]=v[i][j-1];
                  }
              }
    fprintf(f2,"%d\n",v[m][n]);
    i=m;j=n;
    while(i!=0 && j!=0){
        if (a[i]==b[j]){
            nrs++;
            sol[nrs]=a[i];
            i--;j--;
        }
          else
            if (v[i-1][j]>v[i][j-1]) i--;
              else
                j--;
    }
    for (i=nrs;i>=1;i--)
        fprintf(f2,"%d ",sol[i]);
    fclose(f2);
    return 0;
}
