#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, i, le;
vector <int> v;
vector <pair <int, int>> a;
pair <int, int> p;

int fnd(int x){
    for(int j = le; j<v.size(); j++) if(v[j] == x) return j;
    return 0;
}

int main(){
    in>>n>>m;
    int b;
    for(i = 0; i<n; i++){
        in>>b;
        v.emplace_back(b);
    }
    for(i = 0; i<m; i++){
        in>>b;
        if(fnd(b)){
            p.first = b;
            p.second = fnd(b);
            a.emplace_back(p);
            le = p.second;
        }
    }
    out<<a.size()<<"\n";
    for(auto i:a) out<<i.first<<" ";
}