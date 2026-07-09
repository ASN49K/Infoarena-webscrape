#include<cstdio>
#define input "cmlsc.in"
#define output "cmlsc.out"
#define max(a,b) (a > b) ? a : b
#define Nmax 1025


FILE *fin=freopen(input,"r",stdin),
     *fout=freopen(output,"w",stdout);

int n,m, A[Nmax],B[Nmax],mat[Nmax][Nmax];

void citire()
{
  scanf("%d %d",&n,&m);
  
  for(int i=1; i<=n; i++)
    scanf("%d",&A[i]);
    
  for(int i=1; i<=m; i++)
    scanf("%d",&B[i]);
}

void solve()
{
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      if(A[i] == B[j])
        mat[i][j] = mat[i-1][j-1] + 1;
      else
        mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
  
  int sol[Nmax],nrs=0;
  
  for(int i=n,j=m;i;)
    if(A[i] == B[j])
    {
      sol[++nrs] = A[i];
      i--,j--;
    }
    else if(mat[i-1][j] < mat[i][j-1])
      j--;
    else 
      i--;
  
  printf("%d\n",nrs);
  
  for(int i=nrs; i; --i)
    printf("%d ",sol[i]);
}
    
  

int main()
{
  citire();
  solve();  
  fclose(fout);
  return 0;
}
