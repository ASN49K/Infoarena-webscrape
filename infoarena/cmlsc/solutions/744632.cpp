#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,A[1025],B[1025],C[1025][1025];

int cmlsc(){
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(A[i]==B[j])C[i][j]=1+C[i-1][j-1]; else
        C[i][j]=max(C[i-1][j],C[i][j-1]);
}

void tipar(int i,int j){
    if(C[i][j]>0){
    if(A[i]==B[j])tipar(i-1,j-1); else
        if(C[i-1][j]>C[i][j-1])tipar(i-1,j);else tipar(i,j-1);
    if(A[i]==B[j])printf("%d ",A[i]);
    }
}

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        for(int i=0;i<m;i++)scanf("%d",&B[i]);
    cmlsc();
    printf("%d\n",C[n-1][m-1]);
    tipar(n-1,m-1);
}
