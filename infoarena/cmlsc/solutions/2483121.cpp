#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");



short int m, n, i, t, k;
unsigned char x[1025], y[1025], c[1025][1025]; 
unsigned char sol[1025];

int lcs(){
     for(i=1; i<=m;i++){
         for(int j=1; j<=n; j++){
             if(x[i]==y[j]){c[i][j]=1+c[i-1][j-1];}
             else{if(c[i-1][j]>=c[i][j-1]){c[i][j]=c[i-1][j];}
                  else{c[i][j]=c[i][j-1];}    }

         }


     }
    int j=n; i=m;
    while(i && j){
          if(x[i]==y[j]){
              sol[++k]=x[i];
              i--; j--;
          }
    else{if(c[i-1][j]>=c[i][j-1]){i--;}else{j--;}}


    }



    
    return c[m][n];
}



int main(){




fin>>m>>n;

for(i=1;i<=m;i++){ fin>>t;x[i]=t; c[i][0]=0;}

for(i=1;i<=n;i++){ fin>>t;y[i]=t;  c[0][i]=0;}


fout<<lcs()<<endl;
for(int i=m; i>=1; i--){
if(sol[i]>0){
fout<<to_string(sol[i])<<' ';}
}


    return 0;
}