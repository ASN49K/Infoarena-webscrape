#include <bits/stdc++.h>
using namespace std;

int eucl(int a,int b){
    if(b%a==0){
        return a;
    }
    int x=b-((b/a)*a),y=a;
    return eucl(min(x,y),max(x,y));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--){
        int a,b;cin>>a>>b;
        cout<<eucl(min(a,b),max(a,b))<<'\n';
    }
}