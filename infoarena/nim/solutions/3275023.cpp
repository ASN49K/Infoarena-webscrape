#include<bits/stdc++.h>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t, n, x;

int main(){
    in>>t;
    for(int query=1; query<=t; query++){
        in>>n;
        int sum=0;
        for(int i=1; i<=n; i++){
            in>>x;
            sum^=x;
        }
        if(sum==0){
            out<<"NU\n";
        }else{
            out<<"DA\n";
        }
    }
    return 0;
}