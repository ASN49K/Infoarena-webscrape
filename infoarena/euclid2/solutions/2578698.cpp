#include<bits/stdc++.h>
#include<fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    in>>t;
    while(t--){
        int x, y;
        in>>x>>y;
        out<<__gcd(x,y)<<'\n';
    }

    return 0;
}
