#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main(){
    int m, n, i, j, a[1026], b[1026], c[1026][1026];
    in>>m>>n;
    vector<int> x;
    for(i=1; i<=m; i++){
        in>>a[i];
        c[0][i]=0;
        c[1][i]=0;
    }
    for(i=1; i<=n; i++){
        in>>b[i];
        c[i][0]=0;
        c[i][1]=0;
    }
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(a[i]!=b[j]){
                c[i][j]=max(c[i][j-1], c[i-1][j]);
            }else{
                c[i][j]=c[i-1][j-1]+1;
            }
        }
    }
    out<<c[m][n];
    i=m;
    j=n;
    while(i!=0){
        if(c[i][j]>max(c[i-1][j], c[i][j-1])){
            x.push_back(a[i]);
            i--;
            j--;
        }else{
            if(c[i-1][j]>c[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    out<<"\n";
    for(i=x.size()-1; i>=0; i--){
        out<<x[i]<<" ";
    }
    return 0;
}
