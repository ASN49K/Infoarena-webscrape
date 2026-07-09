#include<fstream>
using namespace std;
#define NMAX 1025
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int mat[NMAX][NMAX],v[NMAX],A[NMAX],B[NMAX],n,m,nr;
void citire()
 {f>>n>>m;
  for(int i=1;i<=n;++i) f>>A[i];
  for(int j=1;j<=m;++j) f>>B[j];
  f.close();
 }
int max(int a,int b)
 {if(a>b) return a;
  return b;
}
void formare()
 {for(int i=0;i<=n;++i)
	 for(int j=0;j<=m;++j) mat[i][j]=0;
  for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j) if(A[i]==B[j]) mat[i][j]=mat[i-1][j-1]+1;
						   else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
 }
 void drum()
 {int i = n, j = m;
        do{if (A[i] == B[j])
            v[++nr] = A[i], --i, --j;
        else if (mat[i-1][j] < mat[i][j-1])
            --j;
        else
            --i;
		}while(i);
 }
 int main()
  {citire();
   formare();
   drum();
   g<<mat[n][m]<<"\n";
   for(int i=nr;i>=1;i--) g<<v[i]<<" ";
   g<<"\n";
   g.close(); return 0;
   }
  
 