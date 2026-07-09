#include <stdio.h>
#define L 1025
using namespace std;
int va[L], vb[L], m[L][L];
int main(){
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  int a, b, i, j, k;
  scanf("%d%d", &a, &b);
  for(i=0; i<a; i++)
    scanf("%d", &va[i]);
  for(i=0; i<b; i++)
    scanf("%d", &vb[i]);
  if(va[0]==vb[0])
    m[0][0]=1;
  else
    m[0][0]=0;
  for(i=1; i<b; i++)
    if(va[0]==vb[i])
      m[0][i]=m[0][i-1]+1;
    else
      m[0][i]=m[0][i-1];
  for(i=1; i<a; i++)
    if(vb[0]==va[i])
      m[i][0]=m[i-1][0]+1;
    else
      m[i][0]=m[i-1][0];
  for(i=1; i<a; i++)
    for(j=1; j<b; j++)
      if(va[i]==vb[j])
        m[i][j]=m[i-1][j-1]+1;
      else if(m[i-1][j]>m[i][j-1])
        m[i][j]=m[i-1][j];
      else
        m[i][j]=m[i][j-1];
  printf("%d\n", m[a-1][b-1]);
  k=1;
  for(i=0; i<a; i++)
    for(j=0; j<b; j++)
      if(m[i][j]==k){
        printf("%d ", va[i]);
        k++;
      }
  return 0;
}
