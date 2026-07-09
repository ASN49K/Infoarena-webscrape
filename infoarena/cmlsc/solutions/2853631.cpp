#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, i;
vector <int> v, a;

int main(){
    in>>n>>m;
    int *b = new int;
    for(i = 0; i<n; i++){
        in>>*b;
        v.emplace_back(*b);
    }
    for(i = 0; i<m; i++){
        in>>*b;
        if(find(v.begin(), v.end(), *b) != v.end()) a.emplace_back(*b);
    }
    out<<a.size()<<"\n";
    for(auto i:a) out<<i<<" ";
    delete b;
}