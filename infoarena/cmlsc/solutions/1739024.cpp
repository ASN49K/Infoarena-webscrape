#include<stdio.h>
using namespace std;
FILE *f1=fopen("cmlsc.in","r");
FILE *f2=fopen("cmlsc.out","w");
int n,m,a[1025],b[1025],sol[1025][1025],v[1025][1025],i,j;
void afis(int i,int j){
    if (v[i][j]==1) fprintf(f2,"%d ",sol[i][j]);
      else{
         if (v[i-1][j]==v[i][j]-1){
            afis(i-1,j);
            fprintf(f2,"%d ",sol[i][j]);
            return;
         }
         if (v[i][j-1]==v[i][j]-1){
            afis(i,j-1);
            fprintf(f2,"%d ",sol[i][j]);
            return;
         }
         if (v[i-1][j-1]==v[i][j]-1){
            afis(i-1,j-1);
            fprintf(f2,"%d ",sol[i][j]);
            return;
         }
         afis(i-1,j-1);
      }
}
int main(){
    fscanf(f1,"%d%d",&m,&n);
    for (i=1;i<=m;i++)
        fscanf(f1,"%d",&a[i]);
    for (i=1;i<=n;i++)
        fscanf(f1,"%d",&b[i]);
    fclose(f1);
    for (i=1;i<=n;i++)
        sol[0][i]=b[i];
    for (i=1;i<=m;i++)
        sol[i][0]=a[i];
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
          if (a[i]==b[j])
            {  v[i][j]=v[i-1][j-1]+1;
               sol[i][j]=a[i];
            }
              else{
                if (v[i-1][j]>v[i][j-1]) {
                        v[i][j]=v[i-1][j];
                        sol[i][j]=sol[i-1][j];
                }
                  else{
                    v[i][j]=v[i][j-1];
                    sol[i][j]=sol[i][j-1];
                  }
              }
    fprintf(f2,"%d\n",v[m][n]);
    afis(m,n);
    fclose(f2);
    return 0;
}
