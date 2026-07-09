#include<iostream>
#include<fstream>
using namespace std;
#define MAX 1024
int m,n,A[MAX],B[MAX],C[MAX][MAX],D[MAX];

void citire(const char *path)
{
	ifstream f(path);
	f>>m>>n;
	for(int i=1;i<=m;i++)
		  f>>A[i];
	for(int i=1;i<=n;i++)
		f>>B[i];

	f.close();

}
void afis()
{
	ofstream f("cmlsc.out");
    int nr=0;
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
          if(A[i]==B[j])
             C[i][j]=1+C[i-1][j-1];
          else
            C[i][j]=max(C[i-1][j],C[i][j-1]);
   for(i=m,j=n;i;)
           if(A[i]==B[j])
           {D[++nr]=A[i];--i;--j;}
           else if(C[i-1][j]<C[i][j-1])
               j--;
           else
               i--;
   f<<nr<<endl;
   for(int i=nr;i>=1;i--)
     f<<D[i]<<' ';



	f.close();
}
int main()
{
	citire("cmlsc.in");
	afis();
	return 0;
}
