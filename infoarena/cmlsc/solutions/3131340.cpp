#include<fstream>
#include<iostream>
#include<vector>


using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1050][1050],n,m,x[1050],y[1050], maxi = -1;

vector<int> s;

int main(){
    fin>>n>>m;
    for(int i = 1 ; i<=n;i++){
        fin>>x[i];
    }
    for(int i = 1 ; i<=n;i++){
        fin>>y[i];
    }
    for(int i = 1; i<= n ;i++){
        for(int j =1 ; j<= m ;j++){
            if(x[i]==y[j]){
                a[i][j]=a[i-1][j-1] + 1;
             }else{
                a[i][j]= max(a[i-1][j],a[i][j-1]);
            }
            if(a[i][j]>maxi){
                maxi = a[i][j];
            }
        }
    }
    fout<<maxi<<'\n';
   int drum[1025];
    int length = 0;
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(a[i] == b[j]) {
            drum[++length] = a[i];
            i--;
            j--;
        } else if(dp[i-1][j] < dp[i][j-1]) {
            j--;
        } else {
            i--;
        }
    }
    for(int i = length; i >= 1; i--) {
        fout<<drum[i]<<" ";
    }
}
