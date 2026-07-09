#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");




int main(){


int n, x;
fin>>n>>x;
vector<int> a(n);
vector<int> b(x);
vector<int> c;

for(int i=0;i<a.size();i++){
    fin>>a[i];
}    

for(int j=0;j<b.size();j++){
    fin>>b[j];
} 

for(int k=0;k<a.size();k++){
    for(int l=0;l<b.size();l++){
        if(a[k]==b[l]){
            c.push_back(a[k]);
        }
    }
}
fout<<c.size()<<"\n";
for(int u=0;u<c.size();u++){
    fout<<c[u];
}
    
}