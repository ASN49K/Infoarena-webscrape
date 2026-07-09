#include<fstream>
using namespace std ;
int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    long long int ar,br,l=0;
    in>>ar>>br;
    int a[ar],b[br],v[1024];
    int dp[ar][br]={};
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
                dp[i][j]=1+dp[i-1][j-1];
            }
        }
    }
    while(ar>1 && br>1){
        if(dp[ar][br]==dp[ar-1][br]){
            ar--;
        }else{
            if(dp[ar][br]==dp[ar][br-1]){
                br--;
            }else{
                if(dp[ar][br]=1+dp[ar-1][br-1]){
                    l++;
                    v[l]=a[ar];
                    ar--;
                    br--;
                }
            }
        }
    }
    out<<l<<"\n";
    for(int i=l;i>=1;i--){
        out<<v[i]<<" ";
    }
}
