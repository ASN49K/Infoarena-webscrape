#include <fstream>

using namespace std;
#define max(a,b) ((a>b)?a:b)

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int i,j,N,M,A[1024],B[1024],Z[1024][1024],C[1024],nr=0;

int main()
{
    in>>N>>M;
    for(i=1;i<N;i++)in>>A[i];
    for(i=1;i<M;i++)in>>B[i];
    for(i=1;i<N;i++)
        for(j=1;j<M;j++)
           {
               if(A[i]==B[j]){

                Z[i][j]=1+Z[i-1][j-1];

               }else{Z[i][j]=max(Z[i-1][j],Z[i][j-1]);}
            }
      i=N;j=M;
     while(i!=0&&j!=0)
     {
         if(A[i]==B[j])
         {
             C[++nr]=A[i];
             i--;j--;
         }else if(Z[i-1][j]<Z[i][j-1]){j--;}else{i--;}


     }
     out<<nr;
     for(i=nr;i>=1;i--)
        out<<C[i];

    return 0;
}
