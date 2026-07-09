#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int ma(int a,int b)
{int p;
 if(a>=b) p=a;
 else p=b;
 return p;
}
int A[1024],B[1024],i,j,N,M,D[1024][1024],k,sir[1024];
int main()
{f>>M>>N;
 for(i=1;i<=M;i++) f>>A[i];
 for(i=1;i<=N;i++) f>>B[i];

 for(i=1;i<=M;i++)
    for(j=1;j<=N;j++)
      if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
      else D[i][j]=ma(D[i-1][j],D[i][j-1]);

for(i=M,j=N;i;)
   if(A[i]==B[j])
     sir[++k]=A[i],--i,--j;
   else if (D[i-1][j]<D[i][j-1]) --j;
   else --i;
g<<k<<'\n';
for(i=k;i>=1;i--) g<<sir[i]<<' ';
g<<'\n';

/*for(i=1;i<=M;i++)
 {for(j=1;j<=N;j++)
  g<<D[i][j]<<' ';
  g<<'\n';*/  return 0;
}
