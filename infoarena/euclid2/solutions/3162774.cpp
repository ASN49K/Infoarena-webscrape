#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, x, y;

int euclid(int a, int b){
    return (b?euclid(b, a%b):a);
}

int main(){
    fin>>n;
    for(int i=1; i<=n; i++){
        fin>>x>>y;
        fout<<euclid(x, y)<<"\n";
    }
}
