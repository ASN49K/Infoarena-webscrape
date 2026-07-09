#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    int n,a,b,i,c;
    fin>>n;
    for(i = 1; i <= n; i++){
        fin>>a>>b;
        while(b != 0){
            c = a;
            a = b;
            b = c%b;
        }
        fout<<a<<endl;
    }
    return 0;
}
