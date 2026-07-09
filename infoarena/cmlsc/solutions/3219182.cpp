#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int M[1025][1025],m,n,i,j,k=0,x=0,a[100001],b[100001],v[100001];

int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++){
        fin>>a[i];
    }
    for(j=1;j<=n;j++){
        fin>>b[j];
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(a[i]==b[j]){
                M[i][j]=M[i-1][j-1]+1;
            }else{
                M[i][j]=max(M[i-1][j],M[i][j-1]);
            }
        }
    } 
    fout<<M[m][n]<<endl;

    
    while(i>0 && j>0){
        if(a[i]==b[j]){
            v[k]=a[i];
            k++;
            i--;j--;
    }
        else if(M[i-1][j]<M[i][j-1]){
            j--;
        }
        else{i--;}
    }
    for(i=k-1;i>=1;i--){
       fout<<v[i]<<' ';
    }
    
    
    return 0;
} 
