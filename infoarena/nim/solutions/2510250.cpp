#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int T,n;

int main(){
    int i,x,s;
    f >> T;
    while(T--){
        s = 0;
        f >> n;
        for(i = 1 ; i <= n ; i++){
            f >> x;
            s ^= x;
        }

        if(s == 0)
            g << "NU\n";
        else
            g << "DA\n";
    }

    return 0;
}
