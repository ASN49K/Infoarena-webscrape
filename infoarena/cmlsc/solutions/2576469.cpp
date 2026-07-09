#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");




unsigned short int  n, m, a[1030], b[1030], c[1030][1030];






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
            }
            else{
                c[i][j]=max(c[i-1][j], c[i][j-1]);
            }

    }
}

fout<<c[n][m]<<"\n";


    int l=0;
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        if(c[i][j]==(l+1) ){
            fout<<a[i-1]<<" ";
            l=c[i][j];
            break;
        }
    }
}


return 0;
}
