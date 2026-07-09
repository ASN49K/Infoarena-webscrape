#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
   int N,M,index=0;
   int A[1024]{},B[1024]{},C[1024][1024]{},sol[1024]{};
   fin>>M>>N;
   for(int i=1;i<=M;i++){
    fin>>A[i];
   }
    for(int i=1;i<=N;i++){
    fin>>B[i];
   }
   for(int i=1;i<=M;i++){
    for(int j=1;j<=N;j++){
        if(A[i]==B[j]){
            C[i][j]=C[i-1][j-1]+1;
        }else C[i][j]=max(C[i-1][j],C[i][j-1]);
    }
   }
   int i=M,j=N;
   while(i>0&&j>0){
if(A[i]==B[j]){
    sol[++index]=A[i];
}else if(C[i-1][j]<C[i][j-1]){
j--;
}else i--;
   }
   fout<<index;
   for(int e=1;i<=index;e++){
    fout<<sol[e];
   }
   fin.close();
   fout.close();
    return 0;
}
