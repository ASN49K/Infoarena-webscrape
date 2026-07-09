#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");



int n, m, a[1030], b[1030], lm, ord[260];

vector<int> v[1030];



int bs(int x, int r, int l){
int mij=(l+r)/2;

if(v[mij].size()<1){
    if(mij>0){
        for(int i=0; i<v[mij-1].size(); i++){
            v[mij].push_back(v[mij-1][i]);
        }
    }
    v[mij].push_back(x);
    lm=max(lm, mij+1);
    return mij;
}



int o1=0, o0=0, j=0;
for(int i=0; i<m; i++){
        if(j>=v[mij].size() ){break;}
    if(b[i]==v[mij][j]){o0=o1; o1=i+1; j++;}
}




if( ord[x]>o0 ){
    if(ord[x]<o1){
        return mij;
    }
    else{
        return bs(x, mij+1, l);
    }
}
else{
    return bs(x, r, mij);
}


}







int main(){

fin>>n>>m;


for(int i=0; i<n; i++){
    fin>>a[i];
}

for(int i=0; i<m; i++){
    fin>>b[i];
    ord[b[i] ]=i+1;
}




for(int i=0; i<n; i++){

if(ord[a[i] ]<1){continue;}

int p=bs(a[i], 0, lm);
cout<<p<<"\n";

if(p>=0){
v[p][v[p].size()-1 ]=a[i];
}
cout<<" "<<v[p][v[p].size()-1 ]<<"a\n";


}

fout<<lm<<"\n";
for(int i=0; i<v[lm-1].size(); i++){
    fout<<v[lm-1][i]<<" ";
}

return 0;
}
