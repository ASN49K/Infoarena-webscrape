#include <iostream>
#include<fstream>
using namespace std;
int mat[1025][1025];
int sir1[1025];
int sir2[1025];
int ender[1025];
int main(){
    ifstream cin("sclm.in");
    ofstream cout("sclm.out");
int helper=0,nr1,nr2;
cin>>nr1>>nr2;
for(int i=1;i<=nr1;i++){
    cin>>sir1[i];
}
for(int j=1;j<=nr2;j++){
    cin>>sir2[j];
}
mat[0][0]=0;
for(int i=1;i<=nr1;++i){
  for(int j=1;j<=nr2;++j){
    if(sir1[i]==sir2[j]){
      mat[i][j]=mat[i-1][j-1]+1;
      }
    else{
      mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    }
  }
}
int i,j;
for ( i=nr1, j=nr2;i;){
        if (sir1[i]==sir2[j]){
            ender[++helper]=sir1[i];
            --i;
            --j;
        }
        else{
            if (mat[i-1][j]<mat[i][j-1]){
            --j;
            }
        else{
            --i;
        }
        }
}
    cout<<helper<<'\n';
    for (i=helper;i;--i){
       cout<<ender[i]<<" ";
    }

    return 0;
}
