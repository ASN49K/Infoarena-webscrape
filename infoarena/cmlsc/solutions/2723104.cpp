//#include <iostream>
#include <fstream>

using namespace std;
int n,m,v[1050],f[1050],d[1050][1050],rasp[1050],cnt=0;
int main(){
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int j=1;j<=m;j++){
        cin>>f[j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i]==f[j]){
                d[i][j]=d[i-1][j-1]+1;
            }
            d[i][j]=max(d[i][j],max(d[i-1][j],d[i][j-1]));
        }
    }
    cout<<d[n][m]<<"\n";
    int s1=n,s2=m;
    while(d[s1][s2]!=0){
        if(v[s1]==f[s2]){
            rasp[++cnt]=s1;
            s1--;
            s2--;
        }
        else{
            if(d[s1-1][s2]>d[s1][s2-1]){
                s1--;
            }
            else{
                s2--;
            }
        }
    }
    for(int i=cnt;i>=1;i--){
        cout<<v[rasp[i]]<<" ";
    }

    return 0;
}
