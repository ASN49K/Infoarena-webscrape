#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");




unsigned short int  n, m, a[1030], b[1030], c[1030][1030];
string s[1030][1030];





int main(){

fin>>n>>m;


for(int i=0; i<n; i++){
    fin>>a[i];
}

for(int i=0; i<m; i++){
    fin>>b[i];
}



for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){

            if(a[i-1]==b[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                s[i][j]=s[i-1][j-1]+to_string(a[i-1])+" ";
            }
            else{
                    if(c[i-1][j]>c[i][j-1]){
                        c[i][j]=c[i-1][j];
                        s[i][j]=s[i-1][j];
                    }
                    else{
                        c[i][j]=c[i][j-1];
                        s[i][j]=s[i][j-1];
                    }

            }

    }
}

fout<<c[n][m]<<"\n"<<s[n][m];




return 0;
}
