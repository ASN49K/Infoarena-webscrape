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
                s.push_back(x[i]);
             }else{
                a[i][j]= max(a[i-1][j],a[i][j-1]);
            }
            if(a[i][j]>maxi){
                maxi = a[i][j];
            }
        }
    }
    fout<<maxi<<'\n';
    for(int i = 0 ; i<maxi;i++){
        fout<<s[i]<<" ";
    }
}
