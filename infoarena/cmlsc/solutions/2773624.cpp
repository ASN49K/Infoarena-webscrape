#include <bits/stdc++.h>
using namespace std;
string prob="cmlsc";
ifstream in(prob+".in");
ofstream out(prob+".out");
vector<int> LCS(vector<int> &a,vector<int> &b,int i,int j){
    vector<int> res(0);
    if(i==0||j==0)return res;
    if(a[i]==b[j]){
            vector<int> r=LCS(a,b,i-1,j-1);
            r.push_back(a[i]);
            return r;
    }
    vector<int> aa=LCS(a,b,i-1,j);
    vector<int> bb=LCS(a,b,i,j-1);
    if(aa.size()>=bb.size()){
        return aa;
    }
    else{
        return bb;
    }
}
int main(){
    vector<int> a(1);
    vector<int> b(1);
    vector<int> res;
    int n,m;
    in>>n>>m;
    int nr;
    for(int i=0;i<n;i++){
        in>>nr;
        a.push_back(nr);
    }
    for(int i=0;i<m;i++){
        in>>nr;
        b.push_back(nr);
    }
    res=LCS(a,b,a.size()-1,b.size()-1);
    out<<res.size()<<'\n';
    for(auto i:res)out<<i<<' ';
}
