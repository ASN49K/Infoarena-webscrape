#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");




unsigned short int  n, m, a[1030], b[1030], c[1030][1030], s[1030];






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
                    if(c[i-1][j]>c[i][j-1]){
                        c[i][j]=c[i-1][j];

                    }
                    else{
                        c[i][j]=c[i][j-1];

                    }

            }

    }


}

int k=c[n][m]-1;
int i=n,  j=m;
while( i && j && (k+1) ){
    if(a[i-1]==b[j-1]){
    s[k]=a[i-1]; i--; j--; k--;
    }
    else{
        if(c[i-1][j]>=c[i][j-1]){i--;}else{j--;}
    }

}



fout<<c[n][m]<<"\n";



for(int i=0; i<c[n][m]; i++){
    fout<<s[i]<<" ";
}


return 0;
}
