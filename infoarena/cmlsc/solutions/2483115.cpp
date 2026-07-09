#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");



short int m, n, i, t;
unsigned char x[1025], y[1025], c[1025][1025]; 
vector<vector<string> > s;

int lcs(){
    int d;
     for(i=1; i<=m;i++){
         for(int j=1; j<=n; j++){
             if(x[i]==y[j]){c[i][j]=1+c[i-1][j-1];d=x[i]; s[i][j]=s[i-1][j-1]+" "+to_string(d);}
             else{if(c[i-1][j]>=c[i][j-1]){c[i][j]=c[i-1][j]; s[i][j]=s[i-1][j];}
                  else{c[i][j]=c[i][j-1];s[i][j]=s[i][j-1]; }    }

         }


     }

    
    return c[m][n];
}



int main(){




fin>>m>>n;
s.resize(m+1);
for(int i=0; i<=m; i++){s[i].resize(n+1);}
for(i=1;i<=m;i++){ fin>>t;x[i]=t; c[i][0]=0; s[i][0]="";}

for(i=1;i<=n;i++){ fin>>t;y[i]=t;  c[0][i]=0; s[0][i]="";}


fout<<lcs()<<endl;
s[m][n].erase(0, 1);
s[m][n].erase(s[m][n].length(), 1);
fout<<s[m][n];



    return 0;
}