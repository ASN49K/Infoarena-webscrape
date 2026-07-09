#include <bits/stdc++.h>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int euclid(int a, int b) {
    int r=0;
    while(a%b!=0) {
        r = a%b;
        a = b;
        b=r;
    }
    return b;
}
int euclid_recursive(int a, int b) {
    if(a%b==0)
        return b;
    return euclid_recursive(b,a%b);
}
int t,m,n, ans;
int main () {
    fin>>t;
    for(int i=1;i<=t;i++) {
        fin>>m>>n;
        fout<<euclid_recursive(m,n)<<'\n';
    }
    return 0;
}
