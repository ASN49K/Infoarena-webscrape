#include <bits/stdc++.h>
using namespace std;
int euclid(int a, int b){
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<euclid(a,b);
    }
    return 0;
}
