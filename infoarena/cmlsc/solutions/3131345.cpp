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
    for(int i = 1 ; i<=m;i++){
        fin>>y[i];
    }
    for(int i = 1; i<= n ;i++){
        for(int j =1 ; j<= m ;j++){
            if(x[i]==y[j]){
                a[i][j]=a[i-1][j-1] + 1;
             }else{
                a[i][j]= max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    fout<<a[n][m]<<'\n';
    int drum[1025];
    int length = 0;
    int i = n, j = m;
      while(i > 0 && j > 0) {
        if(x[i] == y[j]) {
            drum[++length] = x[i];
            i--;
            j--;
        } else if(a[i-1][j] < a[i][j-1]) {
            j--;
        } else {
            i--;
        }
    }
    for(int i = length; i >= 1; i--) {
        fout<<drum[i]<<" ";
    }
}
