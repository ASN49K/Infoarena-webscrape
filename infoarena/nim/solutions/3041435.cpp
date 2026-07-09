#include<bits/stdc++.h>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t, n, s, x;

int main()
{
    in>>t;
    for(int i=1; i<=t; i++){
        in>>n;
        s=0;
        for(int j=1; j<=n; j++){
            in>>x;
            s=s^x;
        }
        if(s==0){
            out<<"NU\n";
        }else{
            out<<"DA\n";
        }
    }
    return 0;
}