#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }
}