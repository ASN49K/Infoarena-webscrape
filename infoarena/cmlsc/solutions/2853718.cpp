#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, i, le;
vector <int> a, b;
set <int> c;

int s(int x){
    for(int j = le; j<m; j++) if(b[j] == x) {le = j; return j;}
    return -1;
}

int main(){
    in>>n>>m;
    for(i = 0; i<n; i++){
        in>>le; a.emplace_back(le);
    }
    for(i = 0; i<m; i++){in>>le; b.emplace_back(le);}
    le = 0;
    for(i = 0; i<n; i++){
        if(le >= m-1) break;
        if(s(a[i]) != -1){
            c.insert(a[i]);
        }
    }
    out<<c.size()<<"\n";
    for(auto j:c) out<<j<<" ";
}