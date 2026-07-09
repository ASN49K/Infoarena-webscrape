#include <bits/stdc++.h>
using namespace std;
int N,M,v1[2000][2],v2[2000],i,vint[2000][2000],k,j,P,ok,maxi;
int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++){
        scanf("%d",&v1[i][0]);
    }
    for(i=0;i<M;i++){
        scanf("%d",&v2[i]);
    }

    for(i=0;i<N;i++){
        for(j=0;j<M&&v1[i][0]!=v2[j];j++);
        if(j<M)
            v1[i][1]=j;
        else v1[i][1]=-1;
    }
    for(i=0;i<N;i++){
        ok=0;
        if(v1[i][1]!=-1){
            for(j=0;j<P;j++){
                if(vint[j][1]<v1[i][1]){
                    vint[j][2]++;
                    vint[j][vint[j][2]+2]=vint[j][0];
                    vint[j][0]=v1[i][0];
                    vint[j][1]=v1[i][1];
                    ok=1;
                }
            }
            if(!ok){
                vint[P][0]=v1[i][0];
                vint[P][1]=v1[i][1];
                vint[P][2]=0;
                P++;
            }
        }
    }
    for(i=0;i<P;i++){
        maxi=max(maxi,vint[i][2]+1);
    }
    ok=1;
    for(i=0;i<P&&ok;i++){
        if(vint[i][2]+1==maxi){
            printf("%d\n",maxi);
            for(j=3;j<=maxi+1;j++){
                printf("%d ",vint[i][j]);
            }
            printf("%d",vint[i][0]);
            ok=0;
        }
    }
    return 0;
}
