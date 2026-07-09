#include<stdio.h>
#define NMAX 1024

int n,m,k=0,a[NMAX],b[NMAX],l[NMAX][NMAX],r[NMAX];

void citeste() {
  int i;
  freopen("cmlsc.in","r",stdin);
  scanf("%d %d",&m,&n);
  for(i=0;i<m;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  fclose(stdin);
}

void rezolva() {
  int i,j;
  l[0][0]=(a[0]==b[0])?1:0;
  for(i=1;i<m;i++) l[i][0]=(a[i]==b[0])?1:l[i-1][0];
  for(i=1;i<n;i++) l[0][i]=(a[0]==b[i])?1:l[0][i-1];
  for(i=1;i<m;i++)
   for(j=1;j<n;j++)
    l[i][j]=(a[i]==b[j])?l[i-1][j-1]+1:
      ((l[i-1][j]>l[i][j-1])?l[i-1][j]:l[i][j-1]);
  for(i=m-1,j=n-1;(i>=0)&&(j>=0);) {
    if(a[i]==b[j]) { r[k++]=a[i]; i--; j--; }
    else
     if(!i) j--;
     else
      if(!j) i--;
      else if(l[i][j-1]>=l[i-1][j]) j--; else i--;
  }
}

void scrie() {
  freopen("cmlsc.out","w",stdout);
  printf("%d\n",k);
  for(int i=k-1;i>=0;i--) printf("%d ",r[i]);
  fclose(stdout);
}

int main() {
  citeste();
  rezolva();
  scrie();
  return 0;
}
