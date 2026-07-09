#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a[1025];
int b[1025];
int v[1025][1025];

FILE *fin, *fout;

int max(int a, int b){
  if(a<b)
    a=b;
  return a;
}

int back(int i, int j){
  if(i==0 || j==0){}
  else  if(a[i]==b[j]){
    back(i-1,j-1);
    fprintf(fout,"%d ",a[i]);
  }else if(v[i][j-1]>v[i-1][j]){
    back(i,j-1);
  }else{
    back(i-1,j);
  }
  return 0;
}

int main()
{
    int n,m,i,j,x;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++){
      fscanf(fin,"%d",&a[i]);
    }
    for(j=1;j<=m;j++){
      fscanf(fin,"%d",&b[j]);
    }
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        if(a[i]==b[j])
          v[i][j]=v[i-1][j-1]+1;
        else{
          v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
      }
    }
    fprintf(fout,"%d\n",v[n][m]);
    back(n,m);
    fclose(fin);
    fclose(fout);
    return 0;
}
