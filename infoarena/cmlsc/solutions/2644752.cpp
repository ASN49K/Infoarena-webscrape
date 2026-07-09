#include<fstream>
int a[1025],b[1025],v[1025];
int dp[1025][1025]={};
using namespace std ;
int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    long long int ar,br,l=0;
    in>>ar>>br;
    for(int i=1;i<=ar;i++){
        in>>a[i];
    }
    for(int i=1;i<=br;i++){
        in>>b[i];
    }
    for(int i=1;i<=ar;i++){
        for(int j=1;j<=br;j++){
            if(a[i]!=b[j]){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }else{
                l++;
                v[l]=a[i];
                dp[i][j]=1+dp[i-1][j-1];
            }
        }
    }
    out<<l<<"\n";
    for(int i=1;i<=l;i++){
        out<<v[i]<<" ";
    }
}
