#include<bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");
int maxi(int a, int b)
{
    return (a > b)? a : b;
}
int main(){
int n,m;fin>>n>>m;int A[n],B[m];
for(int a=0;a<n;a++)fin>>A[a];
for(int b=0;b<m;b++)fin>>B[b];

int L[m+1][n+1];
for(int c=0;c<=n;c++){
    for(int d=0;d<=m;d++){
        if(c==0 || d==0)L[d][c]=0;
        else if(A[c-1]==B[d-1])L[d][c]=1+L[d-1][c-1];
        else L[d][c]=maxi(L[d][c-1],L[d-1][c]);

    }
}
int index=L[m][n];int e=L[m][n];
int Res[index];
while(m>0 && n>0){
    if(A[n-1]==B[m-1]){
        Res[index-1]=A[n-1];
        n--;m--;index--;
    }
    else{
        if(L[m-1][n]>L[m][n-1])m--;
        else n--;
    }
}

fout<<e<<endl;
for(int u=0;u<e;u++)fout<<Res[u]<<' ';






return 0;}
