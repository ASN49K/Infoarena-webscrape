#include <bits/stdc++.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
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
    int t,a,b;
    fin >> t;
    while(t--){
        fin>>a>>b;
        fout<<euclid(a,b)<< '\n';
    }
    return 0;
}
