#include <fstream>
#define MAX 1030
#define VMAX 260
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int n,m,A[MAX],B[MAX],Dp[MAX],maxim;
void Citire();
void Rezolv();
void Afisare();
int main(){
    Citire();
    Rezolv();
    Afisare();
    return 0;
}
void Citire(){
    int i,j,k=0,x;
    bool Fr[VMAX]={};
    fin>>n>>m;
    for(i=0;i<n;++i){
        fin>>A[i];
        Fr[A[i]]=1;
    }
    k=m;
    m=0;
    for(i=0;i<k;++i){
        fin>>x;
        if(Fr[x])B[m++]=x;
    }
}
void Rezolv(){
    int i,j,x,poz,maxi,maxipoz;
    for(i=maxim;i<n;++i){
        x=poz=-1,maxipoz=-1;
        maxi=maxim;
        for(j=maxi;j<m;++j){
            if(Dp[j]>maxi){
                maxi=Dp[j];
            }
            if(A[i]==B[j]&&maxi>maxipoz){
                poz=j;
                maxipoz=maxi;
            }
        }
        if(poz!=-1){
            Dp[poz]=maxipoz+1;
            if(Dp[poz]>maxim)
                maxim=Dp[poz];
        }
    }
}
void Afisare(){
    int i,x=1;
    fout<<maxim<<'\n';
    for(i=0;i<m;++i){
        if(x<=Dp[i]){
            fout<<B[i]<<' ';
            ++x;
        }
    }
}
